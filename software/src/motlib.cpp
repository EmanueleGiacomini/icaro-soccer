/*
  motlib.cpp
  All functions and objects relative to motor controll on Icaro soccer robot

  @author
  @version
*/

#include "motlib.h"

static double toRad(double  deg) {
  return (deg * 71 ) / 4068;
}

static double toDeg(int rad) {
  return ( rad * 4068 ) / 71;
}

Motore::Motore() {

}

void Motore::inizializza(int dira, int dirb, int pwm) {
  pinMode(dira, OUTPUT);
  pinMode(dirb, OUTPUT);
  pinMode(pwm, OUTPUT);
  _dira = dira;
  _dirb = dirb;
  _pwm = pwm;
}

void Motore::setVel(int vel) {
  if(vel >= 0) _dir = 1;
  else _dir = 0;

  _vel = constrain(abs(vel), 0, 255);
}

void Motore::elabora() {
  digitalWrite(_dira, _dir);
  digitalWrite(_dirb, !_dir);
  analogWrite(_pwm, _vel);
}

Piattaforma::Piattaforma() {}

void Piattaforma::inizializza(Motore motori[], int angoli[]) {
  _motori = motori;
  for(int i = 0 ; i < 4; i++) {
    _mot_sin[i] = sin(toRad((double)angoli[i]));
    _mot_cos[i] = cos(toRad((double)angoli[i]));
  }
}

void Piattaforma::move(double dir) {
  double dir_rad = toRad(dir);
  _dir_x = cos(dir_rad);
  _dir_y = sin(dir_rad);
}
void Piattaforma::setVel(int vel) {
  _vel = vel;
}
void Piattaforma::ruota(double rot) {
  _rot = rot;
}

void Piattaforma::elabora() {
  for(int i = 0; i < 4; i++) {
    double mot_vel = _mot_cos[i] * (_dir_y * _vel) - _mot_sin[i] * (_dir_x * _vel) + _rot;
    _motori[i].setVel(mot_vel);
    _motori[i].elabora();
  }
}
