void leggiSerialeUno() {

  Serial1.clear();
  Serial1.write('r');
  delay(1);
  
  if (Serial1.available()>=5) {
    
    posPalla = Serial1.read();
    distanzaPalla = Serial1.read();

    distanzaPx = Serial1.read();
    
    distanzaDx = Serial1.read();
    distanzaAx = Serial1.read();
    distanzaSx = Serial1.read();

  }
}
