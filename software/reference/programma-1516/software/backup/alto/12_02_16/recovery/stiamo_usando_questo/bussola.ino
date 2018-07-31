
void bussola_getHeading()
{
  digitalWrite(6,LOW); 
  if(currentMillis - bussolaMillis >= 100 || bussola_firstLettura)
  {
    digitalWrite(6,HIGH);

    compass.readHeading();
    gradi = compass.heading/10.0;
    gradi_rel = gradi - Vnord;
    if(gradi_rel < 0) gradi_rel = gradi_rel + 360;
    gradiE = gradi;
    gradiE = gradiE - Vnord;
    if(gradiE > 180) gradiE = gradiE - 360;
    if(gradiE < -180) gradiE = gradiE + 360;
/*
    display.clearScreen();
    display.setTextSize(2);
    display.setTextColor(WHITE,BLACK);
    display.setCursor(0,0);
    display.print(gradi);
    display.setCursor(0,64);
    display.print(Vnord);
    display.setCursor(0,100);
    display.print(gradiE); */
    //Serial.print(gradi),Serial.print(" - "),Serial.print(gradi_rel),Serial.print(" - "),Serial.println(gradiE);


    bussolaMillis = millis();
    bussola_firstLettura = 0;    
  }
/*
  compass.readAccel();
  dirX = compass.accelX;
  dirY = compass.accelY;
  Serial.println(gradi); */


} 

/*float bussola_getAccel(char axis)
{
  if(currentMillis - accelMillis >= 200)
  {
    compass.readAccel();
    switch(axis)
    {
      case 'x':
        dirX = compass.accelX;
        return dirX;  
      break;
      case 'y':
        dirY = compass.accelY;
        return dirY;
      break;
    }
    accelMillis = millis();   
  }
}
*/
void bussola_setNord()
{
  if(currentMillis - lastCalMillis >= 1000 || bussola_firstCal)
  {
    bussola_firstCal = 0;
    tone(25,4000,200);
    unsigned long totalReadings = 0;
    for(int rep = 0;rep <= 9; rep++)
    {
      bussola_getHeading();
      totalReadings += gradi;
    }
    Vnord = totalReadings / 10;
    delay(100);
    noTone(25);
    lastCalMillis = millis();
  }
}





 // VECCHIE FUNZIONI ////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/*
void salvaVnord()
{
  gradi=leggiBussola();  
  EEPROM.write(0, highByte(gradi));
  EEPROM.write(1, lowByte(gradi));
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

int direzione_Virtuale()
{
  int direzione;
  direzione = (leggiBussola() - vnord);
  if(direzione <0)
    direzione = 360 + direzione;
  return direzione;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

int gradi_norm()
{
  gradi = leggiBussola() - base_bussola;
  if (gradi < 0) gradi+= 360;
}
*/  