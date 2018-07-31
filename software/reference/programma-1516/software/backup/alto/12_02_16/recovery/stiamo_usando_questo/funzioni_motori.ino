
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
 fermo           0
 avanti          1
 indietro        2
 ruotaSx         3
 ruotaDx         4
 sinistra        5
 destra          6
 diagonaleAdx    7
 diagonalePsx    8
 diagonaleAsx    9
 diagonalePdx    10
 */





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// cmdMot
// comanda un motore
// parametri :
//  motore : num motore 0-3
// vel : velocita' -255 / 255  positiva verso orario, negativa verso antiorario
// motori : 0 : avanti sx
// motori : 1 : avanti dx
// motori : 2 : dietro dx
// motori : 3 : dietro sx
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
void cmdMot(byte motore,int vel) // motore : 0 - 3
{      
  //Serial.println(vel);

  // CON SHIFT REGISTER
  if(motore > 3) return;

  switch(motore)
  {
    case 0:
    if(!vel) statoMotori(1,1),statoMotori(2,1),analogWrite(pwm1,255);
    if(vel > 0) statoMotori(1,1),statoMotori(2,0),analogWrite(pwm1, vel);
    if(vel < 0) statoMotori(1,0),statoMotori(2,1),analogWrite(pwm1, -vel);
    break;
    case 1:
    if(!vel) statoMotori(3,1),statoMotori(4,1),analogWrite(pwm2,255);
    if(vel > 0) statoMotori(3,0),statoMotori(4,1),analogWrite(pwm2, vel);
    if(vel < 0) statoMotori(3,1),statoMotori(4,0),analogWrite(pwm2, -vel);
    break;
    case 2:
    if(!vel) statoMotori(5,1),statoMotori(6,1),analogWrite(pwm3,255);
    if(vel > 0) statoMotori(5,0),statoMotori(6,1),analogWrite(pwm3, vel);
    if(vel < 0) statoMotori(5,1),statoMotori(6,0),analogWrite(pwm3, -vel);
    break;
    case 3:
    if(!vel) statoMotori(7,1),statoMotori(8,1),analogWrite(pwm4,255);
    if(vel > 0) statoMotori(7,1),statoMotori(8,0),analogWrite(pwm4, vel);
    if(vel < 0) statoMotori(7,0),statoMotori(8,1),analogWrite(pwm4, -vel);
    break;
  }
}    
  
  /*
  SENZA SHIFT REGISTER


  if (motore > 3) return;

  if (motore == 0)  {
    if (vel == 0)  {
      digitalWrite(INA1,HIGH);
      digitalWrite(INB1,HIGH);
      analogWrite(PWM1, 255);
    }
    if (vel > 0)  {
      digitalWrite(INA1,HIGH);
      digitalWrite(INB1,LOW);
      analogWrite(PWM1, vel);
    }
    if (vel < 0)  {
      digitalWrite(INA1,LOW);
      digitalWrite(INB1,HIGH);
      analogWrite(PWM1, -vel);
    }
  }
  if (motore == 1)  {
    if (vel == 0)  {
      digitalWrite(INA2,HIGH);
      digitalWrite(INB2,HIGH);
      analogWrite(PWM2, 255);
    }
    if (vel > 0)  {
      digitalWrite(INA2,LOW);
      digitalWrite(INB2,HIGH);
      analogWrite(PWM2, vel);
    }
    if (vel < 0)  {
      digitalWrite(INA2,HIGH);
      digitalWrite(INB2,LOW);
      analogWrite(PWM2, -vel);
    }
  }          
  if (motore == 2)  {
    if (vel == 0)  {
      digitalWrite(INA3,HIGH);
      digitalWrite(INB3,HIGH);
      analogWrite(PWM3, 255);
    }
    if (vel > 0)  {
      digitalWrite(INA3,LOW);
      digitalWrite(INB3,HIGH);
      analogWrite(PWM3, vel);
    }
    if (vel < 0)  {
      digitalWrite(INA3,HIGH);
      digitalWrite(INB3,LOW);
      analogWrite(PWM3, -vel);
    }
  }          
  if (motore == 3)  {
    if (vel == 0)  {
      digitalWrite(INA4,HIGH);
      digitalWrite(INB4,HIGH);
      analogWrite(PWM4, 255);
    }
    if (vel > 0)  {
      digitalWrite(INA4,HIGH);
      digitalWrite(INB4,LOW);
      analogWrite(PWM4, vel);
    }
    if (vel < 0)  {
      digitalWrite(INA4,LOW);
      digitalWrite(INB4,HIGH);
      analogWrite(PWM4, -vel);
    }
  }
*/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// se è allineato ritorna 0 - se è storto a sinistra ritorna 1 -  se è storto a destra ritorna 2 - 
byte allineato(){
  int myg = gradiE;

  if(myg >= -10 || myg <= 10) return 0;
  if(myg > 10) return 1;
  if(myg < -10) return 2;
}


void riallinea()
{
  byte d;
  d = allineato();  
  if (d == 0)
  {
    moveRobot(fermo,0,0,0);
    return;  
  }
  if (d == 1)
  {
    moveRobot(ruotaSx, abs(gradiE)*2, 0, 0);
    return;  
  }
  if (d == 2)
  {
    moveRobot(ruotaDx, abs(gradiE)*2, 0, 0);
    return;  
  }

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void frena(int brake) // Brake motor 1, brake is a number between 0 and 400
{
  if (brake < 0)
  {
    brake = -brake;
  }
  if (brake > 255)  // Max brake
    brake = 255;

  analogWrite(pwm1,brake);
  analogWrite(pwm2,brake);
  analogWrite(pwm3,brake);
  analogWrite(pwm4,brake);

  statoMotori(0,0);
  statoMotori(1,0);
  statoMotori(2,0);
  statoMotori(3,0);
  statoMotori(4,0);
  statoMotori(5,0);
  statoMotori(6,0);
  statoMotori(7,0);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


