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

                                                                                                                          */


/*
UUUUUUUU     UUUUUUUU
U::::::U     U::::::U
U::::::U     U::::::U
UU:::::U     U:::::UU
 U:::::U     U:::::Uppppp   ppppppppp
 U:::::D     D:::::Up::::ppp:::::::::p
 U:::::D     D:::::Up:::::::::::::::::p
 U:::::D     D:::::Upp::::::ppppp::::::p
 U:::::D     D:::::U p:::::p     p:::::p
 U:::::D     D:::::U p:::::p     p:::::p
 U:::::D     D:::::U p:::::p     p:::::p
 U::::::U   U::::::U p:::::p    p::::::p
 U:::::::UUU:::::::U p:::::ppppp:::::::p
  UU:::::::::::::UU  p::::::::::::::::p
    UU:::::::::UU    p::::::::::::::pp
      UUUUUUUUU      p::::::pppppppp
                     p:::::p
                     p:::::p
                    p:::::::p
                    p:::::::p
                    p:::::::p
                    ppppppppp
                                  
   _____          _____                 _____  ________      __    __ 
  / ____|   /\   |  __ \     /\        |  __ \|  ____\ \    / /   /_ |
 | |  __   /  \  | |__) |   /  \       | |__) | |__   \ \  / /     | |
 | | |_ | / /\ \ |  _  /   / /\ \      |  _  /|  __|   \ \/ /      | |
 | |__| |/ ____ \| | \ \  / ____ \     | | \ \| |____   \  /       | |
  \_____/_/    \_\_|  \_\/_/    \_\    |_|  \_\______|   \/        |_|
                                                                      
                                                                                        


 */


#include <math.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#include <Wire.h>
#include <EEPROM.h>
#include "SFE_HMC6343.h"
#include <PID_v1.h>
#include <Pixy.h>



//===========================================================================
//============================= Main ========================================
//===========================================================================




// Imposta la velocità dei movimenti base
// da circa 20 a 255
#define VELOCITA 160

// Imposta la velocità una volta che la palla è davanti al robot
#define VELOCITA_ATTACCO 180

// Imposta una rampa nelle variazioni di velocità, per un movimento piu' fluido
#define SOFT_MOVES 0 
// Imposta l'intervallo in millisecondi per la variazione di velocità
#define SOFT_MOVES_INTERVALLO 1000


// Imposta i movimenti per rilevare anche le linee bianche nel campo
#define RILEVA_BORDI 1
// Imposta la velocità per allontanarsi dalla linea
#define VELOCITA_FUGA_LINEA 180
// Imposta il tempo di fuga dalla linea
#define TEMPO_FUGA 550

// Imposta la forza del calcio
// Piu' è alta e maggiore sarà la forza e il consumo
// Valori predefiniti:
// 500 DEFAULT
// ... da testare
#define TEMPO_CALCIO 300







//===========================================================================
//============================= P.I.D. ======================================
//===========================================================================


// Imposta i valori delle 3 costanti per il PID

double kp = 0.95;
double ki = 0;
double kd = 0;
/*  
double kp = 1;
double ki = 0;
double kd = 0.5;
*/
































































SFE_HMC6343 compass; // la variabile compass sarà usata per tutte le iterazioni col sensore
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////  P I D       //////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

double setPoint, Input, Output;
PID myPID(&Input, &Output, &setPoint, kp, ki, kd, DIRECT);


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////// PIN GENERALI //////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// UART PHOENIX
#define RX1 0
#define TX1 1  // Canale 1 / PC / Slave 
// RX2 = 9; TX2 = 10; Canale 2/ NON USATO / PWM2 - CS
#define RX3 7
#define TX3 8// Canale 3/ BLUETOOTH /

// BUSSOLA
int Vnord, gradi, gradi_rel, gradiE;

float dirX = 0;
float dirY = 0;

byte headingData[2];
int i, headingValue;
int base_bussola;
unsigned long bussolaMillis = 0, accelMillis = 0, lastCalMillis = 0;

boolean correzione = true, bussola_firstLettura = 1, bussola_firstCal = 1;

// SHIFT REGISTER
//Pin connected to ST_CP of 74HC595
int latchPin = 30;
//Pin connected to SH_CP of 74HC595
int clockPin = 28;
////Pin connected to DS of 74HC595
int dataPin = 17;

//holders for infromation you're going to pass to shifting function
byte byteLed = 0;
byte byteMotori = 0;

