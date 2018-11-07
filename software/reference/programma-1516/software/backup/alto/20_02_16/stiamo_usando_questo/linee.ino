
/*
Un For legge tutti i sensori.Appena un sensore legge la linea, viene salvato ed escluso dalla lettura.
se in un periodo N viene letto da un altro sensore la linea, viene calcolata la retta tangente alla base del robot che indica la linea con la formula " (gradosensore1 + gradosensore2) / nsensori (2)".
sommando 180 e limitando il risultato fra 0 e 359, ottengo la direzione da prendere per allontanarsi dalla linea.

Studiare come comportarsi quando piu' di 2 sensori leggono la linea.Particolarmente da rivedere i comportamenti in prossimità degli angoli del campo

dare circa 1000 ms di tempo dopo aver individuato la linea per allontanarsi da essa.

Questo sistema in teoria utilizza solamente l'array di sensori esterni. I sensori interni possono essere usati in 2 modi:
1) se per inerzia il robot esce troppo dal campo, per confermare la direzione su cui il robot si muove, posso vedere se leggo prima l'array interno e poi l'esterno o viceversa.
2) Se per inerzia il robot esce dal campo, passerà su un sensore interno, che forzerà il movimento dalla parte opposta di esso: esempio, mi muovo velocemente a destra e il sistema di array esterno fallisce,
il sensore n2 (interno destro) verrà triggerato e il robot si fermerà, muovendosi a sinistra rapidamente.

*/
// LED VARI ( SHIFT REGISTER_2)
/*
Index Array:
1:Led 1 Tattica 2
2:Led 2 Tattica 1
3:Led 3 Tattica 3
4:Led 4 Tattica 4
5:Led 5 Linee Ant
6:Led 6 Linee Dx
7:Led 7 Linee Sx
8:Led 8 Linee Post
*/

/*
int linee[] = {2, 3, 31, 27, 24, 26, 14, 15, 16, 33};
int gradi_Linee[] = {81, 100, 90, 170, 190, 180, 260, 280, 270, 0};
unsigned long previousMillis_Linea = 0, correzioneMillis = 0;
const int intervallo_Linea = 1000; // Timer per lettura della linea
int direzioneCorrezione = 0; // Direzione da prendere per allontanarsi dalla linea
volatile int sensori_individuati[4] = {90,90,90,90}; // Valori randomici per non interferire con l'indice del sensore individuato 
byte nSensore = 0; // Indice di sensori che individuano la linea
byte stato_Linea[10]; // Lo stato 0/1 di ogni sensore
unsigned long sommaGradi, sommaGradiCorr; // sommaGradi viene usata durante le prime 2 letture, sommaGradiCorr viene usata nelle ultime 2 letture
*/


void ledLinee()
{
  statoLed(5,(digitalRead(linee[0])*digitalRead(linee[7])));
  statoLed(6,(digitalRead(linee[0])*digitalRead(linee[1])));
  statoLed(7,(digitalRead(linee[6])*digitalRead(linee[7])));
  statoLed(8,(digitalRead(linee[3])*digitalRead(linee[4])));
  shiftRegister_sendBytes();
}

