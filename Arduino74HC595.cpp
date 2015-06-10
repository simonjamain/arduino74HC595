#include <Arduino.h>
#include "Arduino74HC595.h"

#define ARDUINO74HC595_NBPINS 8
/*
  int _nbOutputs;
  int _DS_pin;
  int _STCP_pin;
  int _SHCP_pin;
  boolean _values[8]{};
*/

    Arduino74HC595::Arduino74HC595(int DS_pin, int STCP_pin, int SHCP_pin)
    :_DS_pin(DS_pin),_STCP_pin(STCP_pin),_SHCP_pin(SHCP_pin),_nbOutputs(ARDUINO74HC595_NBPINS)
    {
      pinMode(_DS_pin,OUTPUT);
      pinMode(_STCP_pin,OUTPUT);
      pinMode(_SHCP_pin,OUTPUT);
      _writereg();
    }
    
    Arduino74HC595::~Arduino74HC595()
    {
    }

    void
    Arduino74HC595::setValue(int pinNumber, boolean value)
    {
      if(pinNumber)
      {
        _values |= (1 << pinNumber);
      }else
      {
        _values &= !(1 << pinNumber);
      }
      _writereg();
    }

    void
    Arduino74HC595::setValues(boolean* values)
    {
      _values = 0;
      for(int i = 0; i < ARDUINO74HC595_NBPINS; i++)
      {
        _values += (values[i] << i);
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

      shiftOut(_DS_pin, _SHCP_pin, MSBFIRST, _values); 
      
      digitalWrite(_STCP_pin, HIGH);
    }



