/*
  motlib.h
  All functions and objects relative to motor controll on Icaro soccer robot.

  @author
  @version
*/

#ifndef motlib_h
#define motlib_h
#include <Arduino.h>
#include <math.h>
#include "sreglib.h"

class Motore {
  int _bit_dira;
  int _bit_dirb;
  int _pin_pwm;
  int _dir;
  int _pwm;
  ShiftRegister *_sreg;
public:
  //costruttore
  Motore();
  //metodi
  //BLOCCO INIZIALIZZAZIONE
  void inizializza(int bit_dira, int bit_dirb, int pin_pwm, ShiftRegister* sreg);
  // BLOCCO REGOLAZIONE
  void regolaVelocita(int pwm);
  void regolaDirezione(int dir);
  // BLOCCO ELABORAZIONE
  void elabora();
};


  class BloccoMotori {
    Motore *_post_sx, *_post_dx, *_ant_dx, *_ant_sx;
    int _rot;
    double _dirx, _diry;
    // seno - coseno di:
    // 45 - 135 - 225 - 315
    double sen_post_sx = -0.70710678118;
    double cos_post_sx = -0.70710678118;
    double sen_post_dx = -0.70710678118;
    double cos_post_dx = 0.70710678118;
    double sen_ant_sx = 0.70710678118;
    double cos_ant_sx = -0.70710678118;
    double sen_ant_dx = 0.70710678118;
    double cos_ant_dx = 0.70710678118;
    public:
    BloccoMotori ();
    //metodi
    void inizializza(Motore* post_sx, Motore* post_dx, Motore* ant_dx, Motore* ant_sx );
    void muovi(int dir);
    void ruota(int vers);
    void regolaVelocita(int pwm);
    void elabora();
};
#endif
