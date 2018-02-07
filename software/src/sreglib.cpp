/*
  sreglib.cpp
  All functions and objects relative to shift register module
  onboard the Icaro-soccer robot.

  @author
  @version
*/

#include "sreglib.h"
/*
int _pin_latch;
int _pin_clock;
int _pin_data;
int _data_byte;
*/
//costruttore
ShiftRegister::ShiftRegister(){
}

//metodi
void ShiftRegister::inizializza(int pin_latch,int pin_clock,int pin_data) {
  _pin_latch=pin_latch;
  _pin_clock=pin_clock;
  _pin_data=pin_data;
  pinMode(pin_latch, OUTPUT);
  pinMode(pin_clock, OUTPUT);
  pinMode(pin_data, OUTPUT);
  _data_byte=0;
}
void ShiftRegister::impostaBit(int bit, int valore){
  if(valore==1){
    _data_byte |= (1<<bit);
  }
  else{
    _data_byte &= ~(1 << bit);
  }
}
void ShiftRegister::elabora(){
  digitalWrite (_pin_latch, LOW);
  shiftOut(_pin_data,_pin_clock, MSBFIRST, _data_byte);
  digitalWrite (_pin_latch, HIGH);
}
