/*
  Line finder rev 3 by Giacomini:
  lo scopo del programma è riuscire ad individuare una traiettoria di fuga dalla linea, dati n-sensori attivati.
  il sistema adoperato da questa versione sfrutta le proprietà della somma dei vettori per individuare la traiettoria, dato almeno 1 sensore.

  prendiamo per ipotesi il sensore 0 (ovvero il sensore piazzato a 80°)
  considerandolo come vettore chiamato V.
  tale vettore avrà cordinate V(Vx;Vy) dove Vx = Vcos(a) e Vy = Vsin(a)
  da cui si possono ricavare:
  V = sqrt(Vx^2 + Vy^2)
  o tg(a) = Vy/Vx

  Prendo il sensore 1 (100°)
  e faccio lo stesso lavoro.
  U(Ux;Uy) dove Ux = Ucos(b) e Uy = Usin(b)

  Magic happens here !
  sfruttando la proprietà della somma dei vettori
  creo un vettore fittizio A = V + U
  con coordinate A(Ax;Ay) dove Ax = Vx+Ux e Ay = Vy+Uy

  per la proprietà prima indicata ricavo

  tg(c) = (Vy+Uy)/(Vx+Ux)

  se svolgo l'arcotangente su tg(c) mi ricavo c, ovvero l'angolo di incidenza della linea rispetto al robot, sommando infine 180 al risultato, ottengo la traiettoria di fuga.

  differentemente dal programma del rev2 che poteva funzionare solo con 4 sensori disposti a coppie di 2,
  il rev3 può raccogliere un numero ipoteticamente infinito di vettori e ricavare la traiettoria di fuga.
  (DA SPERIMENTARE)
  Il problema di differenziare l'incidenza anteriore e posteriore è risolta.



  // La nuova configurazione attiva il sensore anteriore
  // e sfrutta il sensore posteriore centrale come secondo centrale

  int linee[] = {2, 3, 31, 26, 24, 27, 14, 15, 16, 33};
  /*
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
//int gradi_Linee[] = {80, 100, 35, 170, 190, 180, 260, 280, 325};
// lineFinder.rev3 usa il grado d'arco ma i radianti dato che
// la libreria math.h di Arduino usa proprio i radianti.
/*
  double gradi_Linee[] = {1.3963,1.7453,0.610865,2.9671,3.3161,3.14159,4.5379,4.8869,5.67232};
  float X = 0,Y = 0;
  //lineaMillis salva ogni quanto è stata attuata la funzione della linea
  //correzioneMillis salva ogni quanto è stata corretta la traiettoria
  unsigned long lineaMillis = 0, correzioneMillis = 0;
  // intervalloLinea indica dopo quanti ms và riattivata la funzione di linea
  // intervalloCorr indica per quanto tempo il robot corregge la traiettoria
  int intervalloLinea = 500,intervalloCorr = 500;
  byte nSens = 0; // quanti sensori hanno visto la linea
  // Ho deciso di usare massimo 6 sensori per rilevare la linea
  // Il valore 90 è random per non interferire col programma
  int sensoriTrovati[6] = {90,90,90,90,90,90};
  volatile int direzioneCorrezione;
  unsigned long sommaGradi = 0, sommaGradiCorr;
  boolean stoCorreggendo = 0;
*/

/*
  #define Babbonatale

  #ifdef Babbonatale
  istruzioni
  #endif
*/






/*
  .oooo.       .ooo
  .dP""Y88b    .88'
      ]8P'  d88'
    <88b.  d888P"Ybo.
     `88b. Y88[   ]88
  o.   .88P  `Y88   88P
  `8bd88P'    `88bod8'

  Questo programma permetterà di leggere e calibrare i 36 sensori di linea del robot
  Crazy right ?!
*/



