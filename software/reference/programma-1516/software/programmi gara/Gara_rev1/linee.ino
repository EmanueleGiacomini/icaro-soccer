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




void individuaLinee()
{
  if(!stoCorreggendo)
  {
    for(int lettura=0;lettura<9;lettura++)
    {

      if(digitalRead(linee[lettura]) && lettura != 5)
      {

        portiereLineaPresa = 1;
        portiereLineaMillis = millis();
        Serial.print(linee[lettura]);
        Serial.print(" - ");
        Serial.print(gradi_Linee[lettura]);
        tone(25,3000,10);
        //display.fillRect(0,0,128,128,RED);
        
        //display.setCursor(0,0);
        //display.setTextSize(2);
        //display.setTextColor(WHITE,RED);
        //display.print(gradi_Linee[lettura]*180/3.14159265);
        
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
          //display.fillRect(0,0,128,128,WHITE);
          currentMillis = millis();
          direzioneCorrezione = double((atan2(Y,X)*180/3.14159265)+180);
          //display.setCursor(0,64);
          //display.setTextSize(2);
          //display.setTextColor(WHITE,RED);
          //display.print(direzioneCorrezione);
          //display.setCursor(64,64);
          //display.print(nSens);
          moveRobot(direzioneCorrezione,0,VELOCITA_FUGA_LINEA,1);
          
          if(nSens < 4)
          {
            for(int lettura=0;lettura<9;lettura++)
            {
              // Vengono esclusi i sensori precedentemente trovati   
              if(digitalRead(linee[lettura]) && lettura!=5 && lettura != sensoriTrovati[0] && lettura != sensoriTrovati[1] && lettura != sensoriTrovati[2] && lettura != sensoriTrovati[3] && lettura != sensoriTrovati[4])
              {
                portiereLineaPresa = 1;
                portiereLineaMillis = millis();
                tone(25,4000,10);
                //display.fillRect(0,0,128,128,GREEN);
                //display.setCursor(64,64);
                //display.print(nSens);
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
      
                }  */  
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
  }//else */
}// void individuaLinee()



  /*
  if(nSens <= 1)
  {
    for(int lettura=0;lettura<9;lettura++)
    {
      if(digitalRead(linee[lettura]) && lettura != sensoriTrovati[0] && lettura != sensoriTrovati[1])
      {
        tone(25,5000,50);
        X[nSens] = cos(gradi_Linee[lettura]);
        Y[nSens] = sin(gradi_Linee[lettura]);
        Serial.print("Gradi Sensore: "),Serial.print(double(gradi_Linee[lettura])),Serial.print(" - "),Serial.print(X[nSens]),Serial.print(" - "),Serial.print(Y[nSens]),Serial.print(" - "),Serial.println(double(gradi_Linee[lettura]*180/3.14159265));
        sensoriTrovati[nSens] = lettura;
        nSens++;
        if(nSens > 1)
        {
          tone(25,6000,50);
          double sumY = Y[0] + Y[1];
          double sumX = X[0] + X[1];
          //Serial.print("SumY = "),Serial.print(sumY),Serial.print(" - SumX = "),Serial.print(sumX),Serial.print(" - direzioneCorrezione: "),Serial.println(double(atan2(sumY,sumX)*180/3.14159265));
          //delay(1000);
          direzioneCorrezione = double((atan2(sumY,sumX)*180/3.14159265)+180);
          stoCorreggendo = 1;
          correzioneMillis = millis();

          // Dopo aver individuato i primi 2 sensori di linea, si passa alla fase di movimento, in cui se viene poi rilevati altri n Sensori, la traiettoria verrà modificata di conseguenza


          while(stoCorreggendo && currentMillis - correzioneMillis <= intervalloCorr)
          {

            currentMillis = millis();
            direzioneCorrezione = double((atan2(sumY,sumX)*180/3.14159265)+180);
            display.setCursor(0,64);
            display.setTextSize(2);
            display.setTextColor(WHITE,RED);
            display.print(direzioneCorrezione);
            moveRobot(direzioneCorrezione,0,vel,1);

            for(int lettura=0;lettura<9;lettura++)
            {
              if(digitalRead(linee[lettura]) && lettura != sensoriTrovati[0] && lettura != sensoriTrovati[1] && lettura != sensoriTrovati[2] && lettura != sensoriTrovati[3] && lettura != sensoriTrovati[4] && lettura != sensoriTrovati[5] && lettura != sensoriTrovati[6])
              {
                sumY += cos(gradi_Linee[nSens]);
                sumX += sin(gradi_Linee[nSens]);

                sensoriTrovati[nSens] = lettura;
                nSens++;
                display.clearScreen();
                correzioneMillis = millis();

                if(nSens >= 6)
                {
                  nSens = 2;
                  // Se rilevo troppi sensori cosa dovrei fare ? 
                }// if(nSens >= 6)

              }// if(digitalRead(linee[lettura]) && lettura != sensoriTrovati[0] && lettura != sensoriTrovati[1] && lettura != sensoriTrovati[2] && lettura != sensoriTrovati[3] && lettura != sensoriTrovati[4] && lettura != sensoriTrovati[5] && lettura != sensoriTrovati[6])
            }//for(int lettura=0;lettura<9;lettura++)
          }// while(stoCorreggendo)

          // La fase finale mira a resettare tutti i parametri iniziali della funzione
          nSens = 0;
          sensoriTrovati[0] = 90;
          sensoriTrovati[1] = 90;
        }// if(nSens > 1)
      //Serial.print(sensoriTrovati[0]),Serial.print(" - "),Serial.print(sensoriTrovati[1]),Serial.print(" - "),Serial.print(sensoriTrovati[2]),Serial.print(" - "),Serial.println(sensoriTrovati[3]);           
      }// if(state && lettura != sensoriTrovati[0] && lettura != sensoriTrovati[1])
    }// for(int lettura=0;lettura<9;lettura++)
  }// if(nSens <= 1)
*/


void ledLinee()
{
  statoLed(5,(digitalRead(linee[0])*digitalRead(linee[7])));
  statoLed(6,(digitalRead(linee[0])*digitalRead(linee[1])));
  statoLed(7,(digitalRead(linee[6])*digitalRead(linee[7])));
  statoLed(8,(digitalRead(linee[3])*digitalRead(linee[4])));
  shiftRegister_sendBytes();
}

void linee_debug()
{
  for(int lettura=0;lettura<9;lettura++)
  {
    if(lettura!=5)  
    {  
    Serial.print(digitalRead(linee[lettura])),Serial.print(" - ");
    if(lettura == 8)  Serial.println();
    }
  }
}
