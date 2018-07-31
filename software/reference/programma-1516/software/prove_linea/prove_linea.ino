
////////////////////////////////////////////////////////
//
//  Progetto: Robot calciatore Open league
//  Inizio: 12/12/1992
//  
//
//
//
//

#include <math.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#include <Wire.h>
#include <EEPROM.h>

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  LCD
#define CS 22
#define DC 24
#define RST 23
#define backLight 25
int maxEncoderPos, lvl = 0;


#define	BLACK           0x0000   // 0        PER ALTRI COLORI VEDI SULLA SCHEDA LCD
#define	BLUE            0x001F   //31
#define	RED             0xF800   //63488
#define	GREEN           0x07E0   //2016
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

TFT_ILI9163C display = TFT_ILI9163C(CS, DC, RST);



/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  ENCODER

#define encoder0PinA 18
#define encoder0PinB 19
#define encoderSel 27

volatile int encoderPos = 0;
unsigned int tmp_Pos = 1;

volatile boolean A_set = true;
volatile boolean B_set = true;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  MOTORI

const int INA1 = 31, INB1 = 35, PWM1 = 13, CS1 = A1, INA2 = 32, INB2 = 36, PWM2 = 12, CS2 = A2, INA3 = 33, INB3 = 37, PWM3 = 11, CS3 = A3, INA4 = 34, INB4 = 38, PWM4 = 10, CS4 = A4;
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


double vx, vy, rw;
float rad = 0.0174532;
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  LED RGB

#define ledR 7
#define ledG 9
#define ledB 8

// LED BATTERIA

#define ledBat 30

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  VARIABILI SENSORI LINEE

int linea;
int valore;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  VARIABILI SERIALI

String inputString = "";
boolean stringComplete = false;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  CONSIGLIATORI

const int tattica1 = 28, tattica2 = 29 ;
const int dipsw1 = 40, dipsw2 = 26, dipsw3 = 53 ;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  BUSSOLA

int HMC6352Address = 0x42;
int slaveAddress;
byte headingData[2];
int i, headingValue;
int vnord, gradi;
int base_bussola;

boolean correzione = true;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  PID

float P, D, PD, ErrorePrec;
float e;
float kp = 0.07;
float kd = 0.15;
int sommaE, gradiE, vnordE, deltaE;
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  BATTERIA

int batteria = A0;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  SENSORE PALLA

volatile boolean bandieraIr = false;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  LINEE

// interrupt bianco = int 0
// interrupt nero   = int 1

#define wLine1 47
#define wLine2 48
#define wLine3 49

#define bLine1 42
#define bLine2 43
#define bLine3 44

volatile boolean bandieraBianca = false;
volatile boolean bandieraBiancaInd = false;
volatile boolean bandieraNera   = false;
volatile byte sensW = 0;
volatile byte sensB = 0;
int vecchioSensore;
boolean salvaSensorePalla;
unsigned long ultimoTempo, tempoLinea, tempoLineaPrec;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  US

int distAx, distPx, distDx, distSx;

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//  XXXXXX


//usata anche dal menù
int velM = 50;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() { 

  Serial.begin(9600);
  Serial2.begin(115200);  //BLUETOOTH
  Serial3.begin(9600);  // SLAVE

  //BATTERIA
  if (analogRead(batteria) < 585) {
    digitalWrite(ledBat, HIGH);           // Proporzione rifatta da Fabio Ricci il 21/03/15
    tone(6, 4000, 200);                    // 585 corrisponde a  10.7V misurata col tester Fregato al Pacinotti
    delay(100);
  }                                      



  // LCD
  display.begin();
  display.setBitrate(20000000);
  display.setRotation(45);
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);

  //LED RGB
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledBat, OUTPUT);

  //LINEE
