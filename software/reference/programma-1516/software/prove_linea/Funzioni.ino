void bsod(){
  led(255,0,0);
  digitalWrite(ledBat, HIGH);
  display.clearScreen();
  delay(200);
  digitalWrite(ledBat, LOW);
  display.fillRect(0,0,128,128,BLUE);
  delay(30);
  display.clearScreen();
  delay(400);
  ledOff();
  display.fillRect(0,0,128,128,BLUE);
  delay(80);
  digitalWrite(ledBat, HIGH);
  display.clearScreen();
  delay(400);
  led(255,0,0);
  display.fillRect(0,0,128,128,BLUE);
  delay(50);
  display.clearScreen();
  delay(100);
  digitalWrite(ledBat, LOW);
  display.fillRect(0,0,128,128,BLUE);
  delay(500);
  digitalWrite(ledBat, HIGH);
  ledOff();
  display.clearScreen();
  delay(100);
  display.fillRect(0,0,128,128,BLUE);
  led(255,0,0);

  display.setCursor(0,0);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("\nA problem has been \ndetected and \nPhoenixOS has been \nshut down to preventdamage your robot");
  display.print("\n\nTecnical Information:\n*** STOP: 0x00000050 (0xA8AF3000, 0x0E284A90, 0x9DD24629)");
  delay(8000);
  display.clearScreen();
  display.fillRect(0,0,128,128,BLUE);
  display.setCursor(0,0);
  display.print("If this is the first time you've seen thisstop error screen, \nrestart your robot. \nIf this screen appears again, follow thesesteps:");
  display.print("\nCheck to make sure any new hardware or software is properly installed. If this is a new installation, ask your hardwareor software manifacturer forany PhoenixOS updates you might need.");
  delay(8000);
  display.clearScreen();
  display.fillRect(0,0,128,128,BLUE);
  display.setCursor(0,0);
  display.print("If problem continue, disable coglione.ino or remove any newly installed hardware or software in your mom.Disable BIOS memory options such as caching or shadowing.");
  display.print("If you need to use safe coglione mode to remove or disable components, restart your computer, press F8 to select advanced startup options, and than select safe mode");
  delay(8000);
  display.clearScreen();
  display.fillRect(0,0,128,128,BLUE);
  display.setCursor(0,0);
  display.print("If you are still \nwatching this \nbluescreen, it means \nthat you are \na coglione");


  delay(5000);
  display.clearScreen();
  display.fillRect(0,0,128,128,BLUE);
  display.setCursor(0,0);
  //display.print("\n\n N.B. \nUn programmatore \nha anche bisogno di \nun po' di svago ");
  display.print("\n\n N.B. \n\nLa noia ");

  delay(4000);
  display.clearScreen();
  ledOff();
  digitalWrite(ledBat, LOW);
}


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