// LED VARI ( SHIFT REGISTER_2)
/*
Index Array:
0:Led 1 Tattica 2
1:Led 2 Tattica 1
2:Led 3 Tattica 3
3:Led 4 Tattica 4
4:Led 5 Linee Ant
5:Led 6 Linee Dx
6:Led 7 Linee Sx
7:Led 8 Linee Post
*/

// LED RGB
#define rgb_Green 6
#define rgb_Red 20
#define rgb_Blue 25


// DISPLAY
#define CS 10
#define DC 21

#define  BLACK           0x0000   // 0        PER ALTRI COLORI VEDI SULLA SCHEDA LCD
#define BLUE            0x001F   //31
#define RED             0xF800   //63488
#define GREEN           0x07E0   //2016
#define CYAN            0x07FF   //2047
#define MAGENTA         0xF81F   //63519
#define YELLOW          0xFFE0   //65504
#define WHITE           0xFFFF   //65535
#define TRANSPARENT     -1

#define LIGHTGRAY       0xC618      // 192, 192, 192 
#define DARKGRAY        0x7BEF      // 128, 128, 128 
#define DARKGREEN       0x03E0      //   0, 128,   0 
#define DARKCYAN        0x03EF      //   0, 128, 128
#define PURPLE          0x780F      // 128,   0, 128 
#define OLIVE           0x7BE0      // 128, 128,   0 
#define LIGHTGREEN     0xAFE5      // 173, 255,  47 


// ENCODER
#define encoder0PinB 23
#define sel A11
#define encoder0PinA 22

volatile int encoderPos = 0;
unsigned int tmp_Pos = 1;

volatile boolean A_set = true;
volatile boolean B_set = true;

//// Buzzer
//#define buzzer 25

// Tattiche
#define dipSw A13

// Trimmer Velocità
#define speed A12

// Solenoide
#define calcio 29
unsigned long calcioMillis = 0;
bool caricoCalcio = 0; 
// Sensore Palla
#define sensPalla 28


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////// LINEE /////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// La nuova configurazione attiva il sensore anteriore
// e sfrutta il sensore posteriore centrale come secondo centrale

const int linee[] = {2, 3, 31, 26, 27, 24, 14, 15, 16, 33};
/*
Index Array:
0:Linea1 Destra:Superiore
1:Linea2 Destra:Inferiore
2:Linea3 Ant:Destra

3:Linea4 Post:Destra
4:Linea5 Post:Sinistra
5:Linea6 Post:Centrale

6:Linea7 Sinistra:Inferiore
7:Linea8 Sinistra:Superiore
8:Linea9 Ant:Sinistra

*/ 
//int gradi_Linee[] = {80, 100, 35, 170, 190, 180, 260, 280, 325};
// lineFinder.rev3 usa il grado d'arco ma i radianti dato che
// la libreria math.h di Arduino usa proprio i radianti.
const double gradi_Linee[] = {1.3963,1.7453,0.610865,2.9671,3.3161,3.14159,4.5379,4.8869,5.67232};
//double gradi_Linee[] = {1.3963,1.7453,0.610865,2.9671,3.3161,3.14159,4.5379,4.8869,5.67232};
float X = 0,Y = 0;
//lineaMillis salva ogni quanto è stata attuata la funzione della linea
//correzioneMillis salva ogni quanto è stata corretta la traiettoria
unsigned long lineaMillis = 0, correzioneMillis = 0;
// intervalloLinea indica dopo quanti ms và riattivata la funzione di linea
// intervalloCorr indica per quanto tempo il robot corregge la traiettoria
int intervalloLinea = 400,intervalloCorr = 600;
byte nSens = 0; // quanti sensori hanno visto la linea
// Ho deciso di usare massimo 6 sensori per rilevare la linea
// Il valore 90 è random per non interferire col programma
int sensoriTrovati[4] = {90,90,90,90};
volatile int direzioneCorrezione;
unsigned long sommaGradi = 0, sommaGradiCorr;
boolean stoCorreggendo = 0;

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////// MOTORI ////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/*
	MOTORI:
	1: ANTERIORE: SINISTRO
	2: ANTERIORE: DESTRO
	3: POST: DESTRO
	4: POST: SINISTRO
*/

// PWM MOTORI
#define pwm1 5
#define pwm2 9
#define pwm3 32
#define pwm4 4

#define ORARIO 0
#define ANTIORARIO 1

#define fermo           -1
#define ruotaSx         -2       // sinistrta valore vel positivo ----- destra valore vel negativo
#define ruotaDx         -3

