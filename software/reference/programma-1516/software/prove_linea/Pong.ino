void pong(){
  display.setRotation(45);
  int color = 0xFD20;


  float x = 20; //posizione pallina
  float y = 10;
  float sx = 5; // incremento posizione pallina
  float sy = 4;
  int p1  = 0;   // punteggo
  int p2  = 0;
  int oldp1,oldp2, oldencoderPos, oldr2;
  encoderPos = 100; // posizione racchetta 1
  int r2 = 100; // posizione racchetta 2
  int incR = 15; // incremento posizione racchette 
  int height = 108, width = 128;
  int errore, probabilita;
  int bandiera;
  boolean punto;



  while(1){
    if(encoderPos<0) encoderPos=0;
    else if(encoderPos>70)encoderPos=70;

    /////////////////////////////////////////
    ///// CAMPO
    display.fillRect(0, 0, 128, 3, color);
    display.fillRect(0, 108, 128, 3, color);
    int numero = 0;
    for(int q = 0; q<6; q++){
      display.fillRect(63, numero, 1, 10, color);
      numero += 20;
    }

    oldp1=p1; 
    oldp2=p2;
    oldencoderPos=encoderPos;
    oldr2=r2;

    /////////////////////////////////////////
    ///// MOVIMENTO PALLA 
    x = x + sx;
    y = y + sy;
    if ((y < 0) || (y > height)) {
      // inverte il segno di sy
      sy = -1 * sy;
    }
    if (x<0) {
      p1 = p1 + 1;
      x = width / 2;
      y = height / 2;
      punto = true;
    } 
    else{ 
      punto=false;

    }
    if (x > width) {
      p2 = p2 + 1; 
      x = width / 2;
      y = height / 2;
    }


    /////////////////////////////////////////
    ///// MOVIMENTO RACCHETTA CPU 

    bandiera++;  
    display.fillRect(0, 0, 30, 8, BLACK);
    display.setTextSize(1);
    display.setCursor(0,0);
    display.setTextColor(GREEN);
    display.print(bandiera);

    if(bandiera > 100 || punto == true){
      probabilita = random(0,100);
      bandiera = 0;  
    }

    if(probabilita > 60){
      r2 = y + 1;
      display.print(" E");
    }
    else
      r2= y-20;




    /////////////////////////////////////////
    // collision detection racchetta 2 (CPU)
    if ((x<= 20) && (x >=10) && (y >= r2) && (y <= (r2 +40)))
    {
      sx = -1 * sx;
    }
    /////////////////////////////////////////
    // collision detection racchetta 1 (HUMAN)
    if (((x<= width - 10)) && (x >=(width - 20)) && (y >= encoderPos) && (y <= (encoderPos +40)))
    {
      sx = -1 * sx;
    }
    /////////////////////////////////////////
    //// PALLA
    display.fillCircle(x, y, 2, RED);
    //// RACCHETTE
    display.fillRect(10, r2, 7, 40, BLUE);
    display.fillRect(width - 17, encoderPos, 7, 40, YELLOW);  

    //// TESTO PUNTEGGIO
    display.setTextSize(2);
    display.setCursor(20,112);
    display.setTextColor(BLUE);
    display.print(p1);

    display.setCursor(90,112);
    display.setTextColor(YELLOW);
    display.print(p2);


    delay(45);
    display.fillCircle(x, y, 2, BLACK);

    if(oldencoderPos != encoderPos){
      display.fillRect(width -17, 3, 7, 108, BLACK);
    } 
    if(oldr2 != r2){
      display.fillRect(10, r2 -10, 7, 60, BLACK); 
    }
    if(p1 != oldp1 || p2 != oldp2){
      display.fillRect(0, 111, 128, 30, BLACK);
    }

  }// while 1

}//pong













