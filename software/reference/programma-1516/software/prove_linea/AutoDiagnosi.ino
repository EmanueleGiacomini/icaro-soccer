void led(int r, int g, int b){
  analogWrite(ledR,r);
  analogWrite(ledG,g);
  analogWrite(ledB,b);
}
void ledOff(){
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,LOW);
}


void autoDiagnosi(){
  ledOff();
  
  // BATTERIA
  if(analogRead(batteria)<756){
    digitalWrite(ledBat, HIGH);
  }
  
  // MOTORI

//  muoviti(indietro,100,1);
  delay(5);
  for(int j=1;j<5;j++){
  if(leggiCorrenteMot(j)<100){
//    muoviti(fermo,255,1);
    led(0,128,255);
    delay(1000);
    ledOff();
    delay(10);
  }
  }
//  muoviti(fermo,255,1);
  
  // IR
  
  // US
  
  // LINEE
  
  //







}
