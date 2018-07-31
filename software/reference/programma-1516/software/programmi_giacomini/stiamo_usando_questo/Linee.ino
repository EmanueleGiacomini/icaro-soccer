
/*
un For legge tutti i sensori.Appena un sensore legge la linea, viene salvato ed escluso dalla lettura.
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
	byte stato_Linea[10];
	unsigned int gradiLinea;
	int lettura_Individuata, direzioneCorrettura;
	byte nLetture;

	if(currentMillis - previousMillis_Linea >= intervallo_Linea)
	{

		for(int lettura = 0;lettura < 10;lettura++)
		{
			if(digitalRead(linee[lettura]))
			{

				if(lettura != lettura_Individuata)
				{
					nLetture++;
					lettura_Individuata = lettura;
					gradiLinea += gradi_Linee[lettura];
					if(nLetture == 2)
					{
						nLetture = 0;
						previousMillis_Linea = millis();
						direzioneCorrettura = (gradiLinea / 2);
						if(direzioneCorrettura == 360) direzioneCorrettura = 0;
						if(direzioneCorrettura != 0) direzioneCorrettura = direzioneCorrettura + 180;
						// moveRobot(direzioneCorrettura,0,0,0);
					}
				}

			}
		 }
	}
}	
