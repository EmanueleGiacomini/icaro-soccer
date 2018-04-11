#include "src/motlib.h"
#include "src/linelib.h"
#include "src/pixytracker.h"
#include "src/phoeniximu.h"

Motore motori[4];
int pins[4][3] = {  {15, 22},
                    {14, 20},
                    {12, 6},
                    {11, 9} };
Piattaforma robot;
LineSensor s(0x55);
int angoli[4] = {45, 135, 225, 315};
void setup()  {
    for(int i = 0 ; i < 4; i++) {
      motori[i].inizializza(pins[i][0], pins[i][1]);
    }
    robot.inizializza(motori, angoli);
    s.inizializza(angoli);

}

void loop() {
  robot.elabora();
  if(!robot.trackBall())

}
