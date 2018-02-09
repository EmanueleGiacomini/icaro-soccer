/*
  motlib.cpp
  All functions and objects relative to motor controll on Icaro soccer robot

  @author
  @version
*/

#include "motlib.h"
/*
  Motore
  Oggetto che controlla un motore
  per inizializzare un motore si usi il metodo inizializza nel seguente modo:
  Motore mot;
  mot.inizializza(bit_dira, bit_dirb, pin_pwm, sreg)

  bit_dira e bit_dirb sono i due bit dell'oggetto (ShiftRegister) sreg per il controllo di direzione
  pin_pwm e' il pin per il controllo di velocita
*/
Motore::Motore(){}
void Motore::inizializza(int bit_dira, int bit_dirb, int pin_pwm, ShiftRegister* sreg){
  _bit_dira=bit_dira;
  _bit_dirb=bit_dirb;
  _pin_pwm=pin_pwm;
  pinMode (pin_pwm, OUTPUT);
  _sreg=sreg;
  _dir=0;
  _pwm=0;
}
    // BLOCCO REGOLAZIONE
void Motore::regolaVelocita(int pwm){
  _pwm=abs(pwm);
  if(pwm<0){
    regolaDirezione(!_dir);
  }
}
void Motore::regolaDirezione(int dir){
  if (dir==1){
    _dir=1;
  }
  if (dir==0){
    _dir=0;
  }
}
// BLOCCO ELABORAZIONE
void Motore::elabora(){
  analogWrite(_pin_pwm, _pwm);
   if (_dir==1){
     _sreg->impostaBit(_bit_dira, 1);
     _sreg->impostaBit(_bit_dira, 0);
   }
   if (_dir==0){
     _sreg->impostaBit(_bit_dira, 1);
     _sreg->impostaBit(_bit_dira, 0);
   }
   _sreg->elabora();
}


 /*
  Motore* _post_sx, _post_dx, _ant_dx, _ant_sx;
  int _dir;
  int _rot;
*/
  BloccoMotori::BloccoMotori() {}
  //metodi
  void BloccoMotori::inizializza(Motore* post_sx, Motore* post_dx, Motore* ant_dx, Motore* ant_sx ){
    _post_dx = post_dx;
    _post_sx = post_sx;
    _ant_dx = ant_dx;
    _ant_sx = ant_sx;
  }

/*
radians = (degrees * 71) / 4068

degrees = (radians * 4068) / 71
*/

void BloccoMotori::muovi(int dir){
  dir= (dir * 71) / 4068;
  // double _dirx, _diry;

  _dirx= cos(dir);
  _diry= sin(dir);
}
  void BloccoMotori::ruota(int rot){
    _rot=rot;
  }
  void BloccoMotori::regolaVelocita(int pwm){
    _dirx= _dirx * pwm;
    _diry= _diry * pwm;
  }

  void BloccoMotori::elabora(){
    _post_dx->regolaVelocita(-sen_post_dx*_dirx + cos_post_dx*_diry  + _rot);
    _post_sx->regolaVelocita(-sen_post_sx*_dirx + cos_post_sx*_diry  + _rot);
    _ant_dx->regolaVelocita(-sen_ant_dx*_dirx + cos_ant_dx*_diry  + _rot);
    _ant_sx->regolaVelocita(-sen_ant_sx*_dirx + cos_ant_sx*_diry  + _rot);
    _post_dx->elabora();
    _post_sx->elabora();
    _ant_dx->elabora();
    _ant_dx->elabora();
  }

//v = -sin(t1)*vx + cos(t1)*vy  + rot