void individuaLinee()
{

  if (!stoCorreggendo)
  {
    for (int lettura = 0; lettura < 12; lettura++)
    {
      intToBin(lettura);
      //Serial.print(lettura);
      //Serial.print(" - ");
      for (int nMux = 0; nMux < 3; nMux++)
      {
        //Serial.print(nMux);
        //Serial.print(" - ");
        if (lineaRilevata(nMux, lettura))
        {
          byte checkArray = 0;
          for (int i = 0; i < 24; i++)
          {
            if (lettura + (nMux * 12) != sensoriTrovati[i])checkArray++;
            //Serial.println(checkArray);
          }// for(int i=0;i<24;i++)
          if (checkArray == 24)
          {
            X = cos_Linee[lettura + (12 * nMux)];
            Y = sin_Linee[lettura + (12 * nMux)];
            sensoriTrovati[nSens] = lettura + (nMux * 12);
            nSens++;
            if (nSens > 4) {
              stoCorreggendo = 1;
              correzionePrimaria = double((atan2(Y, X) * 180 / 3.14159265) + 180);
              if (correzionePrimaria < 0) correzionePrimaria += 360;
              correzionePrimariaAbilitata = true;
              dirNeg = correzionePrimaria -= 80;
              dirPos = correzionePrimaria += 80;
            }
            Serial.println(nSens);
          }// if(checkArray==24)
        }// if(lineaRilevata(nMux,lettura))
      }// for(int nMux=0;nMux<3;nMux++)
    }// for(int lettura=0;lettura<12;lettura++)
  }// if(!stoCorreggendo)
  if (stoCorreggendo)
  {
    currentMillis = millis();
    correzioneMillis = millis();
    while ((currentMillis - correzioneMillis < TEMPO_FUGA) && stoCorreggendo)
    {
      currentMillis = millis();
      direzioneCorrezione = double((atan2(Y, X) * 180 / 3.14159265) + 180);


      if (correzionePrimariaAbilitata) {
        //if (dirNeg < 0) dirNeg += 360;
        //if (dirPos > 360) dirPos -= 360;
        if (direzioneCorrezione < 0) direzioneCorrezione = direzioneCorrezione + 360;

        if (direzioneCorrezione < dirNeg && direzioneCorrezione > dirPos)
          direzioneCorrezione = correzionePrimaria;
      }


      moveRobot(direzioneCorrezione, 0, VELOCITA_FUGA_LINEA, 1);
      Serial.print("X= "), Serial.print(X), Serial.print("  Y= "), Serial.print(Y), Serial.print("  Dir= "), Serial.println(direzioneCorrezione);

      for (int lettura = 0; lettura < 12; lettura++)
      {
        intToBin(lettura);
        //Serial.print(lettura);
        //Serial.print(" - ");
        for (int nMux = 0; nMux < 3; nMux++)
        {
          //Serial.print(nMux);
          //Serial.print(" - ");
          if (lineaRilevata(nMux, lettura))
          {
            byte checkArray = 0;
            for (int i = 0; i < 24; i++)
            {
              if (lettura + (nMux * 12) != sensoriTrovati[i])checkArray++;
              //Serial.println(checkArray);
            }// for(int i=0;i<24;i++)
            if (checkArray == 24 && nSens < 24)
            {
              X = cos_Linee[lettura + (12 * nMux)];
              Y = sin_Linee[lettura + (12 * nMux)];
              sensoriTrovati[nSens] = lettura + (nMux * 12);
              nSens++;
              correzioneMillis = millis();
            }// if(checkArray==24)
          }// if(lineaRilevata(nMux,lettura))
        }// for(int nMux=0;nMux<3;nMux++)
      }// for(int lettura=0;lettura<12;lettura++)
    }// while(currentMillis- correzioneMillis < TEMPO_FUGA && stoCorreggendo)
    lineeSetup();
  }// if(stoCorreggendo)
  oldDirMax = direzioneCorrezione + 90;
  if (oldDirMax > 360) oldDirMax = oldDirMax - 360;
  oldDirMin = direzioneCorrezione - 90;
  if (oldDirMin < 0) oldDirMin = oldDirMin + 360;

}// individuaLinee()



/*
  tone(25,4000);
  if(!stoCorreggendo)
  {
    for(int lettura=0;lettura < 12;lettura++)
    {
      intToBin(lettura);
      readMux(lettura);
      readMux2(lettura);
      readMux3(lettura);
      if(nSens > 0) stoCorreggendo = 1;
    }// for(int lettura=0;lettura < 36;lettura++)
    noTone(25);
    currentMillis = millis();
  }// if(!stoCorreggendo)
  else
  {
    currentMillis = millis();
    correzioneMillis = millis();
    //Serial.print("Wot");
    while(stoCorreggendo && (currentMillis - correzioneMillis <= TEMPO_FUGA))
    {
      currentMillis = millis();
      direzioneCorrezione = double((atan2(Y,X)*180/3.14159265)+180);
      Serial.println(direzioneCorrezione);
      moveRobot(direzioneCorrezione,0,VELOCITA_FUGA_LINEA,1);
      for(int lettura=0;lettura < 12;lettura++)
      {
        intToBin(lettura);
        readMux(lettura);
        readMux2(lettura);
        readMux3(lettura);

      }// for(int lettura=0;lettura < 36;lettura++)
    }// while(stoCorreggendo && (currentMillis - correzioneMillis <= TEMPO_FUGA))
    tone(25,6000);
    delay(20);
    noTone(25);
    lineeSetup();
    }// else
    delay(10);
    noTone(25);
*/
//}// void individuaLinee()



