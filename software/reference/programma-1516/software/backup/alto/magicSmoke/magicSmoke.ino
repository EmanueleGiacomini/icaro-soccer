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


   _____ _____  ______ _____  _____ __  __ ______ _   _ _______       _      ______   _____  ________      __       ___
  / ____|  __ \|  ____|  __ \|_   _|  \/  |  ____| \ | |__   __|/\   | |    |  ____| |  __ \|  ____\ \    / /      |__ \
 | (___ | |__) | |__  | |__) | | | | \  / | |__  |  \| |  | |  /  \  | |    | |__    | |__) | |__   \ \  / /          ) |
  \___ \|  ___/|  __| |  _  /  | | | |\/| |  __| | . ` |  | | / /\ \ | |    |  __|   |  _  /|  __|   \ \/ /          / /
  ____) | |    | |____| | \ \ _| |_| |  | | |____| |\  |  | |/ ____ \| |____| |____  | | \ \| |____   \  /          / /_
 |_____/|_|    |______|_|  \_\_____|_|  |_|______|_| \_|  |_/_/    \_\______|______| |_|  \_\______|   \/          |____|



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
#define VELOCITA 80

// Imposta la velocità una volta che la palla è davanti al robot
#define VELOCITA_ATTACCO 150

// Imposta una rampa nelle variazioni di velocità, per un movimento piu' fluido
#define SOFT_MOVES 0
// Imposta l'intervallo in millisecondi per la variazione di velocità
#define SOFT_MOVES_INTERVALLO 1000



// Imposta i movimenti per rilevare anche le linee bianche nel campo
#define RILEVA_BORDI 0

// MOD_LINEE Imposta il programma con il sistema a 9 sensori o a 36 sensori:
// 1 per 9 sensori
// 2 per 36 sensori
#define MOD_LINEE 2
// Imposta il tempo di calibrazione per le linee
#define INTERVALLO_CALIBRA_LINEE 15000
// Imposta la velocità per allontanarsi dalla linea
#define VELOCITA_FUGA_LINEA 150
// Imposta il tempo di fuga dalla linea
#define TEMPO_FUGA 1300



// Imposta la forza del calcio
// Piu' è alta e maggiore sarà la forza e il consumo
// Valori predefiniti:
// 100 DEFAULT
// ... da testare
#define TEMPO_CALCIO 100







//===========================================================================
//============================= P.I.D. ======================================
//===========================================================================


// Imposta i valori delle 3 costanti per il PID

double kp = 0.8;
double ki = 0;
double kd = 0;






































/*
██╗   ██╗ █████╗ ██████╗ ██╗
██║   ██║██╔══██╗██╔══██╗██║
██║   ██║███████║██████╔╝██║
╚██╗ ██╔╝██╔══██║██╔══██╗██║
 ╚████╔╝ ██║  ██║██║  ██║██║
  ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝
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

// Sensore Palla
#define sensPalla 28


TFT_ILI9163C display = TFT_ILI9163C(CS, DC);

unsigned long currentMillis;






/*
██████╗ ██╗██████╗
██╔══██╗██║██╔══██╗
██████╔╝██║██║  ██║
██╔═══╝ ██║██║  ██║
██║     ██║██████╔╝
╚═╝     ╚═╝╚═════╝
*/
double setPoint, Input, Output;
PID myPID(&Input, &Output, &setPoint, kp, ki, kd, DIRECT);


/*
 ██████╗ ██████╗ ███╗   ███╗
██╔════╝██╔═══██╗████╗ ████║
██║     ██║   ██║██╔████╔██║
██║     ██║   ██║██║╚██╔╝██║
╚██████╗╚██████╔╝██║ ╚═╝ ██║
 ╚═════╝ ╚═════╝ ╚═╝     ╚═╝
*/
// UART PHOENIX
#define RX1 0
#define TX1 1  // Canale 1 / PC / Slave 
// RX2 = 9; TX2 = 10; Canale 2/ NON USATO / PWM2 - CS
#define RX3 7
#define TX3 8// Canale 3/ BLUETOOTH /
//  VARIABILI SERIALI

String inputString = "";
boolean stringComplete = false;

int distanzaAx, distanzaDx, distanzaPx, distanzaSx;

int posPalla;
int distanzaPalla;


/*
██████╗ ██╗   ██╗███████╗███████╗ ██████╗ ██╗      █████╗
██╔══██╗██║   ██║██╔════╝██╔════╝██╔═══██╗██║     ██╔══██╗
██████╔╝██║   ██║███████╗███████╗██║   ██║██║     ███████║
██╔══██╗██║   ██║╚════██║╚════██║██║   ██║██║     ██╔══██║
██████╔╝╚██████╔╝███████║███████║╚██████╔╝███████╗██║  ██║
╚═════╝  ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝
*/
SFE_HMC6343 compass; // la variabile compass sarà usata per tutte le iterazioni col sensore
int Vnord, gradi, gradi_rel, gradiE;

float dirX = 0;
float dirY = 0;

byte headingData[2];
int i, headingValue;
int base_bussola;
unsigned long bussolaMillis = 0, accelMillis = 0, lastCalMillis = 0;

boolean correzione = true, bussola_firstLettura = 1, bussola_firstCal = 1;

/*
███████╗██╗  ██╗██╗███████╗████████╗    ██████╗ ███████╗ ██████╗ ██╗███████╗████████╗███████╗██████╗
██╔════╝██║  ██║██║██╔════╝╚══██╔══╝    ██╔══██╗██╔════╝██╔════╝ ██║██╔════╝╚══██╔══╝██╔════╝██╔══██╗
███████╗███████║██║█████╗     ██║       ██████╔╝█████╗  ██║  ███╗██║███████╗   ██║   █████╗  ██████╔╝
╚════██║██╔══██║██║██╔══╝     ██║       ██╔══██╗██╔══╝  ██║   ██║██║╚════██║   ██║   ██╔══╝  ██╔══██╗
███████║██║  ██║██║██║        ██║       ██║  ██║███████╗╚██████╔╝██║███████║   ██║   ███████╗██║  ██║
╚══════╝╚═╝  ╚═╝╚═╝╚═╝        ╚═╝       ╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
*/

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

/*
██████╗ ██╗██████╗ ███████╗██╗    ██╗██╗████████╗ ██████╗██╗  ██╗
██╔══██╗██║██╔══██╗██╔════╝██║    ██║██║╚══██╔══╝██╔════╝██║  ██║
██║  ██║██║██████╔╝███████╗██║ █╗ ██║██║   ██║   ██║     ███████║
██║  ██║██║██╔═══╝ ╚════██║██║███╗██║██║   ██║   ██║     ██╔══██║
██████╔╝██║██║     ███████║╚███╔███╔╝██║   ██║   ╚██████╗██║  ██║
╚═════╝ ╚═╝╚═╝     ╚══════╝ ╚══╝╚══╝ ╚═╝   ╚═╝    ╚═════╝╚═╝  ╚═╝
*/
// Combinazioni ottenute attivando ognuno degli switch
const int constDipSW[] = {1020, 217, 460, 172,  608, 190, 353, 155,  765, 203, 401, 163,  510, 179, 317, 148};

boolean dipSW1 = 0;
boolean dipSW2 = 0;
boolean dipSW3 = 0;
boolean dipSW4 = 0;

/*
██╗     ██╗███╗   ██╗███████╗███████╗
██║     ██║████╗  ██║██╔════╝██╔════╝
██║     ██║██╔██╗ ██║█████╗  █████╗
██║     ██║██║╚██╗██║██╔══╝  ██╔══╝
███████╗██║██║ ╚████║███████╗███████╗
╚══════╝╚═╝╚═╝  ╚═══╝╚══════╝╚══════╝
*/

//===========================================================================
//============================= Pin  ========================================
//===========================================================================

// MuxOut rappresentano i pin di uscita di ogni multiplexer
#define MUXOUT_1 A1
#define MUXOUT_2 A0
#define MUXOUT_3 A2

//MUX_ rappresentano i pin di controllo dei multiplexer
// A = LSB --- D = MSB
#define MUX_A 24
#define MUX_B 27
#define MUX_C 26
#define MUX_D 31

// Imposta la velocità per allontanarsi dalla linea
#define VELOCITA_FUGA_LINEA 200
// Imposta il tempo di fuga dalla linea
#define TEMPO_FUGA 500

//===========================================================================
//============================= Constants  ==================================
//===========================================================================
/*
const int linee[] = {2, 3, 31, 26, 27, 24, 14, 15, 16, 33};
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


// Angoli in radianti di tutti i sensori di linea

const double gradi_Linee[] = {0, 0.1745, 0.3490, 0.5236, 0.6981, 0.8727, 1.0472, 1.2217, 1.3963, 1.5708, 1.74533, 1.91986, 2.0944, 2.26893, 2.44346, 2.61799, 2.79253, 2.96706, 3.14159, 3.31613, 3.49066, 3.66519, 3.83972, 4.01426, 4.36332, 4.53786, 4.71239, 4.88692, 5.06145, 5.23599, 5.41052, 5.58505, 5.75959, 5.93412, 6.10865};
//                0,   10 ,  20  ,  30  ,  40  ,  50  ,  60  ,  70  ,  80  ,  90  ,  100  ,  110  ,  120 ,  130  ,  140  ,  150  ,  160  ,  170  ,  180  ,  190  ,  200  ,  210  ,  220  ,  240  ,  250  ,  260  ,  270  ,  280  ,  290  ,  300  ,  310  ,  320  ,  330  ,  340  ,  350  ,
float sin_Linee[36];
float cos_Linee[36];
/*
const double gradi_Linee[] = {1.3963,1.7453,0.610865,2.9671,3.3161,3.14159,4.5379,4.8869,5.67232};
//int gradi_Linee[] =        {  80  ,  100 ,  35    , 170  ,  190 ,  180  ,  260 ,  280 ,  325}; */

// Valori di soglia per ogni sensore
int soglia_Linee[36];
//
// Sensori individuati limitati a 24 sensori
int sensoriTrovati[24];

// Valori dei multiplexer
byte  bin[] = {B0000, B0001, B0010, B0011, B0100, B0101, B0110, B0111, B1000, B1001, B1010, B1011, B1100, B1101, B01101111}; //list of binary value
boolean a = 0, b = 0, c = 0, d = 0;
/*
Index Array
0:ExpA
1:ExpB
2:ExpC
3:ExpD
*/


//===========================================================================
//============================= Variables  ==================================
//===========================================================================

// Variabili che contengono le componenti X,Y dei vettori
float X = 0, Y = 0;
// nSens indica quanti sensori ha visto il robot
unsigned int nSens = 0;
// stoCorreggendo permette di capire quando ho rilevato almeno un sensore
boolean stoCorreggendo = 0;
// millisecondi da quando ho iniziato a correggere
unsigned long correzioneMillis = 0, calibraLineeMillis = 0;
// la direzione per sfuggire dalla linea
int direzioneCorrezione;
// variabile per smettere di leggere per correggere
bool stopLetture = 0;

/*
███╗   ███╗ ██████╗ ████████╗ ██████╗ ██████╗ ██╗
████╗ ████║██╔═══██╗╚══██╔══╝██╔═══██╗██╔══██╗██║
██╔████╔██║██║   ██║   ██║   ██║   ██║██████╔╝██║
██║╚██╔╝██║██║   ██║   ██║   ██║   ██║██╔══██╗██║
██║ ╚═╝ ██║╚██████╔╝   ██║   ╚██████╔╝██║  ██║██║
╚═╝     ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝
*/

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




//////////////////////////
//////// PIXY  ///////////
Pixy pixy;
byte firmaColore;

bool usoPixy = 0;
volatile int blockX;
unsigned long pixyMillis = 0;
int vNordMagicSmoke;






/*
███████╗███████╗████████╗██╗   ██╗██████╗
██╔════╝██╔════╝╚══██╔══╝██║   ██║██╔══██╗
███████╗█████╗     ██║   ██║   ██║██████╔╝
╚════██║██╔══╝     ██║   ██║   ██║██╔═══╝
███████║███████╗   ██║   ╚██████╔╝██║
╚══════╝╚══════╝   ╚═╝    ╚═════╝ ╚═╝     // FONT ANSI SHADOW
*/

void setup()
{
  initSeriale();
  initBussola();
  initEncoder();
  initLCD();
  initMotori();
  initShiftRegister();
  initPid();
  initRgb();

  pinMode(MUXOUT_1, INPUT);
  pinMode(MUXOUT_2, INPUT);
  pinMode(MUXOUT_3, INPUT);
  pinMode(MUX_A, OUTPUT);
  pinMode(MUX_B, OUTPUT);
  pinMode(MUX_C, OUTPUT);
  pinMode(MUX_D, OUTPUT);
  Serial.println("Ready 2 Go");
  tone(25, 2000, 500);
  delay(1000);

  pixy.init();  /// è stato modificato il divider del clock spi su pixy.h

  leggiDipSW();
  if (dipSW4 && !dipSW1 && !dipSW2 && !dipSW3)
  {
    autocalibrazionePalla();
  }
  if (dipSW3 && !dipSW1 && !dipSW2 && !dipSW4)
  {
    calibraLinee();
  }
  if (dipSW2 && !dipSW1 && !dipSW3 && !dipSW4)
  {
    //portiere();
  }
  if (dipSW1 && !dipSW2 && !dipSW3 && !dipSW4)
  {
    bussola_cal();
  }
  if (dipSW1 && dipSW2 && dipSW3 && dipSW4)
    firmaColore = 2;
  else
    firmaColore = 1;


  initLinee();



  //calibraLinee();
}

/*
██╗      ██████╗  ██████╗ ██████╗
██║     ██╔═══██╗██╔═══██╗██╔══██╗
██║     ██║   ██║██║   ██║██████╔╝
██║     ██║   ██║██║   ██║██╔═══╝
███████╗╚██████╔╝╚██████╔╝██║
╚══════╝ ╚═════╝  ╚═════╝ ╚═╝
*/

void loop()
{
  //test2(); //test2 è la funzione per la pixy funzionante
  if (usoPixy)statoLed(3, 1);
  else statoLed(3, 0);
  currentMillis = millis();
  //leggiLinee();
  //moveRobot(0, 0, 100, 1);
  //individuaLinee();
  bussola_getHeading();
  getPalla1();

  intToBin(0);
  if (lineaRilevata(0, 0)){
    moveRobot(180, 0, VELOCITA_FUGA_LINEA, 1);
    delay(200);
    Serial.println("DIO CANE 0");
  }

  intToBin(9);
  if (lineaRilevata(0, 9)){
    moveRobot(270, 0, VELOCITA_FUGA_LINEA, 1);
    delay(200);
     Serial.println("MADONNA PUTTANA 90");
  }

  intToBin(6);
  if (lineaRilevata(1, 6)){
    moveRobot(0, 0, VELOCITA_FUGA_LINEA, 1);
    delay(200);
    Serial.println("PADRE PIO LADRO 180");
  }
  
  intToBin(2);
  if (lineaRilevata(2, 2)){
    moveRobot(90, 0, VELOCITA_FUGA_LINEA, 1);
    delay(200);
    Serial.println("Gesu babbo natale 270");
  }




/*


  if (X != 0 && Y != 0) {
    while ((currentMillis - correzioneMillis < TEMPO_FUGA))
    {

      currentMillis = millis();
      direzioneCorrezione = double((atan2(Y, X) * 180 / 3.14159265) + 180);
      moveRobot(direzioneCorrezione, 0, VELOCITA_FUGA_LINEA, 1);
      for (int lettura = 0; lettura < 12; lettura++)
      {
        for (int nMux = 0; nMux < 3; nMux++)
        {
          //Serial.print(nMux);
          //Serial.print(" - ");
          if (lineaRilevata(nMux, lettura))
          {
            X = cos_Linee[lettura + (12 * nMux)];
            Y = sin_Linee[lettura + (12 * nMux)];
          }
        }

      }
    }

    X = 0; Y = 0;

  }
*/
  /*
   bussola_getHeading();
   individuaLinee();
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
   delay(2);
  */

}
































/*
███████╗██╗   ██╗███╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗██╗    ██╗███╗   ██╗██╗████████╗
██╔════╝██║   ██║████╗  ██║╚══███╔╝██║██╔═══██╗████╗  ██║██║    ██║████╗  ██║██║╚══██╔══╝
█████╗  ██║   ██║██╔██╗ ██║  ███╔╝ ██║██║   ██║██╔██╗ ██║██║    ██║██╔██╗ ██║██║   ██║
██╔══╝  ██║   ██║██║╚██╗██║ ███╔╝  ██║██║   ██║██║╚██╗██║██║    ██║██║╚██╗██║██║   ██║
██║     ╚██████╔╝██║ ╚████║███████╗██║╚██████╔╝██║ ╚████║██║    ██║██║ ╚████║██║   ██║
╚═╝      ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝    ╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝
*/


void initSeriale()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial3.begin(115200);
  Serial.println("Serial On");
}

void initBussola()
{
  delay(500); // 500 ms per svegliare la bussola

  if (!compass.init()) // Se la bussola non si attiva, viene inviato un messaggio di errore
  {
    Serial.println("Inizializzazione Bussola Fallita\n\r");
  }
  Serial.println("Compass On");

  delay(100);
}

void initEncoder()
{
  pinMode(sel, INPUT);
  Serial.println("Encoder On");
}

void initLCD()
{
  display.begin();
  display.setBitrate(20000000);
  display.setRotation(45);
  Serial.println("Display On");
}

void initMotori()
{
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);
  Serial.println("Motors On");

}
void initShiftRegister()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.println("Shift Register On");
}
void initPid()
{
  bussola_setNord();
  bussola_getHeading();
  Input = gradiE;
  setPoint = 0;
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255, 255);
  Serial.println("Pid On");
}
void initRgb()
{
  pinMode(rgb_Red, OUTPUT);
  pinMode(rgb_Green, OUTPUT);
  pinMode(rgb_Blue, OUTPUT);
  Serial.println("Led Rgb On");
}

void initDipsw()
{
  pinMode(dipSw, INPUT);
}


void calcolaComponentiLinee()
{
  float gradiRad;
  for (int gradi = 0; gradi < 360; gradi += 10)
  {
    gradiRad = gradi * 3.14159265 / 180;
    sin_Linee[gradi / 10] = sin(gradiRad);
    cos_Linee[gradi / 10] = cos(gradiRad);
    Serial.print(gradi), Serial.print("\t"), Serial.print(gradiRad), Serial.print("\t"), Serial.print(sin_Linee[gradi / 10]), Serial.print("\t"), Serial.println(cos_Linee[gradi / 10]);
  }
}

void initLinee()
{
  calcolaComponentiLinee();
  readSoglie();
}
