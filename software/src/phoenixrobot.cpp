/**
 * @brief 
 * 
 * @file phoenixrobot.cpp
 * @author your name
 * @date 2018-04-11
 */

#include "phoenixrobot.h"

PhoenixRobot::PhoenixRobot() : _pixy_pid(&_input_pixy, &_output_pixy, &_setpoint_pixy, 2, 0, 0, DIRECT), _imu_pid(&_input_imu, &_output_imu, &_setpoint_imu, 2, 0, 0, DIRECT) {

}

void PhoenixRobot::inizializza(PixyTracker* pixy, PhoenixImu* imu, LineHandler* lh, Piattaforma* p)
{
    _pixy = pixy;
    _imu = imu;
    _lh = lh;
    _p = p;

  _pixy_pid.SetMode(AUTOMATIC);
  _pixy_pid.SetOutputLimits(-255, 255);
  _imu_pid.SetMode(AUTOMATIC);
  _imu_pid.SetOutputLimits(-255, 255);

}
void PhoenixRobot::elabora()
{
  _pixy->elabora();
  _imu->elabora();
  // TODO: Fix elabora di lh
  //_lh->elabora();
  
  
}
  bool PhoenixRobot::trackBall()
  {
    _setpoint_pixy=340/2;
    if(abs(_pixy->getBallX() - (_setpoint_pixy)) < 10)
    {
      return false;
    }
    _input_pixy = _pixy->getBallX();
    _pixy_pid.Compute();
    _p->ruota(_output_pixy);    
    return true;
  }
  bool PhoenixRobot::trackNorth()
  {
    bool esit;
    _setpoint_imu=90;
    if(abs(_imu->getHeading()-(_setpoint_imu)) < 10)
    {
      esit = 0;
    }
    _input_imu = _imu->getHeading();
    _imu_pid.Compute();
    _p->ruota(_output_imu);    
    _p->elabora();
    Serial.println(_output_imu);
    esit = 1;
    return esit;
  
   return 0;
  }
  bool PhoenixRobot::trackGoal()
    {
      _setpoint_pixy=340/2;
    if(abs(_pixy->getGoalX()-(_setpoint_pixy)) < 10)
    {
      return false;
    }
    _input_pixy = _pixy->getGoalX();
    _pixy_pid.Compute();
    _p->ruota(_output_pixy);    
    return true;
    }
    /*bool   PhoenixRobot::correggiLinea(int dir)//a*b a=vettore porta b=vettore palla
    {
      if(flag_linea==true)
      {
        dir=ls->correggi(dir);
        return _correzione=true;
      }
      return _correzione=false;
    }*/
    bool PhoenixRobot::alignBallGoal()//se allineato 0
    {

      double heading = _imu->getHeading();
      if(abs(90-heading)<10)
      {
        return false;
      } 
      if(abs(180 - heading) < 20) {
        // Sto guardando la porta alleata, devo andare a destra
        // o sinistra per uscire da questa condizione
        _p->move(180);
      }
      double xHeading= cos(heading);
      double yHeading= sin(heading);
      double xDirFinale=xHeading;
      double yDirFinale=yHeading-1; 
      int dirFinale=circConstraint(toDeg(atan2(yDirFinale,xDirFinale)), -180, 180);     
      _p->move(dirFinale);
      return true;
    }