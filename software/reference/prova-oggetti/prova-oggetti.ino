/*
  prova-oggetti.ino

  Esempio costruzione del software tramite la programmazione ad oggetti.
*/
#define AVANTI 1
#define INDIETRO 0
#define DESTRA 2
#define SINISTRA 3
#define NON_DEFINITO -1

// latch
// data
// clock
// motori_byte
class ShiftReg{
  int _pin_latch;
  int _pin_clock;
  int _pin_data;
  int _motori_byte;
  public:

  //costruttore
  ShiftReg(int pin_latch,int pin_clock,int pin_data ){
    _pin_latch=pin_latch;
    _pin_clock=pin_clock;
    _pin_data=pin_data;
    _motori_byte=0;
  }

  //metodi
  void impostaBit(int bit, int valore){
    if(valore==1){
      _motori_byte |= (1<<bit);
    }
    else{
      _motori_byte &= ~(1 << bit);
    }
  }

  void elabora(){
    digitalWrite (_pin_latch, LOW);
    shiftOut(_pin_data,_pin_clock, MSBFIRST, _motori_byte);
    digitalWrite (_pin_latch, HIGH);
  }

};

ShiftReg shiftreg(8,9,10);

class RobotMotori {
   int _pin_dir;
   int _pin_pwm;
   int _dir;
   int _pwm;

    public:
      int velocita;
      int direzione;

  //costruttore
    RobotMotori(int pin_dir, int pin_pwm){
        _pin_dir=pin_dir;
        _pin_pwm=pin_pwm;
        _dir=NON_DEFINITO;
        _pwm=NON_DEFINITO;
    }


  //metodi
    // BLOCCO REGOLAZIONE
    void regolaVelocita(int pwm){
        _pwm=pwm;
    }

    void regolaDirezione(int dir){
        if (dir==1){
        _dir=1;
        }

     if (dir==0){
        _dir=0;
        }
    }
    //##########################
    // BLOCCO ELABORAZIONE
    void elabora(){
        analogWrite(velocita, pwm);
        if (dir==1){
          shiftreg.impostaBit(_pin_dir, 1);
        }
        if (dir==0){
          shiftreg.impostaBit(_pin_dir, 0);
        }
        shiftreg.elabora();
    }
};



class Phoenix_Mot {
    RobotMotori* mot_1, mot_2, mot_3, mot_4;

    public:
    Phoenix_Mot(int pin_dir_1, int pin_pwm_1,int pin_dir_2, int pin_pwm_2,int pin_dir_3, int pin_pwm_3,int pin_dir_4, int pin_pwm_4) {
        mot_1 = new RobotMotori(pin_dir_1, pin_pwm_1);
        mot_2 = new RobotMotori(pin_dir_2, pin_pwm_2);
        mot_3 = new RobotMotori(pin_dir_3, pin_pwm_3);
        mot_4 = new RobotMotori(pin_dir_4, pin_pwm_4);

    }
    //metodi
    void muovi(int dir){
        switch (dir) {
          case AVANTI: {
              mot_1.regolaDirezione(AVANTI);
              mot_2.regoladirezione(AVANTI);
              mot_3.regoladirezione(INDIETRO);
              mot_4.regoladirezione(INDIETRO);
              break;
          }
          case INDIETRO: {
              mot_1.regolaDirezione(INDIETRO);
              mot_2.regoladirezione(INDIETRO);
              mot_3.regoladirezione(AVANTI);
              mot_4.regoladirezione(AVANTI);
              break;
          }
          case DESTRA: {
              mot_1.regolaDirezione(INDIETRO);
              mot_2.regoladirezione(AVANTI);
              mot_3.regoladirezione(AVANTI);
              mot_4.regoladirezione(INDIETRO);
              break;
          }
          case SINISTRA: {
              mot_1.regolaDirezione(AVANTI);
              mot_2.regoladirezione(INDIETRO);
              mot_3.regoladirezione(INDIETRO);
              mot_4.regoladirezione(AVANTI);
              break;
          }
        }
    }

    void ruota(int vers){
         switch (vers) {
         case DESTRA: {
              mot_1.regolaDirezione(INDIETRO);
              mot_2.regoladirezione(INDIETRO);
              mot_3.regoladirezione(INDIETRO);
              mot_4.regoladirezione(INDIETRO);
              break;
          }
          case SINISTRA: {
              mot_1.regolaDirezione(AVANTI);
              mot_2.regoladirezione(AVANTI);
              mot_3.regoladirezione(AVANTI);
              mot_4.regoladirezione(AVANTI);
              break;
          }
        }
    }

   void regolaVelocita(int pwm){
     mot_1.regolaVelocita(pwm);
     mot_2.regolaVelocita(pwm);
     mot_3.regolaVelocita(pwm);
     mot_4.regolaVelocita(pwm);
   }

    void elabora(){
      mot_1.elabora();
      mot_2.elabora();
      mot_3.elabora();
      mot_4.elabora();
    }
};
//##########################################

Phoenix_Mot robot(3,4,5,6,7,8,9,10);

int latch = 13;
int data = 12;
int clock = 11;

byte sreg_data = 0;

void setup() {
  robot.muovi(AVANTI);
  robot.regolaVelocita(255);
}

void loop() {

}
