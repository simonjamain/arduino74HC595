#include <Arduino74HC595.h>

//Pin connected to ST_CP of 74HC595
#define  STCP_pin 12
//Pin connected to SH_CP of 74HC595
#define  SHCP_pin 13
////Pin connected to DS of 74HC595
#define  DS_pin 11

#define  numPins 8

Arduino74HC595* test;

void setup() {
  Serial.begin(9600);
  //Arduino74HC595(int DS_pin, int STCP_pin, int SHCP_pin);
  test = new Arduino74HC595(DS_pin, STCP_pin, SHCP_pin);
}

void loop() {
  
    for(int i = 0; i<numPins; i++)
    {
      test->setValue(i, HIGH);
      delay(100);
    }
    for(int i = 0; i<numPins; i++)
    {
      test->setValue(i, LOW);
      delay(100);
    }
    
    for(int i = numPins-1; i>=0; i--)
    {
      test->setValue(i, HIGH);
      delay(100);
    }
    for(int i = numPins-1; i>=0; i--)
    {
      test->setValue(i, LOW);
      delay(100);
    }
  
    
}
