#include <math.h>

class Motore{
  int _dirpin, _pwmpin;
  int _dir, _pwm;

public:
  Motore(){}

  void setVel(int  vel) //metodo
  {
    if(vel<0)
    {
      _dir=0;
    }
    else
    {
     _dir=1;
    }
    _pwm = abs(vel);
  }
  void elabora()
  {
    digitalWrite(_dirpin,_dir);
    analogWrite(_pwmpin,_pwm);
  }
  void inizializza(int dirpin, int pwmpin)
  {
    _dirpin=dirpin;
    _pwmpin=pwmpin;
    pinMode(_dirpin, OUTPUT);
    pinMode(_pwmpin,OUTPUT);
  }

};
class Piattaforma{
  int _dir, _rot, _vel;
  //(gradi*71)/4068
  double _sin[4], _cos[4], _vx, _vy;
  Motore *_mot;
public:
  Piattaforma(){ //costruttore

  }
  void inizializza(Motore mot[4], double mot_ang[4])
  {
    _mot = mot;
    for (int i=0; i<4; i++)
    {
      double mot_rad=(mot_ang[i]*71)/4068;
      _sin[i]=sin(mot_rad);
      _cos[i]=cos(mot_rad);
    }
  }
  void setDir(int dir )
  {
    _dir=dir
    double dir_rad=(dir*71)/4068;
    _vx=cos(dir_rad)*_vel;
    _vy=sin(dir_rad)*_vel;
  }
  void setRot(int rot )
  {
    _rot=rot
  }
  void setVel(int vel )
  {
    _vel=vel
  }
  void elabora()
 {
  int mot_vel[4];
  for(int i=0; i<4; i++)
  {
    mot_vel[i]=(_cos[i]*_vy)-(_sin[i]*_vx)+_rot;
    _mot[i]->setVel(mot_vel[i]);
    _mot[i]->elabora();
  }

 }
};

Motore pippo[4];
Piattaforma p;

void setup()
{
  //pippo.inizializza(12,13);
  p.inizializza(pippo);

}
void loop()
{
  //pippo.setVel(255);
  //pippo.elabora();
}
