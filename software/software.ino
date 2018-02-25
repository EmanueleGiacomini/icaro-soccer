
#include "src/motlib.h"

Motore motori[4];
int pins[4][3] = {  {15, 22},
                    {14, 20},
                    {12, 6},
                    {11, 9} };
Piattaforma robot;
int angoli[4] = {45, 135, 225, 315};
void setup()  {
    for(int i = 0 ; i < 4; i++) {
      motori[i].inizializza(pins[i][0], pins[i][1]);
    }
    robot.inizializza(motori, angoli);

}

void loop() {

  static int dir = 0;
  robot.move(dir++);
  robot.setVel(100);
  robot.ruota(0);
  robot.elabora();
  delay(100);

}
