#include <EEPROM.h>

/*

PPPPPPPPPPPPPPPPP   hhhhhhh                                                                      iiii
P::::::::::::::::P  h:::::h                                                                     i::::i
P::::::PPPPPP:::::P h:::::h                                                                      iiii
PP:::::P     P:::::Ph:::::h
 P::::P     P:::::P h::::h hhhhh          ooooooooooo       eeeeeeeeeeee    nnnn  nnnnnnnn    iiiiiii xxxxxxx      xxxxxxx
 P::::P     P:::::P h::::hh:::::hhh     oo:::::::::::oo   ee::::::::::::ee  n:::nn::::::::nn  i:::::i  x:::::x    x:::::x
 P::::PPPPPP:::::P  h::::::::::::::hh  o:::::::::::::::o e::::::eeeee:::::een::::::::::::::nn  i::::i   x:::::x  x:::::x
 P:::::::::::::PP   h:::::::hhh::::::h o:::::ooooo:::::oe::::::e     e:::::enn:::::::::::::::n i::::i    x:::::xx:::::x
 P::::PPPPPPPPP     h::::::h   h::::::ho::::o     o::::oe:::::::eeeee::::::e  n:::::nnnn:::::n i::::i     x::::::::::x
 P::::P             h:::::h     h:::::ho::::o     o::::oe:::::::::::::::::e   n::::n    n::::n i::::i      x::::::::x
 P::::P             h:::::h     h:::::ho::::o     o::::oe::::::eeeeeeeeeee    n::::n    n::::n i::::i      x::::::::x
 P::::P             h:::::h     h:::::ho::::o     o::::oe:::::::e             n::::n    n::::n i::::i     x::::::::::x
PP::::::PP           h:::::h     h:::::ho:::::ooooo:::::oe::::::::e            n::::n    n::::ni::::::i   x:::::xx:::::x
P::::::::P           h:::::h     h:::::ho:::::::::::::::o e::::::::eeeeeeee    n::::n    n::::ni::::::i  x:::::x  x:::::x
P::::::::P           h:::::h     h:::::h oo:::::::::::oo   ee:::::::::::::e    n::::n    n::::ni::::::i x:::::x    x:::::x
PPPPPPPPPP           hhhhhhh     hhhhhhh   ooooooooooo       eeeeeeeeeeeeee    nnnnnn    nnnnnniiiiiiiixxxxxxx      xxxxxxx







  SSSSSSSSSSSSSSS lllllll
SS:::::::::::::::Sl:::::l
S:::::SSSSSS::::::Sl:::::l
S:::::S     SSSSSSSl:::::l
S:::::S             l::::l   aaaaaaaaaaaaavvvvvvv           vvvvvvv eeeeeeeeeeee
S:::::S             l::::l   a::::::::::::av:::::v         v:::::vee::::::::::::ee
S::::SSSS          l::::l   aaaaaaaaa:::::av:::::v       v:::::ve::::::eeeee:::::ee
 SS::::::SSSSS     l::::l            a::::a v:::::v     v:::::ve::::::e     e:::::e
   SSS::::::::SS   l::::l     aaaaaaa:::::a  v:::::v   v:::::v e:::::::eeeee::::::e
      SSSSSS::::S  l::::l   aa::::::::::::a   v:::::v v:::::v  e:::::::::::::::::e
           S:::::S l::::l  a::::aaaa::::::a    v:::::v:::::v   e::::::eeeeeeeeeee
           S:::::S l::::l a::::a    a:::::a     v:::::::::v    e:::::::e
SSSSSSS     S:::::Sl::::::la::::a    a:::::a      v:::::::v     e::::::::e
S::::::SSSSSS:::::Sl::::::la:::::aaaa::::::a       v:::::v       e::::::::eeeeeeee
S:::::::::::::::SS l::::::l a::::::::::aa:::a       v:::v         ee:::::::::::::e
SSSSSSSSSSSSSSS   llllllll  aaaaaaaaaa  aaaa        vvv            eeeeeeeeeeeeee

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////// PIN GENERALI //////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
*/
#define BENCHMARK
unsigned long loopsPerSec = 0;
unsigned long prevMillis = 0;

//#define PRINT_VALORI_PALLA




// UART PHOENIX
#define RX1 0
#define TX1 1  // Canale 1 / PC / Boss
// RX2 = 9; TX2 = 10 // Canale 2/ LED
// RX3 = 7; TX3 = 8 // Canale 3/ NON USATO

