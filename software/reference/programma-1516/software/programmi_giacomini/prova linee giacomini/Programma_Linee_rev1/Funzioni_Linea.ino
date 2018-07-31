void setupLinee()
{
	pinMode(Interni[0],INPUT);
	pinMode(Interni[1],INPUT);
	pinMode(Interni[2],INPUT);
	pinMode(Esterni[0],INPUT);
	pinMode(Esterni[1],INPUT);
	pinMode(Esterni[2],INPUT);
	pinMode(Esterni[3],INPUT);
	pinMode(Esterni[4],INPUT);
	pinMode(Esterni[5],INPUT);
}

void checkLine()
{
	for(int i = 0; i < 6; i++)
	{
		if(digitalRead(Esterni[i]))
		{
			counterLinea++; // counter per ogni volta che la linea viene percepita da un sensore
			switch(counterLinea)
			{
				case 1:
				sensoreA = GradiExt[i]; // Assegna a sensoreA il valore 
				break;

				case 2:
				if(GradiExt[i] == sensoreA) counterLinea--;
				break; // se viene segnalato per la seconda volta il sensore precedente, scarta l'evento.

				sommaLinea = (sensoreA+sensoreB); // sommo il valore angolare dei sensori che hanno visto la linea.

				if(sommaLinea == 360) sommaLinea = 0; // per continuità, quando 80 e 280 si sommano, 360/2 farebbe 180, e quindi dando un angolo di incidenza sbagliato.

				valoreLinea = (sommaLinea/2)+180;// sommaLinea/2 mi fornisce l'angolo di incidenza con la linea, sommando 180 inverto la direzione, fornendo la direzione di controbilancio

				if(valoreLinea>=360) valoreLinea = valoreLinea - 360; // Limito l'insieme dei risultati tra 0 e 359.

				counterLinea = 0; // resetto la funzione.
				triggerLinea = 1; // Avvio il controbilancio
				break;
			}
		}
	}
	while(triggerLinea)
	{
		moveRobot(valoreLinea,0,150,0);
		delay(500);
		valoreLinea = 0;
		triggerLinea = 0;
		break;     
		

	}
}
