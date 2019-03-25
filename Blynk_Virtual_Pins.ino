#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266_SSL.h>


char auth[] = "0013de97fc25472e800485a21a528297";

char ssid[] = "Home";
char pass[] = "42780212";

int place[2];   // Coordinates for Bot
int Start = 0;  // To start 

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V1) // X Coordinate  
{
  int pinValue = param.asInt();
  place[0] = pinValue;
}

BLYNK_WRITE(V2) // Y Coordinate 
{
  int pinValue = param.asInt();
  place[1] = pinValue;
}

BLYNK_WRITE(V3) // Start
{
  int pinValue = param.asInt();
  Start = pinValue;
}


void loop()
{
  Blynk.run();
  delay(100);
  if(Start == 1){                   // Print the coordinates
    for(int i = 0; i<2 ; ++i)
      Serial.print(place[i]);
    Serial.println(' ');
  }
}
