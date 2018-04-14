#include "src/motlib.h"
#include "src/linelib.h"
#include "src/pixytracker.h"
#include "src/phoeniximu.h"

Motore motori[4];
int pins[4][3] = {  {15, 22},
                    {14, 20},
                    {12, 6},       //controlla i pin
                    {11, 9} };
Piattaforma robot;
LineSensor s(0x55);

PixyTracker pixy;                              //creazione oggetto PixyTracker

int angoli[4] = {45, 135, 225, 315};
void setup()  {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata");
    for(int i = 0 ; i < 4; i++) {
      motori[i].inizializza(pins[i][0], pins[i][1]);
    }
    robot.inizializza(motori, angoli);
    s.inizializza(angoli);

    pixy.inizializza();                        //inizializzo l'oggetto PixiTraker
    robot.setVel(100);
}

void loop() {

//  static bool stato_prec = 0;
//  pixy.elabora();
//  bool stato = pixy.getBallStatus();
//
//  if(stato_prec != stato && stato == 1) {      //controllo se ci sono variazioni nello stato della pixy
//    Serial.println("Visto palla");             //se lo stato è 1 la palla è stata trovata
//  }
//
//  if(stato_prec != stato && stato == 0) {     //se lo stato è 0 la palla è uscita dalla visuale della pixy
//    Serial.println("Perso palla");
//  }
//
//  stato_prec = stato;
 robot.move(90);
 robot.elabora();


}
