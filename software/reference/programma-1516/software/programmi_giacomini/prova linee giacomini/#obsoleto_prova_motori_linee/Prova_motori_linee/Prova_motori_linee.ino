// Prova_motori_linee.ino
// Pin Motori
const int PWM1 = 11, PWM2 = 10, PWM3 = 6, PWM4 = 3;   //PWM Motori
const int INA1 = 13, INB1 = 12, INB2 = 9, INA2 = 8, INA3 = 7, INB3 = 5,INB4 = 4,INA4 = 2; //Dir Motori
int arraySetupMot[] = {PWM1,PWM2,PWM3,PWM4,INB1,INB2,INB3,INB4,INA1,INA2,INA3,INA4};
double vx, vy, rw;
// Pin Linee
const int  LineaDx = 30, LineaCx = 31, LineaSx = 32; // Pin centrali Linee

int a = 0;

void setup() 
{
	pinMode(INA1,OUTPUT);
 	pinMode(INB1,OUTPUT);	
  	pinMode(PWM1,OUTPUT);
  	pinMode(INA2,OUTPUT);
 	pinMode(INB2,OUTPUT);	
  	pinMode(PWM2,OUTPUT);
  	pinMode(INA3,OUTPUT);
 	pinMode(INB3,OUTPUT);	
  	pinMode(PWM3,OUTPUT);
  	pinMode(INA4,OUTPUT);
 	pinMode(INB4,OUTPUT);	
  	pinMode(PWM4,OUTPUT);

	pinMode(LineaDx,INPUT);
	pinMode(LineaCx,INPUT);
	pinMode(LineaSx,INPUT);
        
        Serial.begin(9600);

}

void loop() 
{

while(!a)
{
	moveRobot(90,0,150,0);
	if(digitalRead(LineaDx) || digitalRead(LineaSx)) a = 1;
}
moveRobot(180,0,100,0);
delay(500);
a = 0;


}

// verlocità = : positiva orario, negativa antiorario

////////////////////////////////////////////////////////////////////////////
//  | v1 |      | -sin(angoloMotore)  cos(angoloMotore)  1 |   | vx |     //
//  | v2 |      | -sin(angoloMotore)  cos(angoloMotore)  1 |   | vy |     //
//  | v3 |   =  | -sin(angoloMotore)  cos(angoloMotore)  1 | * | Rw |     //
//  | v4 |      | -sin(angoloMotore)  cos(angoloMotore)  1 |              // 
////////////////////////////////////////////////////////////////////////////
//                                                                        //
//     M0 =  0.7071   0.071                                               //
//     M1 = -0.7071   0.071                                               //
//     M2 = -0.7071  -0.071                                               //
//     M3 =  0.7071  -0.071                                               // 
//                                                                        // 
////////////////////////////////////////////////////////////////////////////


void moveRobot(int angolo, int rotazione, int vel, boolean abilitaCorrezione){
  int wr,corre, grad;
  float kw=0.65;

  if(vel>150)kw=1.2;

  int velZero, velUno, velDue, velTre;

  if (vel > 255) vel = 255;
  if (vel < -255) vel = -255;

  if(angolo == -1){ // fermo
    cmdMot(0,0);
    cmdMot(1,0);
    cmdMot(2,0);
    cmdMot(3,0);
  }
  else{

    if(angolo == -2){  // sx
    } 
    else if(angolo == -3){  // dx
      angolo = 0;
      rotazione = -rotazione;
    }

    /*    Serial.print(vx);
     Serial.print("\t");
     Serial.println(vy);
     */
    if(rotazione == 0){

      componenti(angolo);
      vx = vx * vel;
      vy = vy * vel;

    }  
    else{

      vx = 0;
      vy = 0;

    }

    //grad=gradi_norm();
    if(grad<=180)  {
      wr = grad;
    }
    else {
      wr = grad-360;
    }
    if(abilitaCorrezione)
    {
      corre = wr*kw;
    }
    else {
      corre =0;
    }
    //    Serial.print("corre = ");
    //    Serial.println(corre);
    velZero = ((-0.7071 * vx) + ( 0.7071 * vy) + (rotazione + corre));
    velUno  = (( 0.7071 * vx) + ( 0.7071 * vy) + (rotazione + corre));
    velDue  = (( 0.7071 * vx) + ( 0.7071 * vy) + (rotazione + corre));
    velTre  = ((-0.7071 * vx) + ( 0.7071 * vy) + (rotazione + corre));


    
    Serial.print(velZero);
     Serial.print("\t");
     Serial.print(velUno);
     Serial.print("\t");
     Serial.print(velDue);
     Serial.print("\t");
     Serial.print(velTre);
     Serial.println("\t");
    
    cmdMot(0,constrain(velZero, -255, 255));
    cmdMot(1,constrain(velUno,  -255, 255));
    cmdMot(2,constrain(velDue,  -255, 255));
    cmdMot(3,constrain(velTre,  -255, 255));
  }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void componenti(int angolo){
  //float angoloRad = angolo * rad;
  vx = cos((angolo * PI / 180));
  vy = sin((angolo * PI / 180));  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  cmdMot
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

void cmdMot(byte motore,int vel){    // motore : 0 - 3
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

}