void leggiLinee()
{
  volatile int valoreSens[36];

  for (int lettura = 0; lettura < 12; lettura++)
  {
    intToBin(lettura);
    valoreSens[lettura] = analogRead(MUXOUT_1);
    valoreSens[lettura + 12] = analogRead(MUXOUT_2);
    valoreSens[lettura + 24] = analogRead(MUXOUT_3);
  }
  for (int lettura = 0; lettura < 36; lettura++)
  {
    if (lettura != 35)
    {
      Serial.print(valoreSens[lettura]), Serial.print(" "), Serial.print(lettura + 1), Serial.print(" ");
    }
    else Serial.println(valoreSens[lettura]);
  }

}

// Per calibrare le linee, si passerà

void calibraLinee()
{

  int valoreSens[36];
  int valMax[36];
  int valMin[36];
  for (int x = 0; x < 36; x++)
  {
    valMax[x] = 0;
    valMin[x] = 1024;
  }


  currentMillis = millis();
  calibraLineeMillis = millis();

  moveRobot(-2, 50, 40, 0);
  while (currentMillis - calibraLineeMillis < INTERVALLO_CALIBRA_LINEE)
  {
    currentMillis = millis();
    for (int lettura = 0; lettura < 12; lettura++)
    {
      intToBin(lettura);
      valoreSens[lettura] = analogRead(MUXOUT_1);
      valoreSens[lettura + 12] = analogRead(MUXOUT_2);
      valoreSens[lettura + 24] = analogRead(MUXOUT_3);
    }
    for (int lettura = 0; lettura < 36; lettura++)
    {
      if (valoreSens[lettura] < valMin[lettura]) valMin[lettura] = valoreSens[lettura];
      if (valoreSens[lettura] > valMax[lettura]) valMax[lettura] = valoreSens[lettura];
    }

  }// while(currentMillis - calibraLineeMillis < INTERVALLO_CALIBRA_LINEE)
  moveRobot(-1, 0, 0, 0);
  tone(25, 2000);
  delay(20);
  noTone(25);
  for (int lettura = 0; lettura < 36; lettura++)
  {
    soglia_Linee[lettura] = valMin[lettura] + 20;
    if (lettura != 35) Serial.print(soglia_Linee[lettura]), Serial.print("-\t");
    else Serial.println(soglia_Linee[lettura]);
  }

  Serial.println("Saving on EEPROM");
  for (int i = 0; i < 36; i++)
  {
    EEPROM.write(i, (soglia_Linee[i] >> 8) & 255);
    EEPROM.write(i + 36, (soglia_Linee[i]) & 255);
    delay(10);
  }
  Serial.println("EEPROM Set");


  /*
    for(int lettura=0;lettura<36;lettura++)
    {
    if(lettura != 35) Serial.print(valMin[lettura]),Serial.print("-\t");
    else Serial.println(valMin[lettura]);
    }
    for(int lettura=0;lettura<36;lettura++)
    {
    if(lettura != 35) Serial.print(valMax[lettura]),Serial.print("-\t");
    else Serial.println(valMax[lettura]);
    }*/
  stoCorreggendo = 0;
  // Ciclo di lettura verde - bianco



}


void readSoglie()
{
  byte letturaByteHigh = 0;
  byte letturaByteLow = 0;
  for (int i = 0; i <= 35; i++)
  {
    letturaByteHigh = EEPROM.read(i);
    letturaByteLow  = EEPROM.read(i + 36);
    soglia_Linee[i] = letturaByteHigh << 8 | letturaByteLow;
    Serial.print(soglia_Linee[i]);
    Serial.print(" - ");
  }
}






bool lineaRilevata(byte nMux, int lettura)
{
  int nPin;
  switch (nMux)
  {
    case 0:
      nPin = MUXOUT_1;
      break;
    case 1:
      nPin = MUXOUT_2;
      break;
    case 2:
      nPin = MUXOUT_3;
      break;
  }

  if (analogRead(nPin) < soglia_Linee[lettura + (nMux * 12)]) {
    ultimaLineaPresa = millis();
    return 1;
  }

  else return 0;
}










