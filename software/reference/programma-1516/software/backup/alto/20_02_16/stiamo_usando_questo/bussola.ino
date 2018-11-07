
void bussola_getHeading()
{
  
  
  if(currentMillis - bussolaMillis >= 100 || bussola_firstLettura)
  {
    //digitalWrite(6,HIGH);
    rgb(0,255,0);
    shiftRegister_sendBytes();

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
    display.setTextSize(4);
    display.setTextColor(RED);
    display.setCursor(0,50);
    display.print(gradiE);
    */
    //Serial.print(gradi),Serial.print(" - "),Serial.print(gradi_rel),Serial.print(" - "),Serial.println(gradiE);


    bussolaMillis = millis();
    bussola_firstLettura = 0;

  } 
  rgb(0,0,0);  
  shiftRegister_sendBytes();  
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