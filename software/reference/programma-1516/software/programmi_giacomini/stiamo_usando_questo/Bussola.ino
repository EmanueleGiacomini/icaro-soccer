int leggiBussola()
{
  compass.readHeading();
  gradi = compass.heading/10.0;
  gradi_rel = gradi - Vnord_rel;
  return gradi_rel;

  compass.readAccel();
  dirX = compass.accelX;
  dirY = compass.accelY;
  Serial.println(gradi);
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

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
