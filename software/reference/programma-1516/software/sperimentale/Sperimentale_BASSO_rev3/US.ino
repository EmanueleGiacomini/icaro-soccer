void usBegin()
{
  pinMode(startUSread, OUTPUT);
  delay(500);                       // aspetto che completi il primo ciclo di calibrazione (250ms)
  digitalWrite(startUSread,HIGH);  // Da datasheet, tenere alto per un tempo maggiore di 20us e minore di 49ms per iniziare le letture
  delay(20);
  digitalWrite(startUSread,LOW);
}

void readUs()
{
    valUs[0]=0;
    valUs[1]=0;   
    valUs[2]=0;    
    valUs[3]=0;

    for(int j=0; j<20; j++)
    {  
     for (int mux = 5; mux <= 8; mux++)
     {
      intToBin(mux);
      valUs[mux-5] += analogRead(A0);
     }
    }
      valUs[0]=(valUs[0]/20)*1.27;
      valUs[1]=(valUs[1]/20)*1.27;    
      valUs[2]=(valUs[2]/20)*1.27;    
      valUs[3]=(valUs[3]/20)*1.27;
      Serial.println(valUs[2]);
}

