/**
author : Simon Jamain
author url : https://github.com/simonjamain
project url : 
description : This file present a class that allows
you to manipulate easyly an 74HC595 8 output shift register.
*/
#ifndef Arduino74HC595_h
#define Arduino74HC595_h

#include <Arduino.h>

class Arduino74HC595
{
  public:
    Arduino74HC595(int DS_pin, int STCP_pin, int SHCP_pin);
    
    ~Arduino74HC595();
    
    /**
    This function sets the value of a pin given its pin number, the states of the other pins
    are kept the same.
    The pinNumber goes from 0 to nbOutputs-1.
    */
    void setValue(int pinNumber, boolean value);
    
    /**
    This function sets all the pins to values stored in an array.
    The array must have the size _nbOutputs to ensure a correct execution.
    */
    void setValues(boolean* values);
    
    /**
    This function sets all the pins to values corresponding to the binary representation of A number.
    For example setValues(B10000001) will activate the first and last pin.
    */
    void setValues(uint8_t values);//TODO: implement this function
    
    //void setValues();
  private:
    int _DS_pin;
    int _STCP_pin;
    int _SHCP_pin;
    uint8_t _values;
    void _writereg();
};

#endif

