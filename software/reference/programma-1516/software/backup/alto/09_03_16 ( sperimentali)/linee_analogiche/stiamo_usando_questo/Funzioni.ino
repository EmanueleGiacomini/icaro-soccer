

// FUNZIONI VECCHIE
/*

// Creazione disegno bussola
int a  = 0;
void creaBussola(int x=74,int y=74,int d=40)
{ 
  if(a == 0)
  {
    for(int c = 0;c < 24;c++)
    {
      display.drawCircle(x, y, d+10, RED);
      int big = c % 6;
      float sc, cc;
      sc = sin(c*0.261);
      cc = cos(c*0.261);
      if(big == 0) display.drawLine(x+cc*d,y+sc*d,x+cc*(d+10),y+sc*(d+10),RED);
      else display.drawLine(x+cc*d,y+sc*d,x+cc*(d+5),y+sc*(d+5),WHITE);

    }
    a = 1;

  }

}


// Creazione Ago bussola
void agoBussola(int x=74,int y=74,int d=40)
{   

  float sb,cb,dif;
  dif = vnord-round(leggiBussola());
  if(dif < 0) {
    dif = 360 + dif;
  }

  sb = sin(dif*(PI/180));
  cb = cos(dif*(PI/180));
  display.drawLine(x,y,x+cb*d,y+sb*d,RED);
  delay(50);
  display.drawLine(x,y,x+cb*d,y+sb*d,BLACK);
}

void lol()
{
  creaBussola();
  agoBussola();
}
*/

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
////////////////////////////FUNZIONI US///////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void centra()
{    
  leggiSerialeUno();
 if((distanzaDx+distanzaSx)>140){
   if(distanzaDx-distanzaSx > 15){
    moveRobot(90, 0, 70, 0);
  }
  else if(distanzaDx-distanzaSx < -15){
    moveRobot(270, 0, 70, 0);
  }
  else if((distanzaDx-distanzaSx <= 7) || (distanzaDx-distanzaSx >= -7)){
    moveRobot(fermo, 0, 0, 0);
  }
 }

}
