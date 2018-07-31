/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void calciosol()
{

	currentMillis = millis();
	if(analogRead(A10) > 920)
    {
    	if(!caricoCalcio) caricoCalcio = 1,calcioMillis=millis();

    	if(currentMillis - calcioMillis > 200)
    	{
			digitalWrite(calcio,HIGH);
			delay(TEMPO_CALCIO);
			digitalWrite(calcio,LOW);
			delay(300);
			caricoCalcio = 0;
		}
    }
}

void provaCalcio()
{
	while(1)
	{
		if(analogRead(sel)<10)
		{
			digitalWrite(calcio,HIGH);
			delay(TEMPO_CALCIO);
			digitalWrite(calcio,LOW);
			delay(1000);

		}
		
	}
}
