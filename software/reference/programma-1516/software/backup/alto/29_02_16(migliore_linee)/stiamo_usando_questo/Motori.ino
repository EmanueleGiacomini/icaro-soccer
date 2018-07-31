
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
      shiftRegister_sendBytes();

}    


void riallinea()
{
  moveRobot(-2,1,vel,1);
}


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

////////////////////////////////////////////////////////////////////////////
//  | v1 |      | -sin(angoloMotore)  cos(angoloMotore)  1 |   | vx |     //
//  | v2 |      | -sin(angoloMotore)  cos(angoloMotore)  1 |   | vy |     //
//  | v3 |   =  | -sin(angoloMotore)  cos(angoloMotore)  1 | * | Rw |     //
//  | v4 |      | -sin(angoloMotore)  cos(angoloMotore)  1 |              // 
///////////////////////////////////// ///////////////////////////////////////
//                                                                        //
//     M0 =  0.7071   0.071                                               //
//     M1 = -0.7071   0.071                                               //
//     M2 = -0.7071  -0.071                                               //
//     M3 =  0.7071  -0.071                                               // 
//                                                                        // 
////////////////////////////////////////////////////////////////////////////


void moveRobot(int angolo, int rotazione, int vel, boolean abilitaCorrezione)
{
  volatile int corre;
  volatile int velZero, velUno, velDue, velTre;

  // LIMITE DI VELOCITA'
  if (vel > 255) vel = 255;
  if (vel < -255) vel = -255;

  if(angolo == -1)// fermo
  { 
    cmdMot(0,0);
    cmdMot(1,0);
    cmdMot(2,0);
    cmdMot(3,0);
  }
  else
  {
    if(angolo == -2)// sx
    {} 
    else if(angolo == -3) // dx
    { 
      angolo = 0;
      rotazione = -rotazione;
    }

    if(rotazione == 0)
    {
      componenti(angolo);
      vx = vx * vel;
      vy = vy * vel;
    }  

    else
    {
      vx = 0;
      vy = 0;
    }

    if(abilitaCorrezione)
    {
      
      bussola_getHeading();
      Input = gradiE;
      myPID.Compute();
      corre = Output;
    }
    else
    {
      corre = 0;
    }

    velZero = ((0.866  * vx) + ( 0.5    * vy) + (rotazione + corre));   // valori nuovi
    velUno  = ((-0.866  * vx) + ( 0.5    * vy) + (rotazione + corre));
    velDue  = ((-0.7071 * vx) + (-0.7071 * vy) + (rotazione + corre));
    velTre  = ((0.7071 * vx) + (-0.7071 * vy) + (rotazione + corre));

    cmdMot(0,constrain(velZero, -255, 255));
    cmdMot(1,constrain(velUno,  -255, 255));
    cmdMot(2,constrain(velDue,  -255, 255));
    cmdMot(3,constrain(velTre,  -255, 255));

  if(!stoCorreggendo && rileva_linee)
    {
      individuaLinee();
    }// if(!stoCorreggendo)

  } // else
}// void moveRobot(int angolo, int rotazione, int vel, boolean abilitaCorrezione)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void componenti(int angolo){
  //float angoloRad = angolo * rad;
  vx = cos((angolo * pi / 180));
  vy = sin((angolo * pi / 180));  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