void lineeSetup()
{
  for (int in = 0; in <= 24; in++)
  {
    sensoriTrovati[in] = 90;
  }
  stoCorreggendo = 0;
  nSens = 0;
  //tone(25,6000,20);
  //delay(20);
  //noTone(25);
  X = 0;
  Y = 0;
}// void linee.setup()


// Multiplexer Selection function
void intToBin(byte var)
{
  int pos = bin[var];
  a = bitRead(pos, 0);
  b = bitRead(pos, 1);
  c = bitRead(pos, 2);
  d = bitRead(pos, 3);

  digitalWrite(MUX_D, d);
  digitalWrite(MUX_C, c);
  digitalWrite(MUX_B, b);
  digitalWrite(MUX_A, a);
}


// Ogni multiplexer contiene 12 sensori ( da 0 a 11)
/*
  void readMux(byte reading)
  {
  byte lettureDiverse = 0;
  // tramite questo for controllo se ho già visto prima la lettura attuale
  for(byte confrontaSensori=0;confrontaSensori<24;confrontaSensori++)
  {
    if(reading != sensoriTrovati[confrontaSensori]) lettureDiverse++;
    // Se non ho mai visto la lettura attuale, lettureDiverse sarà uguale a 24, altrimenti ho già visto la lettura

  }// for(byte confrontaSensori=0;confrontaSensori<=24;confrontaSensori++)
  //Serial.println(lettureDiverse);

  if(lettureDiverse == 24)
  {
    if(analogRead(MUXOUT_1)<= soglia_Linee[reading])// soglia_Linee[reading]
    {
      tone(25,4000,20);
      sensoriTrovati[nSens] = reading;
      X += cos(gradi_Linee[reading]);
      Y += sin(gradi_Linee[reading]);
      nSens++;
      if(nSens > 24) nSens = 24;
      //Serial.println(reading+1);
      correzioneMillis = millis();
    }// if(analogRead(MUXOUT_1)<= soglia_Linee[reading])
  }// if(lettureDiverse == 24)
  }// void readMux(byte reading)

  void readMux2(byte reading)
  {
  byte lettureDiverse = 0;

  for(byte confrontaSensori=0;confrontaSensori<24;confrontaSensori++)
  {
    if(reading+12 != sensoriTrovati[confrontaSensori]) lettureDiverse++;

  }// for(byte confrontaSensori=0;confrontaSensori<=24;confrontaSensori++)

  if(lettureDiverse == 24)
  {
    if(analogRead(MUXOUT_2)<= soglia_Linee[reading+12])//soglia_Linee[reading+12]
    {
      tone(25,6000,20);
      sensoriTrovati[nSens] = reading+12;
      X += cos(gradi_Linee[reading+12]);
      Y += sin(gradi_Linee[reading+12]);
      nSens++;
      if(nSens > 24) nSens = 24;
      //Serial.println(reading+13);
      correzioneMillis = millis();
    }// if(analogRead(MUXOUT_2)<= soglia_Linee[reading+12])
  }// if(lettureDiverse == 24)
  }// void readMux2(byte reading)

  void readMux3(byte reading)
  {
  byte lettureDiverse = 0;

  for(byte confrontaSensori=0;confrontaSensori<24;confrontaSensori++)
  {
    if(reading+24 != sensoriTrovati[confrontaSensori]) lettureDiverse++;

  }// for(byte confrontaSensori=0;confrontaSensori<=24;confrontaSensori++)

  if(lettureDiverse == 24)
  {
    if(analogRead(MUXOUT_3)<= soglia_Linee[reading+24])//soglia_Linee[reading+24]
    {
      tone(25,8000,20);
      sensoriTrovati[nSens] = reading+24;
      X += cos(gradi_Linee[reading+24]);
      Y += sin(gradi_Linee[reading+24]);
      nSens++;
      if(nSens > 24) nSens = 24;
      //Serial.println(reading+25);
      correzioneMillis = millis();
    }// if(analogRead(MUXOUT_3)<= soglia_Linee[reading+24])
  }// if(lettureDiverse == 24)
  }// void readMux3(byte reading)
*/

