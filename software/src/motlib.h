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
//#include "utilib.h"


class Motore {
  int _dir, _vel;
  int _pin_dir, _pwm;
public:
  Motore();
  void inizializza(int pin_dir, int pwm);
  void setVel(int vel);
  void elabora();
};



class Piattaforma {
Motore *_motori;
double _mot_sin[4];
double _mot_cos[4];
double _rot, _vel;
double _dir_x, _dir_y;
public:
  Piattaforma();
  void inizializza(Motore motori[], int angoli[]);
  void move(double dir);
  void setVel(int vel);
  void ruota(double rot);
  void elabora();
};




#endif
