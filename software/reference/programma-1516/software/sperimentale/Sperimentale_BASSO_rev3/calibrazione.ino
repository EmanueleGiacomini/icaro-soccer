void calibrazione() {
  delay(100);
  rgb(255, 0, 255);

  pulisciArrayDistanze();

  Serial1.clear();
  while (Serial1.available() < 1) {
  }
  delay(10);
  Serial1.clear();
  rgb(255, 0, 0);
  while (Serial1.available() < 1) { /// aspetto altro byte

    leggiSensoriPalla();

    for (int i = 0; i <= 19; i++) {
      if (valPalla[i] < distanzaZero[i]) {
        distanzaZero[i] = valPalla[i];
      }
    }
  } // serial available
  delay(500);
  Serial.println("\ndistanza 0 =");
  for (int i = 0; i <= 19; i++) {
    Serial.print(distanzaZero[i]);
    Serial.print(" - ");
    delay(10);
  }
  /////////////////////////////////////////////////////////////////////////////////////

  Serial1.clear();
  while (Serial1.available() < 1) {
  }
  delay(10);
  Serial1.clear();
  rgb(0, 255, 0);
  while (Serial1.available() < 1) { /// aspetto altro byte

    leggiSensoriPalla();

    for (int i = 0; i <= 19; i++) {
      if (valPalla[i] < distanzaUno[i]) {
        distanzaUno[i] = valPalla[i];
      }
    }
  } // serial available
  delay(500);
  /////////////////////////////////////////////////////////////////////////////////////

  Serial1.clear();
  while (Serial1.available() < 1) {
  }
  delay(10);
  Serial1.clear();
  rgb(0, 0, 255);
  while (Serial1.available() < 1) { /// aspetto altro byte

    leggiSensoriPalla();

    for (int i = 0; i <= 19; i++) {
      if (valPalla[i] < distanzaDue[i]) {
        distanzaDue[i] = valPalla[i];
      }
    }
  } // serial available
  delay(500);
  /////////////////////////////////////////////////////////////////////////////////////
//  Serial1.clear();
//  while (Serial1.available() < 1) {
//  }
//  delay(10);
//  Serial1.clear();
//  rgb(255, 255, 0);
//  while (Serial1.available() < 1) { /// aspetto altro byte
//
//    leggiSensoriPalla();
//
//    for (int i = 0; i <= 19; i++) {
//      if (valPalla[i] < distanzaTre[i]) {
//        distanzaTre[i] = valPalla[i];
//      }
//    }
//  } // serial available
//  delay(1000);
//  Serial1.clear();

  salvaSuEEPROM();
}//calibrazione




/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void leggiSensoriPalla() {

  currentMillis = millis();
  prevMillisPalla = millis();
  contatoreCalibrazione = 0;
  
  while (currentMillis - prevMillisPalla < 3) {
    contatoreCalibrazione++;
    for (int x = 0; x <= 8; x++)
    {
      valPalla[x] += analogRead(sensPalla[x]);
      if (x == 8)
      {
        for (int pallamux = 1; pallamux <= 4; pallamux++)
        {
          intToBin(pallamux);
          valPalla[pallamux + 8] += analogRead(A0);
        }
      }
    }
    for (int x = 13; x <= 19; x++)
    {
      valPalla[x] += analogRead(sensPalla[x - 4]);
    }

    for (byte i = 0; i <= 19; i++) {

      Serial.print(valPalla[i]);
      Serial.print(" -\t");
    }
    Serial.println();

    currentMillis = millis();
  }
  for (int i = 0; i <= 19; i++) {
    valPalla[i] = valPalla[i] /  contatoreCalibrazione;
  }
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void pulisciArrayDistanze() {
  for (int i = 0; i <= 19; i++) {
    distanzaZero[i] = 1023;
    distanzaUno[i]  = 1023;
    distanzaDue[i]  = 1023;
    distanzaTre[i]  = 1023;
  }
}

/////////////////////////////////////////////////////////////////////////////////////       //*/*/*/*//
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void salvaSuEEPROM() {
  Serial.println("Distanza Zero (vicino)");
  for (int i = 0; i <= 19; i++) {
    EEPROM.write(i, ((distanzaZero[i] >> 8) & 255) );
    EEPROM.write(i + 20, (distanzaZero[i] & 255));

    Serial.print(distanzaZero[i]);
    Serial.print(" - ");
    delay(10);
  }
  Serial.println();

  Serial.println("Distanza Uno");
  for (int i = 0; i <= 19; i++) {
    EEPROM.write(i + 40, ((distanzaUno[i] >> 8) & 255) );
    EEPROM.write(i + 60, (distanzaUno[i] & 255));
    Serial.print(distanzaUno[i]);
    Serial.print(" - ");
    delay(10);

  }
  Serial.println();

  Serial.println("Distanza Due");
  for (int i = 0; i <= 19; i++) {
    EEPROM.write(i + 80, ((distanzaDue[i] >> 8) & 255) );
    EEPROM.write(i + 100, (distanzaDue[i] & 255));
    Serial.print(distanzaDue[i]);
    Serial.print(" - ");
    delay(10);

  }
  Serial.println();

  Serial.println("Distanza Tre");
  for (int i = 0; i <= 19; i++) {
    EEPROM.write(i + 120, ((distanzaTre[i] >> 8) & 255) );
    EEPROM.write(i + 140, (distanzaTre[i] & 255));
    Serial.print(distanzaTre[i]);
    Serial.print(" - ");
    delay(10);

  }
  Serial.println("\nCalibrazione completata, salvo i valori sull'eeprom");
  Serial.println("\n\n");
  delay(3000);
}



/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


void leggiDistanzeEEPROM() {
  byte letturaByteHigh = 0;
  byte letturaByteLow  = 0;

  for (int i = 0; i <= 19; i++) {
    letturaByteHigh = EEPROM.read(i);
    letturaByteLow  = EEPROM.read(i + 20);
    distanzaZero[i] = letturaByteHigh << 8 | letturaByteLow;
    Serial.print(distanzaZero[i]);
    Serial.print(" - ");
  }
  Serial.println();
  for (int i = 0; i <= 19; i++) {
    letturaByteHigh = EEPROM.read(i + 40);
    letturaByteLow  = EEPROM.read(i + 60);
    distanzaUno[i] = letturaByteHigh << 8 | letturaByteLow;
    Serial.print(distanzaUno[i]);
    Serial.print(" - ");
  }
  Serial.println();
  for (int i = 0; i <= 19; i++) {
    letturaByteHigh = EEPROM.read(i + 80);
    letturaByteLow  = EEPROM.read(i + 100);
    distanzaDue[i] = letturaByteHigh << 8 | letturaByteLow;
    Serial.print(distanzaDue[i]);
    Serial.print(" - ");
  }
  Serial.println();
  for (int i = 0; i <= 19; i++) {
    letturaByteHigh = EEPROM.read(i + 120);
    letturaByteLow  = EEPROM.read(i + 140);
    distanzaTre[i] = letturaByteHigh << 8 | letturaByteLow;
    Serial.print(distanzaTre[i]);
    Serial.print(" - ");
  }
  Serial.println();


}


