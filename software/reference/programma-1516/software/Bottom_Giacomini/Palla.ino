// Sensori Palla
//int sensPalla[] = {A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A15,A16,A17};
/*
Index Array
0: S1
1: S2
2: S3
3: S4
4: S5
5: S6
6: S7
7: S8
8: S9

AGGIUNGO SENSORI MUX NELLA LETTURA DI 8

9: S14
10: S15
11: S16
12: S17
13: S18
14: S19
15: S20


int valPalla[19];

ACCESSIBILE TRAMITE MUX
1 S10
2 S11
3 S12
4 S13

*/


void findPalla()
{
  
  for (int x = 0; x <= 8; x++)
  {
    Serial.print("Var n: ");
    Serial.print(x);
    valPalla[x] = analogRead(sensPalla[x]);
    Serial.print("  -  ");
    Serial.println(valPalla[x]);

    if (x == 8)
    {
      for (int pallamux = 1; pallamux <= 4; pallamux++)
      {
        Serial.print("Sensore n: ");
        Serial.print(pallamux + 8);
        intToBin(pallamux);
        valPalla[pallamux + 8] = analogRead(A0);
        Serial.print(" - ");
        Serial.println(valPalla[pallamux + 8]);
      }
    }

  }
  for (int x = 13; x <= 19; x++)
  {
    Serial.print("Var n: ");
    Serial.print(x);
    valPalla[x] = analogRead(sensPalla[x - 4]);
    Serial.print("  -  ");
    Serial.println(valPalla[x]);
  }

  for (int i = 0; i <= 19; i++)  {
    if (valPalla[i] < 10) {
      Serial.print("ERRORE !!  Problemi al sensore ");
      Serial.println(i);
    }
  }
  posPalla();
}




byte posPalla() {  ////////////// trovo il valore minimo dell'array
  int minimo = valPalla[0];
  for (int i = 0; i <= 19; i++) {
    if (minimo > valPalla[i]) {
      palla = i;
      minimo = valPalla[i];
    }
  }
  
  if(minimo>1000) palla = 99; /// non c'è la palla

  if (minimo <= distanzaZero[palla])     distanza = 0;
  else if (minimo <= distanzaUno[palla]) distanza = 1;
  else if (minimo <= distanzaDue[palla]) distanza = 2;
  else if (minimo <= distanzaTre[palla]) distanza = 3;

  return palla;
}





