
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

void individuaLinee()
{


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
        if(lettura != lettura_Individuata[nLetture]) // Controlla che il sensore non sia stato salvato precedentemente
        {
          nLetture++; // nLetture è inizialmente 0, diventa 1 e imposta quindi lettura_Individuat[1] = lettura;
          lettura_Individuata[nLetture] = lettura; // Salva nell'array la lettura attuale
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
            if (sommaGradi == 361) direzioneCorrezione = 180; // Il robot imposta la direzione di correzione verso 180°

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
            while(currentMillis - correzioneMillis <= 500)
            {
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
                if((x != lettura_Individuata[1] && x!= lettura_Individuata[2] && x!= lettura_Individuata[0]) && digitalRead(linee[x]) && !terzoSensore)   
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
}