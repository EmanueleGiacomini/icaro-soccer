/*

0000= 1020
0001= 217
0010= 460
0011= 172

0100= 608
0101= 190
0110= 353
0111= 155

1000= 765
1001= 203
1010= 401
1011= 163

1100= 510
1101= 179
1110= 317
1111= 148


*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////


void leggiDipSW(){

  int valoreDipSW=analogRead(A13);
  
  if((valoreDipSW <= constDipSW[0]+3) && (valoreDipSW >= constDipSW[0]-3))      aggiornaBoolDipSW(0,0,0,0);
  else if((valoreDipSW <= constDipSW[1]+3) && (valoreDipSW >= constDipSW[1]-3)) aggiornaBoolDipSW(0,0,0,1);
  else if((valoreDipSW <= constDipSW[2]+3) && (valoreDipSW >= constDipSW[2]-3)) aggiornaBoolDipSW(0,0,1,0);
  else if((valoreDipSW <= constDipSW[3]+3) && (valoreDipSW >= constDipSW[3]-3)) aggiornaBoolDipSW(0,0,1,1);
  
  else if((valoreDipSW <= constDipSW[4]+3) && (valoreDipSW >= constDipSW[4]-3)) aggiornaBoolDipSW(0,1,0,0);
  else if((valoreDipSW <= constDipSW[5]+3) && (valoreDipSW >= constDipSW[5]-3)) aggiornaBoolDipSW(0,1,0,1);
  else if((valoreDipSW <= constDipSW[6]+3) && (valoreDipSW >= constDipSW[6]-3)) aggiornaBoolDipSW(0,1,1,0);
  else if((valoreDipSW <= constDipSW[7]+3) && (valoreDipSW >= constDipSW[7]-3)) aggiornaBoolDipSW(0,1,1,1);
  
  else if((valoreDipSW <= constDipSW[8]+3) && (valoreDipSW >= constDipSW[8]-3))   aggiornaBoolDipSW(1,0,0,0);
  else if((valoreDipSW <= constDipSW[9]+3) && (valoreDipSW >= constDipSW[9]-3))   aggiornaBoolDipSW(1,0,0,1);
  else if((valoreDipSW <= constDipSW[10]+3) && (valoreDipSW >= constDipSW[10]-3)) aggiornaBoolDipSW(1,0,1,0);
  else if((valoreDipSW <= constDipSW[11]+3) && (valoreDipSW >= constDipSW[11]-3)) aggiornaBoolDipSW(1,0,1,1);
  
  else if((valoreDipSW <= constDipSW[12]+3) && (valoreDipSW >= constDipSW[12]-3)) aggiornaBoolDipSW(1,1,0,0);
  else if((valoreDipSW <= constDipSW[13]+3) && (valoreDipSW >= constDipSW[13]-3)) aggiornaBoolDipSW(1,1,0,1);
  else if((valoreDipSW <= constDipSW[14]+3) && (valoreDipSW >= constDipSW[14]-3)) aggiornaBoolDipSW(1,1,1,0);
  else if((valoreDipSW <= constDipSW[15]+3) && (valoreDipSW >= constDipSW[15]-3)) aggiornaBoolDipSW(1,1,1,1);

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////



void aggiornaBoolDipSW(boolean dipUno, boolean dipDue, boolean dipTre, boolean dipQuattro){
 dipSW1=dipUno;
 dipSW2=dipDue;
 dipSW3=dipTre;
 dipSW4=dipQuattro;
}
