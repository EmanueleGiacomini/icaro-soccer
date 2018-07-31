void attaccante()
{
	//===========================================================================
	//============================= Basic =======================================
	//===========================================================================

	bussola_getHeading();
	getPalla();
	//getPalla1(); //switch
	/* Implementazione calcio 
	if(analogRead(sensPalla) < soglia && gradiE < 10 && gradiE > -10)
	{
		digitalWrite(calcio,HIGH);
		delay(TEMPO_CALCIO);
		digitalWrite(calcio,LOW);	
	}

	*/








	//===========================================================================
	//============================= Advanced ====================================
	//===========================================================================
	// Muoversi in relazione alla posizione della porta tramite pixy una volta 
	// ottenuta la palla
	/*
	una volta catturata la palla, tramite pixy si può vedere se vi è
	piu' spazio a destra o a sinistra del robot, e pensare di traslare
	in quella zona.
	Successivamente se la porta avversaria è visibile, si imposta il PID per
	correggere la rotazione dei movimenti verso la porta, ed appena il robot
	ha visione sulla porta, usa il calcio.

	*/




}

void portiere()
{
	




}