#define avanti          0
#define indietro        180
#define sinistra        270
#define destra          90
#define diagonaleAdx    45
#define diagonalePdx    135
#define diagonalePsx    225
#define diagonaleAsx    315

// DIREZIONI MOTORI
int dir[] = {15, 1, 2, 3, 4, 5, 6, 7};
volatile int vel = VELOCITA;
volatile int traiettoriaPalla;
unsigned long softMovesMillis = 0;
unsigned long pallamillis = 0;

/*
Index Array:
0: INA1
1: INB1
2: INA2
3: INB2
4: INA3
5: INB3
6: INA4
7: INB4
*/

const float pi = 3.14;
double vx, vy, rw;
float rad = 0.0174532;

//  VARIABILI SERIALI

String inputString = "";
boolean stringComplete = false;

TFT_ILI9163C display = TFT_ILI9163C(CS, DC);

unsigned long currentMillis;

//////////////////////////
////////DIP SWITCH////////
const int constDipSW[] = {1020, 217, 460, 172,  608, 190, 353, 155,  765, 203, 401, 163,  510, 179, 317, 148};
boolean dipSW1 = 0;
boolean dipSW2 = 0;
boolean dipSW3 = 0;
boolean dipSW4 = 0;

//////////////////////////
////////    US    ////////
int distanzaAx, distanzaDx, distanzaPx, distanzaSx;

//////////////////////////
//////// Seriale  ////////
int posPalla;
int distanzaPalla;

//////////////////////////
//////// PIXY  ///////////
Pixy pixy;
byte firmaColore = 1;

bool usoPixy = 0;
volatile int blockX;
unsigned long pixyMillis = 0;
int vNordMagicSmoke;


///// PORTIERE

bool Portiere = 0;
bool portiereLineaPresa = 0;
unsigned long portiereLineaMillis = 0;

void setup()
{
  pinMode(calcio,OUTPUT);
  digitalWrite(calcio,LOW);
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial3.begin(115200);

  Serial.println("Serial On");

  delay(500);

  //BUSSOLA
  if (!compass.init()) // Se la bussola non si attiva, viene inviato un messaggio di errore
  {
    Serial.println("Inizializzazione Bussola Fallita\n\r");
  }

  delay(100);

  //ENCODER
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  //attachInterrupt(23, doEncoder, CHANGE);
  pinMode(sel, INPUT);

  // LCD
  display.begin();
  display.setBitrate(20000000);
  display.setRotation(45);
  Serial.println("Display On");

  //LED RGB
  pinMode(rgb_Red, OUTPUT);
  pinMode(rgb_Green, OUTPUT);
  pinMode(rgb_Blue, OUTPUT);
  Serial.println("Led On");

  // Sensore Palla
  //pinMode(sensPalla,OUTPUT);
  //attachInterrupt(sensPalla, locked_ball, FALLING);

  // LINEE

  for (int pm = 0; pm <= 9; pm++)
  {
    pinMode(linee[pm], INPUT);
  }

  // MOTORI
  initMotori();
  Serial.println("Motori On");

  // SHIFT REGISTER
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.println("Shift Register On");

  /*
    for(int stato=0;stato<3;stato++)
   {
      statoLed(stato,0);
   }
   shiftRegister_sendBytes(); */

  // TATTICHE
  pinMode(dipSw, INPUT);

  digitalWrite(rgb_Red, HIGH);
  digitalWrite(rgb_Red, LOW);

  bussola_setNord();
  bussola_getHeading();
  Input = gradiE;
  setPoint = 0;
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-180, 180);
  Serial.println("Ready 2 Go");
  tone(25,2000,500);
  delay(1000);

  leggiDipSW();
  if(dipSW4) 
  {
    autocalibrazionePalla();
  }
  if(dipSW2)
  {
    firmaColore = 2;  
  }
  if(dipSW3)
  {
   portiere();
  }
  
  if(dipSW1)
  {
     bussola_cal();
  } 
}


void loop()
{ 
  //linee_debug();
  currentMillis = millis();
  //portiere();
  //bussola_getHeading();
  //individuaLinee();
    getPalla();
  
  //getPalla1(); //switch
  
  display.clearScreen();
  display.setTextSize(3);
  display.setTextColor(RED,BLACK);
  display.setCursor(0,0);
  display.print(posPalla);
  display.setCursor(100,0);
  display.print(distanzaPalla);
  display.setCursor(40,64);
  display.print(traiettoriaPalla);
  display.setCursor(40,100);
  display.print(gradiE);
  
  //delay(2); 
 
  
}





void initMotori()
{
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);
}
