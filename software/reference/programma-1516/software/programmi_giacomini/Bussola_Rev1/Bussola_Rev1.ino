// Bussola_Rev1.ino

#include <math.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#include <Wire.h>
#include <EEPROM.h>

#include "SFE_HMC6343.h"

SFE_HMC6343 compass; // la variabile compass sarà usata per tutte le iterazioni col sensore

const int ledG = 6;
const int ledR = 20;
const int ledB = 25;

#define encoder0PinB 23
#define sel A11
#define encoder0PinA 22

volatile int encoderPos = 0;
unsigned int tmp_Pos = 1;

volatile boolean A_set = true;
volatile boolean B_set = true;

unsigned long direzione = 0;
unsigned long direzione_rel = 0;
float Vnord,Vnord_rel;
float dirX = 0;
float dirY = 0;

#define CS 10
#define DC 21

TFT_ILI9163C display = TFT_ILI9163C(CS, DC);


#define BLACK           0x0000   // 0        PER ALTRI COLORI VEDI SULLA SCHEDA LCD
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

void setup() 
{
	Serial.begin(115000); // Attivo la comunicazione Seriale a 9600 baud
  
	delay(500); // Lascio mezzo secondo alla bussola per attivarsi

  //LED RGB
  pinMode(ledG,OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledB,OUTPUT);

  //ENCODER
  pinMode(sel,INPUT_PULLUP);

  //LCD
  display.begin();
  display.setBitrate(20000000);
  display.setRotation(45);
  display.fillRect(0,0,128,128,BLUE);

  //BUSSOLA
 	if(!compass.init()) // Se la bussola non si attiva, viene inviato un messaggio di errore
	{
		Serial.println("Inizializzazione Bussola Fallita\n\r");
	}
  display.fillRect(0,0,128,128,BLACK);
}

void loop()
{ 
  Serial.print("ciao");
  display.fillRect(0,0,128,128,GREEN);
  bussola_Compute();
  if(!digitalRead(sel))
  {
    Serial.println("WOW");
    bussola_setNord();
  }
}

void bussola_Compute()
{
	compass.readHeading();
	direzione = compass.heading/10.0;
	direzione_rel = direzione - Vnord_rel;

	compass.readAccel();
	dirX = compass.accelX;
	dirY = compass.accelY;
	Serial.println(direzione);
	
}

void bussola_setNord() // Per Impostare il nord virtuale (direzione della porta avversaria), verrà campionata la direzione 100 volte.
{
	Vnord = 0;
	Vnord_rel = 0;
	for(int r=0;r<1000;r++)
	{ 
		bussola_Compute();
		Vnord += direzione;
	}
	Vnord = Vnord / 1000;

  delay(500); 

}

