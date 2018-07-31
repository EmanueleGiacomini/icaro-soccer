String menu_0[] ={
  "Bussola","Bluetooth","Motori","Sens Palla","Sens Linea","Ultrasuoni","Calcio"};



void menu()
{
  while(1)
  {
    lvl = 0;
    constrain(encoderPos,0,maxEncoderPos);
    if(encoderPos > maxEncoderPos) encoderPos = maxEncoderPos;
    if(encoderPos < 0) encoderPos = 0;
    /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
    ///////////////////// LISTA DEI MENU' ///////////////////////////////
    switch(lvl)
    {
    case 0 :
      for(int a = 0 ; a < 7 ; a++)
      { 
        int posDx = a % 2;
        posDx = a % 2 ;
        if(posDx) display.setCursor(30,i*20+20);
        else display.setCursor(0,i*20+20);			

      }





    }

  }





}

