#include <MapFloat.h>
#include <stdio.h>
#include "EasyNextionLibrary.h"


EasyNex myNex(Serial);

#define LED_Pin  A5
#define RES 1023
#define AREF 5

float current;
float voltage;
float current1; 

const int REFRESH_TIME = 100;           // time to refresh the Nextion page every 100 ms
unsigned long refresh_timer = millis();  // timer for refreshing Nextion's page

void showvoltage(int temp);

void setup() 
{
  pinMode(LED_Pin, OUTPUT);
  myNex.begin(9600); 
  analogReference(EXTERNAL);
   //Serial.begin(9600);
}

void loop() 
{
  
      digitalWrite(LED_Pin, HIGH); 

     if((millis()-refresh_timer) > REFRESH_TIME){
      
      int data = analogRead(A1);

      //Serial.print(data);
      
      
      current1 = ( data * (5.000/1074.000));
      
      current =  mapFloat(current1, 0.000, 20.000, 90.000, 200.000);
     // Serial.print(current, 4);
      
      voltage = mapFloat(data, 1.0, 100.0, 40.0, 300.0);
     //Serial.println(voltage, 3);
      
      myNex.writeNum("z1.val", current);////////////////current gauge display;

      myNex.writeNum("x1.val", current);////////////////current digitial display

      myNex.writeNum("z0.val", data);////////////////voltage gauge display
      
      myNex.writeNum("x0.val", data);/////////////voltage display

       refresh_timer = millis();
     }
}
