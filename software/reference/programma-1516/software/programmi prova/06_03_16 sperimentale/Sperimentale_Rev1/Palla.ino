	



const int sensPallaDir[] = {0,12,25,38,51,64,77,90,120,150,180,210,240,270,282,295,308,321,334,347};


// la funzione getPalla assegna alla variabile traiettoriaPalla , la direzione che il robot deve prendere per riuscire
// a raggiungere la palla con la giusta angolazione
void getPalla()
{
	leggiSerialeUno();

	if(posPalla != 99)
	{

		if(posPalla > 1 && posPalla <= 10)
		{
			traiettoriaPalla = sensPallaDir[(posPalla+1)+(3-distanzaPalla)];
		}
		else if(posPalla > 10 && posPalla < 19)
		{
			traiettoriaPalla = sensPallaDir[(posPalla-1)-(3-distanzaPalla)];
		}
		switch(posPalla)
		{
			case 0:
			traiettoriaPalla = 0, vel = VELOCITA_ATTACCO;
			break;
			case 1:
			traiettoriaPalla = 0, vel = VELOCITA_ATTACCO;
			break;
			case 19:
			traiettoriaPalla = 0, vel = VELOCITA_ATTACCO;
			break;
		}
	}
	else
	{
		traiettoriaPalla = -1;
		distanzaPalla = 0;
	}
	moveRobot(traiettoriaPalla,0,vel,1);
	vel = VELOCITA;

}
/*
unsigned long tempo99 = 0;
boolean caso;
void getPalla1()
{
	leggiSerialeUno();
	switch(posPalla)
	{
		case 0:
		traiettoriaPalla = 0;
		vel = VELOCITA_ATTACCO;
		break;
		case 1:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 45;
			vel = VELOCITA_ATTACCO;
			break;
			case 1:
			traiettoriaPalla = 20;
			break;
			case 2:
			traiettoriaPalla = 12;
			break;
			case 3:
			traiettoriaPalla = 12;
			break;
		}
		break;
		case 2:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 60;
			break;
			case 1:
			traiettoriaPalla = 45;
			break;
			case 2:
			traiettoriaPalla = 25;
			break;
			case 3:
			traiettoriaPalla = 25;
			break;
		}
		break;
		case 3:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 100;
			break;
			case 1:
			traiettoriaPalla = 60;
			break;
			case 2:
			traiettoriaPalla = 37;
			break;
			case 3:
			traiettoriaPalla = 37;
			break;
		}
		break;
		case 4:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 135;
			break;
			case 1:
			traiettoriaPalla = 85;
			break;
			case 2:
			traiettoriaPalla = 50;
			break;
			case 3:
			traiettoriaPalla = 50;
			break;
		}
		break;
		case 5:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 150;
			break;
			case 1:
			traiettoriaPalla = 90;
			break;
			case 2:
			traiettoriaPalla = 62;
			break;
			case 3:
			traiettoriaPalla = 62;
			break;
		}
		break;
		case 6:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 180;
			break;
			case 1:
			traiettoriaPalla = 110;
			break;
			case 2:
			traiettoriaPalla = 75;
			break;
			case 3:
			traiettoriaPalla = 75;
			break;
		}
		break;
		case 7:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 180;
			break;
			case 1:
			traiettoriaPalla = 135;
			break;
			case 2:
			traiettoriaPalla = 87;
			break;
			case 3:
			traiettoriaPalla = 87;
			break;
		}
		break;
		case 8:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 180;
			break;
			case 1:
			traiettoriaPalla = 175;
			break;
			case 2:
			traiettoriaPalla = 100;
			break;
			case 3:
			traiettoriaPalla = 100;
			break;
		}
		break;
		case 9:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 230;
			break;
			case 1:
			traiettoriaPalla = 220;
			break;
			case 2:
			traiettoriaPalla = 220;
			break;
			case 3:
			traiettoriaPalla = 210;
			break;
		}
		break;
		case 10:
		switch(distanzaPalla)
		{
			case 0:
			if(currentMillis - tempo99 > 400) caso = random(0, 1), tempo99 = millis();
			if(caso) traiettoriaPalla = 270;
			else traiettoriaPalla = 90;
			
			break;
			case 1:
			traiettoriaPalla = 180;
			break;
			case 2:
			traiettoriaPalla = 180;
			break;
			case 3:
			traiettoriaPalla = 180;
			break;
		}
		break;
		case 11:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 140;
			break;
			case 1:
			traiettoriaPalla = 130;
			break;
			case 2:
			traiettoriaPalla = 130;
			break;
			case 3:
			traiettoriaPalla = 120;
			break;
		}
		break;
		case 12:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 180;
			break;
			case 1:
			traiettoriaPalla = -175;
			break;
			case 2:
			traiettoriaPalla = -100;
			break;
			case 3:
			traiettoriaPalla = -100;
			break;
		}
		break;
	    case 13:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 180;
			break;
			case 1:
			traiettoriaPalla = -135;
			break;
			case 2:
			traiettoriaPalla = -87;
			break;
			case 3:
			traiettoriaPalla = -87;
			break;
		}
		break;
		case 14:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = 180;
			break;
			case 1:
			traiettoriaPalla = -110;
			break;
			case 2:
			traiettoriaPalla = -75;
			break;
			case 3:
			traiettoriaPalla = -75;
			break;
		}
		break;
		case 15:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = -150;
			break;
			case 1:
			traiettoriaPalla = -90;
			break;
			case 2:
			traiettoriaPalla = -62;
			break;
			case 3:
			traiettoriaPalla = -62;
			break;
		}
		break;
		case 16:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = -135;
			break;
			case 1:
			traiettoriaPalla = -85;
			break;
			case 2:
			traiettoriaPalla = -50;
			break;
			case 3:
			traiettoriaPalla = -50;
			break;
		}
		break;
		case 17:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = -60;
			break;
			case 1:
			traiettoriaPalla = -45;
			break;
			case 2:
			traiettoriaPalla = -25;
			break;
			case 3:
			traiettoriaPalla = -25;
			break;
		}
		break;
		case 18:
		switch(distanzaPalla)
		{
			case 0:
			traiettoriaPalla = -45;
			vel = VELOCITA_ATTACCO;
			break;
			case 1:
			traiettoriaPalla = -20;
			break;
			case 2:
			traiettoriaPalla = -12;
			break;
			case 3:
			traiettoriaPalla = -12;
			break;
		}
		break;
		case 19:
		traiettoriaPalla = 0;
		vel = VELOCITA_ATTACCO;
		break;		
		case 99:
		traiettoriaPalla = -1;
		break;
	}
	moveRobot(traiettoriaPalla,0,vel,1);
	vel = VELOCITA;
	delay(2); 
}*/