// LED RGB
#define rgb_Blue 5
#define rgb_Red 25
#define rgb_Green 6

// BUZZER
#define buzzer 30

// LED
int led[] = {9, 10, 31};
/*
Index Array
0: Led1
1: Led2
2: LedAlim
*/

// MULTIPLEXER
int mux[] = {2, 3, 4, 24};
/*
Index Array
0:ExpA
1:ExpB
2:ExpC
3:ExpD
*/
#define exp_Read 14

// Sensori Palla
int sensPalla[] = {A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A15, A16, A17};
/*
Index Array
0: S1
1: S2
2: S3
3: S4
4: S5
5: S6
6: S7
7: S8
8: S9


9: S14
10: S15
11: S16
12: S17
13: S18
14: S19
15: S20
*/
int valPalla[20];
/*
ACCESSIBILE TRAMITE MUX
1 S10
2 S11
3 S12
4 S13
*/


// Ultrasuoni
#define startUSread 33  //inizia le letture continue degli ultrasuoni

/*
ACCESSIBILE TRAMITE MUX
5 Anteriore
6 Destra
7 Posteriore
8 Sinistra
*/
int valUs[4];
/*
 * 0 = UsAx
 * 1 = UsDx
 * 2 = UsPx
 * 3 = UsSx
 */

// Livello Batteria
#define batLevel 32


////////////////////////////////
///////////BREAKOUT SLAVE //////
////////////////////////////////
/*
D6
D11
D12
D13
D30
*/



////////////////////////////////
///////////SERIALE /////////////

byte istruzione = 0;
byte byteRichiesta = 'r';

int distanzaZero[20] = {1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023};
int distanzaUno[20]  = {1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023};
int distanzaDue[20]  = {1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023};
int distanzaTre[20]  = {1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023};


////////////////////////////////
///////////// VAR  /////////////
byte palla = 0;
byte distanza = 0;



void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);

  // LED RGB
  pinMode(rgb_Red, OUTPUT);
  pinMode(rgb_Green, OUTPUT);
  pinMode(rgb_Blue, OUTPUT);

  // Buzzer
  pinMode(buzzer, OUTPUT);

  // Mux
  /*for(int m = 0;m<4;m++)
  {
  	pinMode(mux[m],OUTPUT);
  }*/
  pinMode(exp_Read, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(24, OUTPUT);

  // LED 9,10,31
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(31, OUTPUT);

  //BATTERIA
  if (analogRead(batLevel) < 585)// 585 corrisponde a  10.7V
  {
    digitalWrite(led[2], HIGH);
    tone(buzzer, 4000, 200);
    delay(100);
  }


  //usBegin();
  delay(1500);
  leggiDistanzeEEPROM();
}






void loop()
{
  //digitalWrite(5, HIGH);
  //delay(1000);
  //digitalWrite(5, LOW);
  //delay(1000);
  //readUs();
  //tone(buzzer,4000);
  //delay(1000);
  //noTone(buzzer);
  //delay(1000);
  /*
    Serial.print(analogRead(A17));
    Serial.print(" - ");
    Serial.print(analogRead(A1));
    Serial.print(" - ");
    Serial.println(analogRead(A2));
  */
#ifdef BENCHMARK
  loopsPerSec++;
  long currentMillis = millis();

  if (currentMillis - prevMillis > 1000) {
    Serial.print(loopsPerSec);
    Serial.println(" loops per second");
    loopsPerSec = 0;
    prevMillis = currentMillis;
  }
#endif

  findPalla();
  
#ifdef PRINT_VALORI_PALLA
  Serial.print("sensore palla = ");
  Serial.print(palla);
  Serial.print(" - Distanza = ");
  Serial.println(distanza);
#endif

  rgb(0, 0, 0);

  if (Serial1.available()) {
    istruzione = Serial1.read();

    Serial.println(istruzione);
    if (istruzione == byteRichiesta) {  // byte richiesta = 'r'
      rgb(0, 100, 0);

      Serial1.write(palla);/// 50 = no palla
      Serial1.write(distanza);

      Serial1.write(0); //us
      Serial1.write(0);
      Serial1.write(0);
      Serial1.write(0); //us

      istruzione = 0;
    }

    else if (istruzione == 'c') { /// avvio calibrazione
      calibrazione();
      istruzione = 0;
    }

  }//serial 1 available

}

