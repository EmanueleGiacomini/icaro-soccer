



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
			traiettoriaPalla = sensPallaDir[posPalla+3];
		}
		else if(posPalla > 10 && posPalla < 19)
		{
			traiettoriaPalla = sensPallaDir[posPalla-3];
		}
		switch(posPalla)
		{
			case 0:
			traiettoriaPalla = 0, vel = 170;
			break;
			case 1:
			traiettoriaPalla = 12, vel = 170;
			break;
			case 19:
			traiettoriaPalla = 347, vel = 170;
			break;
		}
	
	}
	else
	{
      traiettoriaPalla = -1;
	}
	moveRobot(traiettoriaPalla,0,135,1);
	delay(2);
}