void individuaLinee()
{
  /*
  if(!digitalRead(sensAnt))
  {
    moveRobot(180,0,150,1);
  }
  if(!digitalRead(sensAnt))
  {
    moveRobot(180,0,150,1);
  }
  */
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////// FASE INIZIALE         //////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  // IN questa fase il robot controlla se una coppia di sensori rileva la linea bianca.
  // Quando ciò accade, viene calcolata una traiettoria di allontanamento da tale linea ( fase secondaria)


 // nSensore si presuppone sia 0 o 1
  display.setTextSize(2);
  display.setTextColor(WHITE,BLACK);
  if(currentMillis - previousMillis_Linea >= intervallo_Linea)
  {
    // Se passano almeno nmillisecondi, controlla i sensori di linea
    for(int lettura = 0;lettura < 9;lettura++)
    {
      // La funzione qui riportata viene ripetuta 2 volte prima che il robot possa calcolare una traiettoria per allontanarsi dalla linea
      ledLinee();
      if(digitalRead(linee[lettura]) && lettura != sensori_individuati[0] && lettura != sensori_individuati[1] && lettura != sensori_individuati[2] && lettura != sensori_individuati[3] )
      {
        tone(25,4000,25);
        sensori_individuati[nSensore] = lettura;
        nSensore++;
        sommaGradi += gradi_Linee[lettura];

      }// if(digitalRead(linee[lettura]) && lettura != sensori_individuati[0] && lettura != sensori_individuati[1] )

      
      if(nSensore == 2)
      {
        tone(25,5000,25);
        if (sommaGradi == 361) direzioneCorrezione = 180; // Il robot imposta la direzione di correzione verso 180°
        else
        {
          direzioneCorrezione = (sommaGradi / 2); // crea una retta intrinseca perpendicolare alla linea bianca
          direzioneCorrezione = direzioneCorrezione + 180; // inverte la retta, dando una traiettoria opposta alla linea
          if(direzioneCorrezione > 359) direzioneCorrezione = direzioneCorrezione - 360; // rende 0 il valore 360 in caso il robot debba andare avanti
        } 
        display.clearScreen();
        display.setCursor(64,64);
        display.print(direzioneCorrezione); 
        stoCorreggendo = 1;
        correzioneMillis = millis();
      }



      /////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////FINE FASE INIZIALE     //////////////////////////////////////////////
      /////////////////////////////////////////////////////////////////////////////////////////////////////
      // Nella seconda fase il robot si muove verso una traiettoria di allontanamento dalla linea, ma in oltre
      // se trova un altra linea con altri 2 sensori, ricalcola una nuova traiettoria, evitando cosi problemi agli angoli.
      
      
      while(stoCorreggendo) 
      {
        currentMillis = millis();
        Serial.println("0");
        if(currentMillis - correzioneMillis <= intervallo_correzione)
        {
          //Serial.println("Correggo");
          Serial.println("1");
          digitalWrite(rgb_Red, HIGH);
          moveRobot(direzioneCorrezione,0,150,1);

          for(int letturaCr = 0;letturaCr < 9;letturaCr++)
          {
            ledLinee();
            Serial.println("2");
            if(digitalRead(linee[letturaCr]) && letturaCr != sensori_individuati[0] && letturaCr != sensori_individuati[1] && letturaCr != sensori_individuati[2] && letturaCr != sensori_individuati[3] )
            {
              Serial.println("3");
              tone(25,7000,50);
              sensori_individuati[nSensore] = letturaCr;
              nSensore++;
              sommaGradiCorr += gradi_Linee[letturaCr];    
              if(nSensore == 4)
              {
                Serial.println("4");
                if((sommaGradi+sommaGradiCorr) == 721) direzioneCorrezione = 180,intervallo_correzione = 850;
                else
                {
                direzioneCorrezione = (sommaGradi + sommaGradiCorr)/4;                
                direzioneCorrezione = direzioneCorrezione + 180;                
                if(direzioneCorrezione > 359) direzioneCorrezione = direzioneCorrezione - 360;
                }
                /*
                display.clearScreen();
                display.fillRect(0,0,128,128,RED);
                display.setCursor(0,30);
                display.print(sommaGradi);
                display.setCursor(80,30);
                display.print(sommaGradiCorr);
                display.setCursor(64,64);
                display.print(direzioneCorrezione); */
                sommaGradiCorr = 0;
                nSensore = 2;
                correzioneMillis = millis();
              } // if(nSensore == 4)
            }// if(digitalRead(linee[letturaCr]) && letturaCr != sensori_individuati[0] && letturaCr != sensori_individuati[1] && letturaCr != sensori_individuati[2] && letturaCr != sensori_individuati[3] )
          }// For
        }// if(currentMillis - correzioneMillis <= 500)

        else // Se trova i primi 2 sensori, per 500 millisecondi corregge, poi torna allo stato iniziale 
        {          
          Serial.println("5");
          sensori_individuati[0] = 90;
          sensori_individuati[1] = 90;
          sensori_individuati[2] = 90;
          sensori_individuati[3] = 90;
          nSensore = 0;
          sommaGradiCorr = 0;
          sommaGradi = 0;
          digitalWrite(rgb_Red, LOW);
          previousMillis_Linea = millis();
          stoCorreggendo = 0;
          delay(50);
          return;   
        }// else            
      }// while(nSensore > 1 && currentMillis - correzioneMillis <= 1000)
      



    }// for(int lettura = 0;lettura < 9;lettura++)
  }// if(currentMillis - previousMillis_Linea >= intervallo_Linea)
}// void individuaLinee()













 /* 


  if(currentMillis - previousMillis_Linea >= intervallo_Linea)
  {
    for(int lettura = 0;lettura < 9;lettura++) // Inizia un ciclo di lettura di tutti i sensori IL SENSORE ANTERIORE è ESCLUSO
    {
      if(digitalRead(linee[lettura])) // Se trovi una linea, 
      {
        vel = vel/2;
        /*
        lettura_Individuata[] è un array che contiene 3 valori : lettura3, lettura1, lettura2.
        Di default lettura3, lettura1 e lettura2 sono impostati come 90 per non essere confusi con altre letture.
        lettura1 e lettura2 si impostano tramite la variabile nLetture che, alla prima lettura diventa 1 e alla seconda diventa 2.
        lettura3 viene usata solamente se durante la correzione viene individuata un altra linea
        */
       /* if(lettura != lettura_Individuata[nLetture]) // Controlla che il sensore non sia stato salvato precedentemente
        {
          lettura_Individuata[nLetture] = lettura; // Salva nell'array la lettura attuale
          nLetture++; // nLetture è inizialmente 0, diventa 1 e imposta quindi lettura_Individuat[1] = lettura;
           
          sommaGradi += gradi_Linee[lettura]; // Calcola la somma dei sensori;


          if(nLetture == 2) // Il robot ha trovato 2 punti che creano una retta tangente alla circonferenza del robot
          // tale retta è proprio la linea che interseca i 2 sensori che l'hanno rilevata.
          {
            nLetture = 0; // resettiamo il contatore per le letture.
            previousMillis_Linea = millis(); // Impostiamo l'istante di tempo in cui la linea è stata trovata

            /*
            Per Distinguere la tangente anteriore da quella posteriore, è stato inserito un grado fittizio
            il valore del sensore 0 è 81° e quindi 280 + 81 = 361
            */
           /* if (sommaGradi == 361) direzioneCorrezione = 180; // Il robot imposta la direzione di correzione verso 180°

            else
            {
              direzioneCorrezione = (sommaGradi / 2); // crea una retta intrinseca perpendicolare alla linea bianca
              direzioneCorrezione = direzioneCorrezione + 180; // inverte la retta, dando una traiettoria opposta alla linea
              if (direzioneCorrezione == 360) direzioneCorrezione = 0; // rende 0 il valore 360 in caso il robot debba andare avanti
            }
            
            // Arriva la parte intrippante
            correzioneMillis = millis();
            /*
            Per non interrompere il proramma, utilizziamo un sistema con millis per correggere la traiettoria
            del robot. Inoltre se rileviamo una linea in questo intervallo, possiamo correggere ancora la traiettoria.

            */
            /*while(currentMillis - correzioneMillis <= 500)
            {
              display.clearScreen();
              display.setTextSize(2);
              display.setTextColor(WHITE,BLACK);
              display.setCursor(0,30);
              display.print(lettura_Individuata[1]);
              display.setCursor(30,30);
              display.print(lettura_Individuata[2]);
              display.setCursor(50,30);
              display.print(lettura_Individuata[0]);


              digitalWrite(6,HIGH); // LED RGB VERDE ACCESO
              currentMillis = millis(); // continuiamo la lettura dei millisecondi
              


              moveRobot(direzioneCorrezione,0,150,0); // Correggo la traiettoria
              for(int x = 0;x<9;x++) // Continuo a leggere i sensori per eventuali intercettazioni
              {
                /*
              Magic smoke !
              controlla se il sensore individuato differisce dai 2 sensori che hanno attivato la correzione precedentemente.
              */
              /*Serial.print(digitalRead(linee[x])),Serial.print(" - ");
              if(x == 8) Serial.println();*/
              /*  if((x != lettura_Individuata[1] && x!= lettura_Individuata[2] && x!= lettura_Individuata[0]) && digitalRead(linee[x]) && !terzoSensore)   
                {                                      
                  digitalWrite(20,HIGH); // LED RGB ROSSO ACCESO
                  lettura_Individuata[0] = x; // nella posizione 0 dell'array mi salvo il sensore che ha corretto.
                  correzioneMillis = currentMillis; // resetto il tempo di correzione
                  direzioneCorrezione = direzioneCorrezione + gradi_Linee[x]; // sommo alla correzione, il valore dei gradi del sensore individuato
                  
                  if(direzioneCorrezione >= 360) direzioneCorrezione = direzioneCorrezione - 360; // limita il valore da 0 a 359

                  //if((direzioneCorrezione >= 90) && (direzioneCorrezione <= 360))
                  //{
                  //  direzioneCorrezione = direzioneCorrezione + 180;
                  //  if(direzioneCorrezione >= 360) direzioneCorrezione = direzioneCorrezione - 360;
                  //}
                  

                  terzoSensore = 1;
                }                 
              }
              display.setCursor(0,90);
              display.print(direzioneCorrezione);
            }
            Serial.println(" uscito ");
            // Freno il robot e resetto le variabili.
            Serial.print(currentMillis),Serial.print(" - "), Serial.println(correzioneMillis);
            digitalWrite(6, LOW);
            digitalWrite(20, LOW);
            frena(1);
            sommaGradi = 0;
            direzioneCorrezione = 0;
            lettura_Individuata[0] = 90;
            terzoSensore = 0;
            vel = 100;


          }
        }
      }
    }
  }
  */