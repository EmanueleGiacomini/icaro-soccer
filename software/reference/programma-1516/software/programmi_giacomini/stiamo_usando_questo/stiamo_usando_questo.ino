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
                                   */


#include <math.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#include <Wire.h>
#include <EEPROM.h>
#include "SFE_HMC6343.h"

SFE_HMC6343 compass; // la variabile compass sarà usata per tutte le iterazioni col sensore

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
unsigned long gradi_rel = 0;
float Vnord,Vnord_rel;
float dirX = 0;
float dirY = 0;

byte headingData[2];
int i, headingValue;
int vnord, gradi;
int base_bussola;

boolean correzione = true;

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
#define rgb_Blue 6
#define rgb_Red 20
#define rgb_Green 25


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

// Buzzer 
#define buzzer A14

// Tattiche
#define dipSw A13

// Trimmer Velocità
#define speed A12

// Solenoide 
#define calcio 29

// Sensore Palla
#define sensPalla 28


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////// LINEE /////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

int linee[] = {2,3,31,24,27,26,14,15,16,33};
int gradi_Linee[] = {80,70,90,170,190,180,260,280,270,0};
unsigned long previousMillis_Linea = 0;
const int intervallo_Linea = 1000;
/*
Index Array:
0:Linea1 Destra:Superiore
1:Linea2 Destra:Inferiore
2:Linea3 Destra:Centrale
3:Linea4 Post:Destra
4:Linea5 Post:Sinistra
5:Linea6 Post:Centrale
6:Linea7 Sinistra:Inferiore
7:Linea8 Sinistra:Superiore
8:Linea9 Sinistra:Centrale
9:LineaAnteriore  */

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

#define CORREZIONE_DX -16
#define CORREZIONE_SX 16
#define CORREZIONE_DX_FORTE -30
#define CORREZIONE_SX_FORTE 30


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
int dir[] = {15,1,2,3,4,5,6,7};
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

double vx, vy, rw;
float rad = 0.0174532;

//  VARIABILI SERIALI

String inputString = "";
boolean stringComplete = false;


TFT_ILI9163C display = TFT_ILI9163C(CS, DC);


unsigned long currentMillis = 0;

void setup() 
{
	Serial.begin(9600);
	Serial3.begin(115200);
  
  //BUSSOLA
   if(!compass.init()) // Se la bussola non si attiva, viene inviato un messaggio di errore
  {
    Serial.println("Inizializzazione Bussola Fallita\n\r");
  }
  base_bussola = leggiBussola();
  delay(100);

  base_bussola = leggiBussola();// settaggio v nord
    
	// LCD
	display.begin();
	display.setBitrate(20000000);
	display.setRotation(45);

	//LED RGB
	pinMode(rgb_Red, OUTPUT);
	pinMode(rgb_Green, OUTPUT);
	pinMode(rgb_Blue, OUTPUT);

	// Sensore Palla
	pinMode(sensPalla,OUTPUT);
	//attachInterrupt(sensPalla, locked_ball, FALLING);

	// LINEE
	for(int pm = 0;pm<=9;pm++)
	{
		pinMode(linee[pm],INPUT);
	}

	// MOTORI
	initMotori();

	// SHIFT REGISTER
	pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for(int stato=0;stato<3;stato++)
 {
    statoLed(stato,0);
 }
 shiftRegister_sendBytes();

	// TATTICHE
	pinMode(dipSw,INPUT);
}

void loop() 
{
/*  
  for(int stato=0;stato<9;stato++)
 {
    statoLed(stato,0);
 }
 shiftRegister_sendBytes();
 */
 Serial.println("loop");
 delay(1000);
}



void initMotori()
{
	pinMode(pwm1,OUTPUT);
	pinMode(pwm2,OUTPUT);
	pinMode(pwm3,OUTPUT);
	pinMode(pwm4,OUTPUT);
}

