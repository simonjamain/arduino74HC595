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
        delete [] _values;
    }

    void
    Arduino74HC595::setValue(int pinNumber, boolean value)
    {
      _values[pinNumber] = value;
      _writereg();
    }

    void
    Arduino74HC595::setValues(boolean* values)
    {
      memcpy(_values,values,_nbOutputs*sizeof(boolean));
      _writereg();
    }

    void
    Arduino74HC595::_writereg()// code from http://staticjolt.com/shift-registers-arduino-tutorial/
    {
      digitalWrite(_STCP_pin, LOW);
      for (int i = _nbOutputs-1; i>=0; i--)
      {
        digitalWrite(_SHCP_pin, LOW);
        digitalWrite(_DS_pin, _values[i] );
        digitalWrite(_SHCP_pin, HIGH);
      }
      digitalWrite(_STCP_pin, HIGH);
    }



