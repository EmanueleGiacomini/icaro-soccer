



const int sensPallaDir[] = {0, 12, 25, 38, 51, 64, 77, 90, 120, 150, 180, 210, 240, 270, 282, 295, 308, 321, 334, 347};


// la funzione getPalla assegna alla variabile traiettoriaPalla , la direzione che il robot deve prendere per riuscire
// a raggiungere la palla con la giusta angolazione
void getPalla()
{
  leggiSerialeUno();

  if (posPalla != 99)
  {
    if (posPalla > 1 && posPalla <= 10)
    {
      traiettoriaPalla = sensPallaDir[(posPalla + 1) + (2 - distanzaPalla)];
    }
    else if (posPalla > 10 && posPalla < 19)
    {
      traiettoriaPalla = sensPallaDir[(posPalla - 1) - (2 - distanzaPalla)];
    }
    switch (posPalla)
    {
      case 0:
        traiettoriaPalla = 0, vel = VELOCITA_ATTACCO;
        usoPixy = 1;
        break;
      case 1:
        traiettoriaPalla = 0, vel = VELOCITA_ATTACCO;
        usoPixy = 1;
        break;
      case 19:
        traiettoriaPalla = 0, vel = VELOCITA_ATTACCO;
        usoPixy = 1;
        break;
    }
  }
  else
  {
    traiettoriaPalla = 180;
    distanzaPalla = 0;
  }
  moveRobot(traiettoriaPalla, 0, vel, 1);
  vel = VELOCITA;

  Serial.print("sensPalla= ");
  Serial.print(posPalla);
  Serial.print("\tdirezione = ");
  Serial.println(traiettoriaPalla);
}


unsigned long tempo99 = 0;
boolean caso;
void getPalla1()
{
  leggiSerialeUno();
  switch (posPalla)
  {
    case 0:
      traiettoriaPalla = 0;
      vel = VELOCITA_ATTACCO;
      break;
    case 1:
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = 35;
          vel = VELOCITA_ATTACCO;
          break;
        case 1:
          traiettoriaPalla = 20;
          break;
        case 2:
          traiettoriaPalla = 0;
          break;
      }
      break;
    case 2:
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = 20;
          break;
        case 1:
          traiettoriaPalla = 35;
          break;
        case 2:
          traiettoriaPalla = 40;
          break;
      }
      break;
    case 3:
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = 120;
          break;
        case 1:
          traiettoriaPalla = 95;
          break;
        case 2:
          traiettoriaPalla = 38;
          break;
      }
      break;
    case 4:
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = 170;
          break;
        case 1:
          traiettoriaPalla = 105;
          break;
        case 2:
          traiettoriaPalla = 60;
          break;
      }
      break;
    case 5:
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = 160;
          break;
        case 1:
          traiettoriaPalla = 100;
          break;
        case 2:
          traiettoriaPalla = 62;
          break;
      }
      break;
    case 6:
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = 170;
          break;
        case 1:
          traiettoriaPalla = 120;
          break;
        case 2:
          traiettoriaPalla = 90;
          break;
      }
      break;
    case 7:
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = 180;
          break;
        case 1:
          traiettoriaPalla = 135;
          break;
        case 2:
          traiettoriaPalla = 95;
          break;
      }
      break;
    case 8:
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = 195;
          break;
        case 1:
          traiettoriaPalla = 160;
          break;
        case 2:
          traiettoriaPalla = 105;
          break;
      }
      break;
    case 9:
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = 210;
          break;
        case 1:
          traiettoriaPalla = 195;
          break;
        case 2:
          traiettoriaPalla = 180;
          break;
      }
      break;
    case 10:
      switch (distanzaPalla)
      {
        case 0:
          if (currentMillis - tempo99 > 400) caso = random(0, 1), tempo99 = millis();
          if (caso) traiettoriaPalla = 270;
          else traiettoriaPalla = 90;

          break;
        case 1:
          traiettoriaPalla = 180;
          break;
        case 2:
          traiettoriaPalla = 180;
          break;
      }
      break;
    case 11: //9
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = -210;
          break;
        case 1:
          traiettoriaPalla = -195;
          break;
        case 2:
          traiettoriaPalla = -180;
          break;
      }
      break;
    case 12://8
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = -195;
          break;
        case 1:
          traiettoriaPalla = -160;
          break;
        case 2:
          traiettoriaPalla = -105;
          break;
      }
      break;
    case 13://7
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = -180;
          break;
        case 1:
          traiettoriaPalla = -135;
          break;
        case 2:
          traiettoriaPalla = -95;
          break;
      }
      break;
    case 14://6
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = -170;
          break;
        case 1:
          traiettoriaPalla = -120;
          break;
        case 2:
          traiettoriaPalla = -90;
          break;
      }
      break;
    case 15://5
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = -160;
          break;
        case 1:
          traiettoriaPalla = -100;
          break;
        case 2:
          traiettoriaPalla = -62;
          break;
      }
      break;
    case 16://4
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = -170;
          break;
        case 1:
          traiettoriaPalla = -105;
          break;
        case 2:
          traiettoriaPalla = -60;
          break;
      }
      break;
    case 17://3
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = -120;
          break;
        case 1:
          traiettoriaPalla = -95;
          break;
        case 2:
          traiettoriaPalla = -38;
          break;
      }
      break;
    case 18://2
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = -20;
          break;
        case 1:
          traiettoriaPalla = -35;
          break;
        case 2:
          traiettoriaPalla = -40;
          break;
      }
      break;
    case 19://1
      switch (distanzaPalla)
      {
        case 0:
          traiettoriaPalla = -35;
          vel = VELOCITA_ATTACCO;
          break;
        case 1:
          traiettoriaPalla = -20;
          break;
        case 2:
          traiettoriaPalla = 0;
          break;
      }
      break;


    case 99:
      traiettoriaPalla = -1;
      break;
  }
  moveRobot(traiettoriaPalla, 0, vel, 1);
  vel = VELOCITA;
  Serial.print("sensPalla= ");
  Serial.print(posPalla);
  Serial.print("\tdirezione = ");
  Serial.println(traiettoriaPalla);

}
