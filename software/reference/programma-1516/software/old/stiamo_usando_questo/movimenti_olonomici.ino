// verlocità = : positiva orario, negativa antiorario

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


void moveRobot(int angolo, int rotazione, int vel, boolean abilitaCorrezione){
  int wr,corre, grad;
  //float kw=0.65;
  //Serial.println("Lol");
  //if(vel>150)kw=1.2;
  
  int velZero, velUno, velDue, velTre;

  if (vel > 255) vel = 255;
  if (vel < -255) vel = -255;

  if(angolo == -1){ // fermo
    cmdMot(0,0);
    cmdMot(1,0);
    cmdMot(2,0);
    cmdMot(3,0);
  }
  else
  {
    //Serial.println("Get_in_Else");
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
      //Serial.println("Get_rotazione");
      componenti(angolo);
      vx = vx * vel;
      vy = vy * vel;

    }  
    else{
      //Serial.println("Get_rotazione_null");
      vx = 0;
      vy = 0;

    }
/*
    grad=gradi_norm();
    if(grad<=180)  {
      Serial.println("Get_wr=grad");
      wr = grad;
    }
    else {
      wr = grad-360;
    } */
    if(abilitaCorrezione)
    {
      bussola_getHeading();
      Input = gradiE;
      myPID.Compute();
      //Serial.println("Get_corre");
      corre = Output;
    }
    else {
      //Serial.println("Get_corre=null");
      corre =0;
    }
    //    Serial.print("corre = ");
    //    Serial.println(corre);
    velZero = ((0.866  * vx) + ( 0.5    * vy) + (rotazione + corre));   // valori nuovi
    velUno  = ((-0.866  * vx) + ( 0.5    * vy) + (rotazione + corre));
    velDue  = ((-0.7071 * vx) + (-0.7071 * vy) + (rotazione + corre));
    velTre  = ((0.7071 * vx) + (-0.7071 * vy) + (rotazione + corre));
    //Serial.println("Get_Vel");


    /*
    Serial.print(velZero);
     Serial.print("\t");
     Serial.print(velUno);
     Serial.print("\t");
     Serial.print(velDue);
     Serial.print("\t");
     Serial.print(velTre);
     Serial.println("\t");
     */
    individuaLinee();
    cmdMot(0,constrain(velZero, -255, 255));
    cmdMot(1,constrain(velUno,  -255, 255));
    cmdMot(2,constrain(velDue,  -255, 255));
    cmdMot(3,constrain(velTre,  -255, 255));
    //Serial.println("CmdMot");
    shiftRegister_sendBytes();
    //Serial.println("SendBytes");
    
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







