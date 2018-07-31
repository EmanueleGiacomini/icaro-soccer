String menu_main[] = {
  "Bussola","Motori","Sensori Palla","Sensori linea","Bluetooth","Ultrasuoni","Calcio"};
String menu_bussola[] = {
  "Calibrazione","Imposta Nord","Indietro"};
String menu_motori[] = {
  "Prova Motori","Calibra PID","Velocita'","Sforzo","Indietro"};
String menu_bluetooth[] = {
  "Cerca Dispositivi","Dispositivi Associati","Indietro"}; 
String menu_calcio[] = {
  "Tira Calcio","Forza Calcio","Indietro"}; 
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//////// LISTA MENU \ 0 PRINCIPALE \ 1 BUSSOLA \ 2 MOTORI \ 3 SENS.PALLA \ 4 SENS. LINEA
/////////////////// \ 5 BLUETOOTH  \ 6 ULTRASUONI \ 7 CALCIO //////////// 
void menu()
{

  while(1)
  {

    if(encoderPos >= maxEncoderPos) encoderPos = maxEncoderPos;
    if(encoderPos < 0) encoderPos = 0;
    switch(lvl)
    {
      /////////////////////////////////
      /////// MENU' PRINCIPALE ////////
    case 0 : 
      maxEncoderPos = 6;
      display.drawLine(0,15,128,15,WHITE);

      // LED E SIMBOLO BLUETOOTH
      display.drawLine(20, 3, 20, 13,(BLUE));
      display.drawPixel(19, 7, BLUE);
      display.drawPixel(19, 8, BLUE);
      display.drawPixel(18, 8, BLUE);
      display.drawPixel(18, 7, BLUE);
      display.drawPixel(17, 9, BLUE);
      display.drawPixel(17, 6, BLUE);
      display.drawPixel(16, 10, BLUE);
      display.drawPixel(16, 5, BLUE);
      display.drawPixel(21, 4, BLUE);
      display.drawPixel(22, 5, BLUE);
      display.drawPixel(23, 6, BLUE);
      display.drawPixel(22, 6, BLUE);
      display.drawPixel(21, 7, BLUE);
      display.drawPixel(21, 9, BLUE);
      display.drawPixel(22, 10, BLUE);
      display.drawPixel(23, 11, BLUE);
      display.drawPixel(22, 12, BLUE);
      display.drawPixel(21, 13, BLUE);   

      display.fillCircle(8,8,3,BLUE);

      display.drawRect(90,3,30,10,WHITE);
      display.fillRect(120,5,3,6,WHITE);
      display.fillRect(91,4,28,8,BLACK); // 28 MAX
      display.drawLine(0, 15, 128, 15,WHITE);
      double t;
      int s;
      t = analogRead(A0)/204.8;
      s = (t*3.6)+10;
      //Serial.println(s);
      if(t>3.5) display.fillRect(91,4,s,8,GREEN);
      if(t<3.5) display.fillRect(91,4,s,8,YELLOW);
      if(t<1.5) display.fillRect(91,4,s,8,RED);

      for(int pos = 0;pos < 7;pos++)
      {
        display.setTextSize(1);
        if(pos == encoderPos) display.setTextColor(RED,WHITE);
        else display.setTextColor(WHITE,BLACK);
        display.setCursor(0,pos*17+16);
        display.print(menu_main[pos]);
      }
      if(!digitalRead(sel))
      {  
        tone(6,4000,60);
        display.clearScreen();
        switch(encoderPos)
        {
        case 0:
          in = 0; ///// IMPOSTARE in = 0 per inizializzare i disegni nei menu'
          lvl = 1;
          break; 
        case 1:
          lvl = 2;
          break;
        case 2:
          lvl = 3;
          break; 
        case 3:
          lvl = 4;
          break;
        case 4:
          lvl = 5;
          break; 
        case 5:
          in = 0;
          lvl = 6;
          break;
        case 6:
          lvl = 7;
          break;
        } 
        encoderPos = 0;
      }              
      break;
      /////////////////////////////////
      /////// MENU' BUSSOLA //////////
    case 1:
      int lastlettura;
      // long attesa=4000,previousMillis;
      maxEncoderPos = 3;



      display.drawLine(0,15,128,15,WHITE);
      display.setTextSize(2);
      display.setTextColor(RED);
      display.setCursor(0,0);
      display.print("BUSSOLA");
      for(int pos = 0;pos < 3;pos++)
      {
        display.setTextSize(1);
        if(encoderPos == pos) display.setTextColor(RED,WHITE);
        else display.setTextColor(WHITE,BLACK);
        display.setCursor(0,pos*10+16); 
        display.print(menu_bussola[pos]);
      }
      creaBussola(90,70,20);
      agoBussola(89,70,19);
      if(lastlettura != leggiBussola(0)) display.fillRect(40,80,17,8,BLACK),display.fillRect(40,90,24,8,BLACK);

      display.setCursor(0,80); ///////////// GRADI /////////////
      display.setTextColor(WHITE);
      display.print("Gradi:");

      display.setCursor(40,80);
      display.print(leggiBussola(0));


      display.setCursor(0,90);
      display.print("Error:"); //////////// ERRORE /////////////

      display.setCursor(40,90);
      display.print(leggiBussola(1)); 

      lastlettura = leggiBussola(0);

      /*    display.setCursor(0,115); //////////// PID
            display.setTextColor(WHITE,RED);
            display.print("kP:");
            display.setCursor(45,115);
            display.print("kI:");
            display.setCursor(90,115);
            display.print("kD:");
       */


      if(!digitalRead(sel))
      {
        tone(6,4000,60);
        switch(encoderPos)
        {
        case 0: //////////// CALIBRA BUSSOLA ////////////
          calibraBussola();
          in = 0;
          break;
        case 1:
          {    
            //////////////////////////////////////////////////////////////////////
            ////////////////////////      SET V. NORD   //////////////////////////
            //////////////////////////////////////////////////////////////////////
            Vnord = leggiBussola(2);
            VnordE = leggiBussola(3);

            int byte0=Vnord&255;
            int byte1=(Vnord>>8)&255;
            EEPROM.write(storedValueOffset, byte0);
            EEPROM.write(storedValueOffset+1, byte1);
            delay(5);
            display.setCursor(80,26);
            display.setTextColor(GREEN);
            delay(100);
            display.print("Memoryzed!");
          }
          break;
        case 2: /////////// INDIETRO ///////////
          display.clearScreen();
          lvl = 0;
          break;

        }

        encoderPos = 0;
      }
      break;
      /////////////////////////////////
      /////// MENU' MOTORI ////////////
    case 2:
      {
        boolean prvMt,clbPID,clbVel;
        String consPID[] = {
          "kP","kI","kD"                        };
        float pidConst[] = {
          kP,kI,kD                        };

        int selezione;
        maxEncoderPos = 4;


        display.drawLine(0,15,128,15,WHITE);
        display.setTextSize(2);
        display.setTextColor(RED);
        display.setCursor(0,0);
        display.print("MOTORI");
        for(int pos = 0;pos < 5;pos++)
        {
          display.setTextSize(1);
          if(encoderPos == pos) display.setTextColor(RED,WHITE);
          else display.setTextColor(WHITE,BLACK);
          display.setCursor(0,pos*15+16);
          display.print(menu_motori[pos]);
        }

        if(!digitalRead(sel))
        {

          tone(6,4000,60);
          switch(encoderPos)
          {
          case 0: ////// PROVA MOTORI //////
            prvMt = 1;
            display.clearScreen();
            display.drawLine(0,15,128,15,WHITE);
            display.setTextSize(2);
            display.setTextColor(RED);
            display.setCursor(0,0);
            display.print("Movimenti");

            while(prvMt)
            {
              if(encoderPos > 10) encoderPos = 0;
              if(encoderPos < 0) encoderPos = 10; 
              for(int mov=0;mov < 11;mov++)
              {
                Serial.print(mov),Serial.print(" - "),Serial.println(encoderPos);

                if(mov >= 8)
                {
                  switch(mov)
                  {
                  case 8:
                    if(encoderPos == mov) display.fillRect(90,70,5,5,RED);
                    else display.fillRect(90,70,5,5,WHITE);
                    break;
                  case 9:
                    if(encoderPos == mov) display.fillRect(50,70,5,5,RED);
                    else display.fillRect(50,70,5,5,WHITE);
                    break;
                  case 10:
                    display.setCursor(0,16);
                    display.setTextSize(1);
                    if(encoderPos == mov) display.setTextColor(RED,WHITE);
                    else display.setTextColor(WHITE,BLACK);
                    display.print("Indietro");
                    break;              
                  }
                }
                if(mov < 8)
                {
                  float senM = sin(mov*0.7853);
                  float cosM = cos(mov*0.7853);
                  if(encoderPos == mov) display.fillRect(70+cosM*40,70+senM*40,5,5,RED);
                  else display.fillRect(70+cosM*40,70+senM*40,5,5,WHITE);   
                }
              }
              if(!digitalRead(sel))
              {
                tone(6,4000,60);
                switch(encoderPos)
                {
                case 0:
                  // DESTRA
                  moveRobot(destra,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 1:
                  // DIAG PostDx
                  moveRobot(diagonalePdx,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 2:
                  // INDIETRO
                  moveRobot(indietro,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 3:
                  // Diag PostSx
                  moveRobot(diagonalePsx,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 4:
                  // SINISTRA
                  moveRobot(sinistra,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 5:
                  // Diag AntSx
                  moveRobot(diagonaleAsx,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 6:
                  // AVANTI
                  moveRobot(avanti,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 7:
                  // Diag AntDx
                  moveRobot(diagonaleAdx,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 8:
                  // RUOTA DX
                  moveRobot(ruotaDx,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 9:
                  //RUOTA SX
                  moveRobot(ruotaSx,velM,0);
                  delay(2000);
                  moveRobot(fermo,0,0);
                  break;
                case 10:
                  prvMt = 0;
                  display.clearScreen();
                  lvl = 2;

                }
              }
            }


            break;
          case 1: ///////////// CALIBRA PID ///////////////////
            {
              display.clearScreen();
              clbPID = 1;
              delay(50);
              String menuPid[] = {
                "kP","kI","kD","STime","Salva Impostazioni","Indietro"                                          };
              display.clearScreen();
              display.drawLine(0,15,128,15,WHITE);
              display.setTextSize(2);
              display.setTextColor(RED);
              display.setCursor(0,0);
              display.print("PID");
              while(clbPID)
              {
                if(encoderPos < 0) encoderPos = 0;
                if(encoderPos > 5) encoderPos = 5;
                for(int pos=0;pos<6;pos++)
                {
                  display.setTextSize(1);
                  if(encoderPos == pos) display.setTextColor(RED,WHITE);
                  else display.setTextColor(WHITE,BLACK);
                  display.setCursor(0,pos*15+16);
                  display.print(menuPid[pos]);
                }
                if(!digitalRead(sel))
                {
                  switch(encoderPos)
                  {
                  case 0: // KP
                    {
                      delay(150);
                      float oldkP;
                      int setkP = 1;
                      while(setkP)
                      {
                        display.setCursor(64,16);
                        display.setTextColor(WHITE,RED);
                        kP = encoderPos*0.01;
                        if(kP < 0) kP = 0;
                        if(kP > 2.55) kP = 2.55;
                        display.print(kP);
                        if(kP != oldkP) display.fillRect(64,16,40,10,BLACK);
                        oldkP = kP;
                        if(!digitalRead(sel))encoderPos = 0,setkP = 0,delay(150);
                      }
                    }
                    break;
                  case 1: // KI
                    {
                      delay(150);
                      float oldkI;
                      int setkI = 1;
                      while(setkI)
                      {
                        display.setCursor(64,31);
                        display.setTextColor(WHITE,RED);
                        kI = encoderPos*0.01;
                        if(kI < 0) kI = 0;
                        if(kI > 2.55) kI = 2.55;
                        display.print(kI);
                        if(kI != oldkI) display.fillRect(64,31,40,10,BLACK);
                        oldkI = kI;
                        if(!digitalRead(sel))encoderPos = 1,setkI = 0,delay(150);
                      }
                    }
                    break;

                  case 2: // KD
                    {
                      delay(150);
                      float oldkD;
                      int setkD = 1;
                      while(setkD)
                      {
                        display.setCursor(64,46);
                        display.setTextColor(WHITE,RED);
                        kD = encoderPos*0.01;
                        if(kD < 0) kD = 0;
                        if(kD > 2.55) kD = 2.55;
                        display.print(kD);
                        if(kD != oldkD) display.fillRect(64,46,40,10,BLACK);
                        oldkD = kD;
                        if(!digitalRead(sel))encoderPos = 2,setkD = 0,delay(150);
                      }
                    }
                    break;

                  case 3: // SampleTime
                    ///// IMPOSTARE EEPROM

                    break;

                  case 4: // Salva Impostazioni
                    ////// SALVARE TUTTE LE IMPOSTAZIONI SU EEPROM
                    break;

                  case 5: // Indietro
                    clbPID = 0;
                    display.clearScreen();
                    lvl = 2;
                    break;

                  }

                }

                float pidConst[] = {
                  kP,kI,kD                };
                Serial.println(kP);
                for(int pos = 0;pos <= 2;pos++)
                {
                  display.setTextSize(1);
                  display.setCursor(pos*40,110);
                  if(pos == selezione) display.setTextColor(RED,WHITE);
                  else display.setTextColor(WHITE,RED);
                  display.print(consPID[pos]);
                  display.setCursor(pos*40+13,110);
                  display.setTextColor(WHITE);
                  display.print(pidConst[pos]);
                  delay(15);
                  display.fillRect(pos*40+13,110,24,19,BLACK);


                }
                if(!digitalRead(sel)) tone(6,5000,60),selezione ++,encoderPos = 0,delay(150);
                if(selezione > 2)
                {
                  clbPID = 0;
                  display.fillRect(0,109,128,19,BLACK);
                  /////// SALVARE SU EEPROM LE MODIFICHE CONST.PID ///////////
                }

                switch(selezione) 
                {
                case 0:
                  kP = encoderPos*0.01;
                  if(kP < 0.00) kP = 0.00;
                  break;
                case 1:
                  kI = encoderPos*0.01;
                  if(kI < 0.00) kI = 0.00;
                  break;
                case 2:
                  kD = encoderPos*0.01;
                  if(kD < 0.00) kD = 0.00;
                  break;

                } 

              }
            }
            break;
          case 2: ////////////// VELOCITA ///////////////
            clbVel=1;
            delay(150);
            while(clbVel)
            {
              int oldVel;
              display.setCursor(70,46);



              display.setTextColor(WHITE);
              Vel = encoderPos*5;
              if(Vel < 0) Vel = 0;
              if(Vel > 255) Vel = 255;
              display.print(Vel);
              if(Vel != oldVel) display.fillRect(70,46,40,20,BLACK);
              oldVel = Vel;

              if(!digitalRead(sel)) tone(6,5000,60),display.fillRect(70,46,40,20,BLACK),clbVel=0,delay(150);
            }
            break;
          case 3:
            break;
          case 4:
            display.clearScreen();
            lvl = 0;
            break;
          }
          encoderPos = 0; 
        }
      }///// FINE MENU MOTORI
      break;
      /////////////////////////////////
      /////// MENU' SENSORI PALLA /////
    case 3:
      maxEncoderPos = 0;
      display.drawLine(0,15,128,15,WHITE);
      display.setTextSize(2);
      display.setTextColor(RED);

      display.setCursor(0,0);
      display.print("SENS PALLA");

      display.setTextSize(1);
      display.setCursor(0,16);
      display.setTextColor(RED,WHITE);
      display.print("Indietro");

      for(int sensorePalla = 0;sensorePalla<12;sensorePalla++)
      {
        float sinS,cosS;
        sinS = sin(sensorePalla*0.523);
        cosS = cos(sensorePalla*0.523);
        
        ////// AGGIUNGERE SCAN SENSORI PALLA ////////

        switch(sensorePalla)
        {
        case 0:
          if(sensorePalla == 0)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        case 1:
          if(sensorePalla == 1)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        case 2:
          if(sensorePalla == 2)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        case 3:
          if(sensorePalla == 3)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        case 4:
          if(sensorePalla == 4)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        case 5:
          if(sensorePalla == 5)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        case 6:
          if(sensorePalla == 6)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        case 7:
          if(sensorePalla == 7)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        case 8:
          if(sensorePalla == 8)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        case 9:
          if(sensorePalla == 9)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED); 
        case 10:
          if(sensorePalla == 10)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);        
        case 11:
          if(sensorePalla == 11)display.fillRect(80+cosS*30,75+sinS*30,3,5,WHITE);
          else display.fillRect(80+cosS*30,75+sinS*30,3,5,RED);
        }
      }
      display.fillRect(0,90,40,40,BLACK);
      delay(2);
      display.setCursor(0,90);
      display.setTextSize(3);
      display.setTextColor(RED);
      display.print(sensorePalla);
      if(!digitalRead(sel)) tone(6,4000,60),display.clearScreen(),lvl = 0;
      return;

      break;
      /////////////////////////////////
      /////// MENU' SENSORI LINEA /////
    case 4:
      maxEncoderPos = 0;
      display.drawLine(0,15,128,15,WHITE);
      display.setTextSize(2);
      display.setTextColor(RED);
      display.setCursor(0,0);
      display.print("SENS LINEA");

      for(int pos = 0;pos < 4;pos++)
      {
        int frnt = pos % 2;
        float sinL,cosL;
        sinL = sin(pos*1.57);
        cosL = cos(pos*1.57);
        if(frnt) display.fillRect(95+cosL*25,75+sinL*25,3,5,WHITE),display.fillRect(65+cosL*25,75+sinL*25,3,5,WHITE);
        else display.fillRect(80+cosL*25,75+sinL*25,3,5,WHITE);

      }
      display.setCursor(0,16);
      display.setTextSize(1);
      if(!encoderPos) display.setTextColor(RED,WHITE);
      else display.setTextColor(WHITE,BLACK);
      display.print("Indietro");
      delay(150);
      if(!digitalRead(sel))
      {
        display.clearScreen();
        lvl = 0;
      }
      break;

    case 5:
      display.drawLine(0,15,128,15,WHITE);
      display.setTextSize(2);
      display.setTextColor(RED);
      display.setCursor(0,0);
      display.print("BLUETOOTH");    

      if(encoderPos < 0) encoderPos = 0;
      if(encoderPos > 3) encoderPos = 3;
      for(int pos = 0;pos < 3;pos++)
      {
        display.setTextSize(1);
        if(encoderPos == pos) display.setTextColor(RED,WHITE);
        else display.setTextColor(WHITE,BLACK);
        display.setCursor(0,pos*17+16); 
        display.print(menu_bluetooth[pos]);
      }

      if(!digitalRead(sel))
      {
        tone(6,4000,60);
        switch(encoderPos)
        {
        case 0://ricerca dispositivi

          break;
        case 1://dispositivi associati

          break;
        case 2://indietro
          display.clearScreen();
          lvl = 0;
          break;
        }      
      }
      if(!digitalRead(sel))
      {
        display.clearScreen();
        lvl = 0;
      }
      break;

    case 6:
    /////////////////////////////////////////////
    //////////////////Ultrasuoni/////////////////
    /////////////////////////////////////////////
      maxEncoderPos=0;
      display.drawLine(0,15,128,15,WHITE);
      display.setTextSize(2);
      display.setTextColor(RED);
      display.setCursor(0,0);
      display.print("ULTRASUONI");

      display.setCursor(0,16);
      display.setTextSize(1);
      if(!encoderPos) display.setTextColor(RED,WHITE);
      else display.setTextColor(WHITE,BLACK);
      display.print("Indietro");
      
     ///////////////Richiama funzione dal sotto///////////////

      display.fillRect(35,112,17,9,BLACK);
      delay(10);
      display.setCursor(0,112);
      display.setTextSize(1);
      display.setTextColor(BLUE);
      display.println("US1 = ");
//      display.setCursor(35,112);
//      display.setTextColor(BLUE);
//      display.print(analogRead(Us1));
      delay(10);

      display.fillRect(35,120,17,9,BLACK);
      delay(10);
      display.setCursor(0,120);
      display.setTextColor(BLUE);
      display.setTextSize(1);
      display.println("US2 = ");
//      display.setCursor(35,120);
//      display.setTextColor(BLUE);
//      display.print(analogRead(Us2));
      delay(10);
      
      display.fillRect(109,112,17,9,BLACK);
      delay(10);    
      display.setCursor(64,112);
      display.setTextColor(BLUE);
      display.println("US3 = ");
//      display.setCursor(109,112);
//      display.setTextColor(BLUE);
//      display.print(analogRead(Us3));
      delay(10);

      display.fillRect(109,120,17,9,BLACK);
      delay(10);
      display.setCursor(64,120);
      display.setTextColor(BLUE);
      display.println("US4 = ");
//      display.setCursor(109,120);
//      display.setTextColor(BLUE);
//      display.print(analogRead(Us4));
      delay(10);

      campo();
      in=0;

      /* 
       int posX,posY;
       posX = ((lettura USsx * 128)/243)-distanza centro robot, sensore US 
       posY = ((lettura USax * 128)/243)-distanza centro robot, sensore US
       ? verifica posizione con sensori px e dx ?
       display.fillCircle(posX, posY, 5, BLACK);//robot
       */

      if(!digitalRead(sel))
      {
        display.clearScreen();
        lvl = 0;
      }
      break;

    case 7:
      int clbtime;
      int Oldtime;
      display.drawLine(0,15,128,15,WHITE);
      display.setTextSize(2);
      display.setTextColor(RED);
      display.setCursor(0,0);
      display.print("CALCIO");

      if(encoderPos < 0) encoderPos = 0;
      if(encoderPos > 3) encoderPos = 3;
      for(int pos = 0;pos < 3;pos++)
      {
        display.setTextSize(1);
        if(encoderPos == pos) display.setTextColor(RED,WHITE);
        else display.setTextColor(WHITE,BLACK);
        display.setCursor(0,pos*17+16); 
        display.print(menu_calcio[pos]);
      }

      if(!digitalRead(sel))
      {
        tone(6,4000,60);
        switch(encoderPos)
        {
        case 0://tira calcio
        if(!digitalRead(sel))
        {
         tone(6,4000,60);
         digitalWrite(calcio, LOW);
         delay(Oldtime);
         digitalWrite(calcio, HIGH);
        }
        display.clearScreen();
        lvl = 7;
         break;
        case 1://forza calcio
            clbtime=1;
            delay(150);
            while(clbtime)
            {
              display.setCursor(100,35);
              display.setTextColor(WHITE);
              time = encoderPos*1;
              if(time < 0) time = 0;
              if(time > 100) time = 100;
              display.print(time);
              if(time != Oldtime) display.fillRect(100,35,40,20,BLACK);
              Oldtime = time;

              if(!digitalRead(sel))
              {
              tone(6,5000,60);
              display.fillRect(100,35,40,20,BLACK);
              display.setCursor(100,50);
              display.setTextColor(WHITE);
              display.print(Oldtime);              
              clbtime=0;
              delay(400);
               display.clearScreen();
              lvl = 7;
              }
            }

          break;
        case 2://indietro
          display.clearScreen();
          lvl = 0;
          break;
        }      
      }

      if(!digitalRead(sel))
      {
        display.clearScreen();
        lvl = 0;
      }
      break;   
    } //// SWITCH(LVL)
  } //// WHILE(1)
} /// VOID MENU
