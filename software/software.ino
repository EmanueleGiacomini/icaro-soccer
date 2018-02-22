
#include "src/motlib.h"

Motore motori[4];
int pins[4][3] = {  {7, 8, 6},
                    {9, 10, 11},
                    {2, 3, 4},
                    {5, 12, 13} };
Piattaforma robot;
int angoli[4] = {45, 135, 225, 315};
void setup()  {
    for(int i = 0 ; i < 4; i++) {
      motori[i].inizializza(pins[i][0], pins[i][1], pins[i][2]);
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
