void displayBlocks() {
  uint16_t blocks;
  int xPosCentroPalla, yCentroPalla;

  if(currentMillis - pixyMillis > 50){
  blocks = pixy.getBlocks();

  Serial.println(blocks);
  if ((blocks >= 1) && (pixy.blocks[0].signature == 1)) {
    Serial.println("la firma è 1");
    usoPixy = 1;
    rgb(255, 50, 0);

    if (pixy.blocks[0].x <= 159)
      xPosCentroPalla = -((159 - pixy.blocks[0].x) / 2);
    else
      xPosCentroPalla = (pixy.blocks[0].x - 159) / 2;

    yCentroPalla = (199 - pixy.blocks[0].y) * 2;

    double calcolo = double(xPosCentroPalla) / double(yCentroPalla);
    vNordMagicSmoke = atan( calcolo ) * 180 / PI;

    if (vNordMagicSmoke < 0) vNordMagicSmoke = 360 + vNordMagicSmoke;


  }
  else usoPixy = 0, rgb(0, 0, 0);

  pixyMillis=millis();
  }

  //display.fillRect(0,0,128,128,GREEN);
}



void test2()
{
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];
  int xPosCentroPalla, yCentroPalla;
currentMillis=millis();
  if (currentMillis - pixyMillis > 30) {

    // grab blocks!
    blocks = pixy.getBlocks();
    Serial.println(blocks);
   

    // If there are detect blocks, print them!
    if (blocks)
    {

      sprintf(buf, "Detected %d:\n", blocks);
      Serial.print(buf);
      for (j = 0; j < blocks; j++)
      {
        // sprintf(buf, "  block %d: ", j);
        // Serial.print(buf);
        // pixy.blocks[j].print();


        if ((blocks >= 1) && (pixy.blocks[j].signature == firmaColore)) {
          Serial.println("la firma è 1");
          usoPixy = 1;
          rgb(255, 50, 0);

          if (pixy.blocks[j].x <= 159)
            xPosCentroPalla = -((159 - pixy.blocks[j].x) / 2);
          else
            xPosCentroPalla = (pixy.blocks[j].x - 159) / 2;

          yCentroPalla = (199 - pixy.blocks[j].y) * 2;

          double calcolo = double(xPosCentroPalla) / double(yCentroPalla);
          vNordMagicSmoke = (atan( calcolo ) * 180 / PI) * 3;

          // if (vNordMagicSmoke < 0) vNordMagicSmoke = 360 + vNordMagicSmoke;



        }

      }
    }
    else usoPixy = 0, rgb(0, 0, 0);
    pixyMillis=millis();
  }
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void esempio()
{
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];

  // grab blocks!
  blocks = pixy.getBlocks();

  // If there are detect blocks, print them!
  if (blocks)
  {

    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    sprintf(buf, "Detected %d:\n", blocks);
    Serial.print(buf);
    for (j = 0; j < blocks; j++)
    {
      sprintf(buf, "  block %d: ", j);
      Serial.print(buf);
      pixy.blocks[j].print();
      //Serial.println(blocks);
      /*int x = map(pixy.blocks[j].x,0,319,0,128);
      int y = map(pixy.blocks[j].y,0,199,0,128);
      int xSize = map(pixy.blocks[j].width,1,320,1,128);
      int ySize = map(pixy.blocks[j].height,1,200,1,128);
      display.fillRect(x,y,x+xSize,y+ySize,YELLOW);*/
    }
  }
}
