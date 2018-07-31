void usBegin(){
  pinMode(startUSread, OUTPUT);


  delay(500);                       // aspetto che completi il primo ciclo di calibrazione (250ms)
  digitalWrite(startUSread,HIGH);  // Da datasheet, tenere alto per un tempo maggiore di 20us e minore di 49ms per iniziare le letture
  delay(20);
  //digitalWrite(startUSread,LOW);
}

void readUs(){
  distAx=analogRead(usAx)*1.27;
  distPx=analogRead(usPx)*1.27;    
  distSx=analogRead(usSx)*1.27;    
  distDx=analogRead(usDx)*1.27;  
}