/*
  void individuaLinee()
  {
  if(!stoCorreggendo)
  {
    for(int lettura=0;lettura<9;lettura++)
    {

      if(digitalRead(linee[lettura]))
      {
        Serial.print(linee[lettura]);
        Serial.print(" - ");
        Serial.print(gradi_Linee[lettura]);
        tone(25,3000,10);
        display.fillRect(0,0,128,128,RED);

        display.setCursor(0,0);
        display.setTextSize(2);
        display.setTextColor(WHITE,RED);
        display.print(gradi_Linee[lettura]*180/3.14159265);

        X += cos(gradi_Linee[lettura]);
        Y += sin(gradi_Linee[lettura]);
        sensoriTrovati[nSens] = lettura;
        nSens++;
        stoCorreggendo = 1;
        correzioneMillis = millis();
        currentMillis = millis();
        while(stoCorreggendo && (currentMillis - correzioneMillis <= TEMPO_FUGA))
        {
          Serial.print(currentMillis);
          Serial.print(" - ");
          Serial.print(correzioneMillis);
          Serial.print(" - ");
          Serial.print(intervalloLinea);
          Serial.print(" - ");
          Serial.println(intervalloCorr);
          display.fillRect(0,0,128,128,WHITE);
          currentMillis = millis();
          direzioneCorrezione = double((atan2(Y,X)*180/3.14159265)+180);
          display.setCursor(0,64);
          display.setTextSize(2);
          display.setTextColor(WHITE,RED);
          display.print(direzioneCorrezione);
          display.setCursor(64,64);
          display.print(nSens);
          moveRobot(direzioneCorrezione,0,VELOCITA_FUGA_LINEA,1);

          if(nSens < 4)
          {
            for(int lettura=0;lettura<9;lettura++)
            {
              // Vengono esclusi i sensori precedentemente trovati
              if(digitalRead(linee[lettura]) && lettura != sensoriTrovati[0] && lettura != sensoriTrovati[1] && lettura != sensoriTrovati[2] && lettura != sensoriTrovati[3] && lettura != sensoriTrovati[4])
              {
                tone(25,4000,10);
                display.fillRect(0,0,128,128,GREEN);
                display.setCursor(64,64);
                display.print(nSens);
                X += cos(gradi_Linee[lettura]);
                Y += sin(gradi_Linee[lettura]);
                sensoriTrovati[nSens] = lettura;
                nSens++;
                if(nSens > 4) nSens = 4;

                currentMillis = millis();
                correzioneMillis = millis();
              }

              /*
              if(digitalRead(linee[lettura]) && lettura != sensoriTrovati[0]&& lettura != sensoriTrovati[1]&& lettura != sensoriTrovati[2]&& lettura != sensoriTrovati[3]&& lettura != sensoriTrovati[4]&& lettura != sensoriTrovati[5]&& lettura != sensoriTrovati[6])
               {
                  tone(25,4000,20);
                  //display.fillRect(0,0,128,128,GREEN);
                  display.setCursor(0,30);
                  display.setTextSize(2);
                  display.setTextColor(WHITE,RED);
                  display.print(gradi_Linee[lettura]*180/3.14159265);
                  X += cos(gradi_Linee[lettura]);
                  Y += sin(gradi_Linee[lettura]);
                  sensoriTrovati[nSens] = lettura;
                  nSens++;
                  if(nSens>4)
                  {
                    nSens = 0;
                    for(int in=0;in<=4;in++)
                    {
                      sensoriTrovati[in] = 90;
                    }
                  }
                  currentMillis = millis();
                  correzioneMillis = millis();

                }  // Inserire fine commento qui
              }//for(int lettura=0;lettura<9;lettura++)
            }//if(nSens <= 4)
        }// while(stoCorreggendo)
        stoCorreggendo = 0;
        nSens = 0;
        tone(25,6000,20);
        X = 0;
        Y = 0;
        for(int in=0;in<=4;in++)
        {
           sensoriTrovati[in] = 90;
        }
        lineaMillis = millis();
      }//if(digitalRead(linee[lettura]))
    }//for(int lettura=0;lettura<9;lettura++)
  }// if(!stoCorreggendo)
  // finito di correggere, resetta i parametri iniziali
  /*else
  {
    display.fillRect(0,0,128,128,YELLOW);
    stoCorreggendo = 0;
    nSens = 0;
    tone(25,6000,20);
    X = 0;
    Y = 0;
    for(int in=0;in<=4;in++)
    {
      sensoriTrovati[in] = 90;
    }
    lineaMillis = millis();
  }//else // inserire fine commento qui
  }// void individuaLinee()
*/

