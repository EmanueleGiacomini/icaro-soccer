#include "src/motlib.h"
#include "src/linelib.h"
#include "src/pixytracker.h"
#include "src/phoeniximu.h"
#include "src/phoenixrobot.h"

#define BNO055_SAMPLERATE_DELAY_MS (100)

Motore motori[4];
int pins[4][3] = {  {15, 22},
                    {14, 20},
                    {5, 6},       
                    {4, 9} };
Piattaforma p;
LineSensor s(0x55);
PhoenixImu bussola;
LineHandler lh;
PhoenixRobot robot;

PixyTracker pixy;                              //creazione oggetto PixyTracker

int angoli[4] = {45, 315, 225, 135};
void setup()  {   
  Serial.begin(9600);
  Serial.println("Seriale inizializzata");
  for(int i = 0 ; i < 4; i++) {
    motori[i].inizializza(pins[i][0], pins[i][1]);
  }
  p.inizializza(motori, angoli);
  s.inizializza(angoli);
  bussola.inizializza();
  pixy.inizializza();                        //inizializzo l'oggetto PixiTraker
  robot.inizializza(&pixy, &bussola, &lh, &p);
}

void loop() {
  robot.elabora();
  if (pixy.getBallStatus()==true)
  {
    robot.trackBall();
      if(robot.alignBallGoal()==true)
      {
       robot.attack();
      }
  }
  else
  {
    robot.trackNorth();
    p.ruota(70);
  }




  delay(50);
}
