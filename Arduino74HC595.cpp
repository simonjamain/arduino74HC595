#include <Arduino.h>
#include "Arduino74HC595.h"

/*
  int _DS_pin;
  int _STCP_pin;
  int _SHCP_pin;
  uint8_t _values;
*/

    Arduino74HC595::Arduino74HC595(int DS_pin, int STCP_pin, int SHCP_pin)
    :_DS_pin(DS_pin),_STCP_pin(STCP_pin),_SHCP_pin(SHCP_pin)
    {
      pinMode(_DS_pin,OUTPUT);
      pinMode(_STCP_pin,OUTPUT);
      pinMode(_SHCP_pin,OUTPUT);
      _writereg();
    }
    
    Arduino74HC595::~Arduino74HC595()
    {
    }

    // see : http://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit-in-c-c
    void
    Arduino74HC595::setValue(int pinNumber, boolean value)
    {
      int n = 7-pinNumber;
      _values ^= (-value ^ _values) & (1 << n);
      _writereg();
    }

    void
    Arduino74HC595::setValues(boolean* values)
    {
      _values = 0;
      for(int i = 0; i < 8; i++)
      {
        _values += (values[7-i] << i);
      }
      _writereg();
    }

    void
    Arduino74HC595::setValues(uint8_t values)
    {
      _values = values;
      _writereg();
    }

    void
    Arduino74HC595::_writereg()
    {

      digitalWrite(_STCP_pin, LOW);

      shiftOut(_DS_pin, _SHCP_pin, LSBFIRST, _values); 
      
      digitalWrite(_STCP_pin, HIGH);
    }



