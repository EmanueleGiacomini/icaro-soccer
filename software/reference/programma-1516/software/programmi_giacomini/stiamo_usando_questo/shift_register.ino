
void statoLed(byte nLed, boolean stato) {
  /*
  led 1  rosso
  led 2  bianco
  led 3  blu
  led 4  giallo

  led 5  giallo ax
  led 6  rosso  dx
  led 7  rosso  sx
  led 8  giallo px
  */

  /*
  Setting a bit
  Use the bitwise OR operator (|) to set a bit.

  number |= 1 << x;
  That will set bit x.

  Clearing a bit
  Use the bitwise AND operator (&) to clear a bit.

  number &= ~(1 << x);
  That will clear bit x. You must invert the bit string with the bitwise NOT operator (~), then AND it.

  Toggling a bit
  The XOR operator (^) can be used to toggle a bit.

  number ^= 1 << x;
  That will toggle bit x.

  Checking a bit
  You didn't ask for this but I might as well add it.

  To check a bit, shift the number x to the right, then bitwise AND it:

  bit = (number >> x) & 1;
  That will put the value of bit x into the variable bit.

  */


  switch (nLed) {
    case 1:
      if (stato)
        byteLed |= 1 << nLed - 1;
      else byteLed &= ~(1 << nLed - 1);
      break;
    case 2:
      if (stato)
        byteLed |= 1 << nLed - 1;
      else byteLed &= ~(1 << nLed - 1);
      break;
    case 3:
      if (stato)
        byteLed |= 1 << nLed - 1;
      else byteLed &= ~(1 << nLed - 1);
      break;
    case 4:
      if (stato)
        byteLed |= 1 << nLed - 1;
      else byteLed &= ~(1 << nLed - 1);
      break;
    case 5:
      if (stato)
        byteLed |= 1 << nLed - 1;
      else byteLed &= ~(1 << nLed - 1);
      break;
    case 6:
      if (stato)
        byteLed |= 1 << nLed - 1;
      else byteLed &= ~(1 << nLed - 1);
      break;
    case 7:
      if (stato)
        byteLed |= 1 << nLed - 1;
      else byteLed &= ~(1 << nLed - 1);
      break;
    case 8:
      if (stato)
        byteLed |= 1 << nLed - 1;
      else byteLed &= ~(1 << nLed - 1);
      break;
  }

}

void statoMotori(byte nPin, boolean stato)
{
  // DIREZIONI MOTORI

  /*
  int dir[] = {15,1,2,3,4,5,6,7};

  Index Array:
  0: INA1
  1: INB1
  2: INA2
  3: INB2
  4: INA3
  5: INB3
  6: INA4
  7: INB4
  */

  switch (nPin) {
    case 1:
      if (stato)
        byteMotori |= 1 << nPin - 1;
      else byteMotori &= ~(1 << nPin - 1);
      break;
    case 2:
      if (stato)
        byteMotori |= 1 << nPin - 1;
      else byteMotori &= ~(1 << nPin - 1);
      break;
    case 3:
      if (stato)
        byteMotori |= 1 << nPin - 1;
      else byteMotori &= ~(1 << nPin - 1);
      break;
    case 4:
      if (stato)
        byteMotori |= 1 << nPin - 1;
      else byteMotori &= ~(1 << nPin - 1);
      break;
    case 5:
      if (stato)
        byteMotori |= 1 << nPin - 1;
      else byteMotori &= ~(1 << nPin - 1);
      break;
    case 6:
      if (stato)
        byteMotori |= 1 << nPin - 1;
      else byteMotori &= ~(1 << nPin - 1);
      break;
    case 7:
      if (stato)
        byteMotori |= 1 << nPin - 1;
      else byteMotori &= ~(1 << nPin - 1);
      break;
    case 8:
      if (stato)
        byteMotori |= 1 << nPin - 1;
      else byteMotori &= ~(1 << nPin - 1);
      break;
  }



}

void shiftRegister_sendBytes()
{
  digitalWrite(latchPin, LOW);


  shiftOut(dataPin, clockPin, MSBFIRST, byteLed);
  shiftOut(dataPin, clockPin, MSBFIRST, byteMotori);

  digitalWrite(latchPin, HIGH);

}










