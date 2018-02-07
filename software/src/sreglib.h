/*
  sreglib.h
  All functions and objects relative to shift register module
  onboard the Icaro-soccer robot.

  @author
  @version
*/

#ifndef sreglib_h
#define sreglib_h
#include <Arduino.h>

class ShiftRegister{
  int _pin_latch;
  int _pin_clock;
  int _pin_data;
  int _data_byte;
  public:

  //costruttore
  ShiftRegister();

  //metodi
  void inizializza(int pin_latch,int pin_clock,int pin_data);
  void impostaBit(int bit, int valore);
  void elabora();
};
#endif
