
/*
void setup(){
 
 Wire.beginTransmission(HMC6352SlaveAddress);
 Wire.write('G');                               // Command - Write to RAM
 Wire.write(0x74);                            // Operational mode control byte register address 74(hex). 
 Wire.write(0x72);                           // 20 Hz - Continuous mode.
 Wire.endTransmission();
 }
 
 
 */


void calibraBussola()
{  
  //Enter User Calibration Mode by sending an ASCII 'C'
  Wire.beginTransmission(slaveAddress);
  Wire.write('C');              // The "C" command  starts calibration
  Wire.endTransmission();

  Serial.print("CALIBRATING Compass, "); 

  moveRobot(ruotaDx,20,0,0);

  delay(40000);

  //End User Calibration Mode by sending an ASCII 'E'
  Wire.beginTransmission(slaveAddress);
  Wire.write('E');              // The "E" command exits calibration
  Wire.endTransmission();

  frena(100);
  delay(1000);
  moveRobot(fermo,0,0,0);
} 

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void salvaVnord(){
  gradi=leggiBussola();  
  EEPROM.write(0, highByte(gradi));
  EEPROM.write(1, lowByte(gradi));
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

int posizioneVirtuale(){
  int a;
  a = (leggiBussola() - vnord);
  if(a <0)
    a = 360 + a;
  return a;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

int leggiBussola(){

  Wire.requestFrom(slaveAddress, 2);  //get the two data bytes, MSB and LSB
  //"The heading output data will be the value in tenths of degrees
  //from zero to 3599 and provided in binary format over the two bytes."
  byte MSB = Wire.read();
  byte LSB = Wire.read();

  gradi = (MSB << 8) + LSB; //(MSB / LSB sum)
  gradi = gradi / 10; 
  return gradi;
}

int gradi_norm()
{
  gradi = leggiBussola() - base_bussola;
  if (gradi < 0) gradi+= 360;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/*
int pidBussola(){
 leggiBussola();
 gradiE = gradi-180;
 deltaE = gradiE-vnordE;
 if(deltaE<-180) deltaE = deltaE + 360 ;
 e=deltaE;
 P = e*kp;
 D = (e-ErrorePrec)*kd;
 PD = P + D;
 PD = constrain(PD, -30,30);
 
 }
 */


int pidBussola(){
  int gradiPv = posizioneVirtuale();
  gradiE = gradiPv-180;
  deltaE = gradiE-vnordE;
  if(deltaE<-180) deltaE = deltaE + 360 ;
  e=deltaE;
  P = e*kp;
  D = (e-ErrorePrec)*kd;
  PD = P + D;
  PD = constrain(PD, -30,30);

}