//  attachInterrupt(0, lineaBianca, RISING);
//  attachInterrupt(1, lineaNera, FALLING);

  //MOTORI
  motorsInit();

  //BUSSOLA
  slaveAddress = HMC6352Address >> 1;   // This results in 0x21 as the address to pass to TWI
  Wire.begin();
  Wire.beginTransmission(slaveAddress);
  Wire.write('G');                               // Command - Write to RAM
  Wire.write(0x74);                            // Operational mode control byte register address 74(hex).
  Wire.write(0x72);                           // 20 Hz - Continuous mode.
  Wire.endTransmission();
  digitalWrite(25, HIGH);

  base_bussola = leggiBussola();
  delay(100);


  //CONSIGLIATORI
  pinMode(tattica1, INPUT_PULLUP);
  pinMode(tattica2, INPUT_PULLUP);
  pinMode(dipsw1, INPUT_PULLUP);
  pinMode(dipsw2, INPUT_PULLUP);
  pinMode(dipsw3, INPUT_PULLUP);

  pinMode(encoderSel, INPUT_PULLUP);
  base_bussola = leggiBussola();// settaggio v nord


  if (digitalRead(tattica2) == HIGH)
  {
    delay(3000);
    calibraBussola();
  }
  if (digitalRead(dipsw1) == LOW)
  {
    led(10, 100, 0);
    delay(1000);
    //ledOff();
    //portiere();
  }
}//setup
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{

  //  gradi = leggiBussola();
  gradi = gradi_norm();


  if ( (gradi >= 145) && (gradi < 180)) {
    moveRobot(ruotaSx, velM, 0, 0);
    delay(100);
  }


  if ( (gradi >= 180) && (gradi < 215)) {
    moveRobot(ruotaDx, velM, 0, 0);
    delay(100);
  }


    switch (linea)  {  // 0 - 9

    case 0:
      if ((valore > 1))
      {
        //moveRobot(avanti, 0, 200, 1);
      }
      else 
      {
        //moveRobot(avanti, 0, velM+35, 1);
      }
      break;

    case 1:
      if (valore > 1) 
      {
        //moveRobot(80, 0, velM, correzione);
      }
      else 
      {
        //moveRobot(35, -20, velM-20, correzione);
      }
      break;

    case 2:
      if (valore > 1) 
      {
        //moveRobot(80, 0, velM, correzione);
      }
      else 
      {
        //moveRobot(105, 0, velM, correzione); // prima 170
      }
      break;

    case 3:
      if (valore > 1) 
      {
        //moveRobot(115, 0, velM, correzione);
      }
      else 
      {
        //moveRobot(135, 0, velM, correzione);//170
      }
      break;

    case 4:
      if (valore > 1) 
      {
        //moveRobot(170, 0, velM, correzione);
      }
      else 
      {
        //moveRobot(105, 0, velM, correzione);
      }
      break;

    case 5:
      if (valore > 1) 
      {
        //moveRobot(180, 0, velM, correzione);
      }
      else 
      {
        //moveRobot(225, 0, velM, correzione);
      }
      break;

    case 6:
      if (valore > 1) 
      {
        //moveRobot(90, 0, velM, correzione);
      }
      else 
      {
        //moveRobot(270, 0, velM, correzione);
      }
      break;

    case 7:
      if (valore > 1) 
      {
        //moveRobot(180, 0, velM, correzione);
      }
      else 
      {
        //moveRobot(105, 0, velM, correzione);
      }
      break;

    case 8:
      if (valore > 1) 
      {
        //moveRobot(190, 0, velM, correzione);
      }
      else
      {
        //moveRobot(255, 0, velM, correzione);
      }
      break;

      default:  // non vedo la linee

      gradi = gradi_norm();

      if ( (gradi >= 145) && (gradi < 180))
      {
      moveRobot(ruotaSx, velM, 0, 0);
      delay(100);
      }

      if ( (gradi >= 180) && (gradi < 215)) 
      {
      moveRobot(ruotaDx, velM, 0, 0);
      delay(100);
      }

      moveRobot(90, 0, 70, 0);
      break;

    }//switch

}//loop



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void test_movimento_motori() {

  moveRobot(avanti, 0, velM, 0);
  delay(2000);
  moveRobot(fermo, 0, 0, 0);
  delay(200);

  moveRobot(indietro, 0, velM, 0);
  delay(2000);
  moveRobot(fermo, 0, 0, 0);
  delay(200);

  moveRobot(destra, 0, velM, 0);
  delay(2000);
  moveRobot(fermo, 0, 0, 0);
  delay(200);

  moveRobot(sinistra, 0, velM, 0);
  delay(2000);
  moveRobot(fermo, 0, 0, 0);
  delay(200);

  moveRobot(diagonaleAdx, 0, velM, 0);
  delay(2000);
  moveRobot(fermo, 0, 0, 0);
  delay(200);

  moveRobot(diagonaleAsx, 0, velM, 0);
  delay(2000);
  moveRobot(fermo, 0, 0, 0);
  delay(200);

  moveRobot(diagonalePdx, 0, velM, 0);
  delay(2000);
  moveRobot(fermo, 0, 0, 0);
  delay(200);

  moveRobot(diagonalePsx, 0, velM, 0);
  delay(2000);
  moveRobot(fermo, 0, 0, 0);
  delay(200);
  delay(10000);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//void lineaBianca() 
//{
//  if (bandieraBianca == true) return;
//  tone(6, 1000, 200);
//  if (((digitalRead(wLine1)== HIGH)&&(digitalRead(wLine2)== HIGH))||((digitalRead(wLine1)== HIGH)&&(digitalRead(wLine3)== HIGH))||((digitalRead(wLine2)== HIGH)&&(digitalRead(wLine3)== HIGH)))
//  {
//    if ((digitalRead(wLine1)== HIGH)&&(digitalRead(wLine2)== HIGH))
//    {
//      serialEvent3();
//       for(int m=0; m<300; m++){
//       riallinea();
//  }
//      if (distDx<40)
//      {
//        sensW= 2;
//      }
//      else
//      {
//        sensW=3;
//      }
//    }
//if ((digitalRead(wLine1)== HIGH)&&(digitalRead(wLine3)== HIGH))
//    {
//      serialEvent3();
//             for(int m=0; m<300; m++){
//       riallinea();
//  }
//      if (distSx<40)
//      {
//        sensW= 3;
//      }
//      else
//      {
//        sensW=2;
//      }
//    }
//  }
//
//  else if (digitalRead(wLine1) == HIGH) {
//    bandieraBianca = true;
//    sensW = 1;
//  }
//  else if (digitalRead(wLine2) == HIGH) {
//    bandieraBianca = true;
//    sensW = 2;
//  }
//  else if (digitalRead(wLine3) == HIGH) {
//    bandieraBianca = true;
//    sensW = 3;
//  }
//}




void serialEvent3() {
  String strA, strB, strC, strD, strE, strF;
  while (Serial3.available()) { // get the new byte:
    analogWrite(ledB, 40);
    char inChar = (char)Serial3.read();
    if (inChar == '#') {
      strA = Serial3.readStringUntil(',');
      strB = Serial3.readStringUntil(',');
      strC = Serial3.readStringUntil(',');
      strD = Serial3.readStringUntil(',');
      strE = Serial3.readStringUntil(',');
      strF = Serial3.readStringUntil(',');
      
      linea = strA.toInt();
      valore = strB.toInt();
      distAx = strC.toInt();
      distDx = strD.toInt();
      distPx = strE.toInt();
      distSx = strF.toInt();
    }
    else return;


    Serial.println("\n\n");
    
    Serial.print(linea);
    Serial.print("  --  ");
    Serial.print(valore);
    Serial.print("  --  ");
    Serial.print(distAx);
    Serial.print("  --  ");
    Serial.print(distDx);
    Serial.print("  --  ");
    Serial.print(distPx);
    Serial.print("  --  ");
    Serial.print(distSx);
    Serial.print("\n\n");


  }
  digitalWrite(ledB, LOW);
  Serial3.flush();
}/// serialEvent3



