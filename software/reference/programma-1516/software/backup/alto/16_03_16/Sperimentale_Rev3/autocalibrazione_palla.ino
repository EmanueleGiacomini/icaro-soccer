
void autocalibrazionePalla() {
  display.setTextColor(RED, BLACK);
  display.setTextSize(2);
  Serial1.clear();
  delay(2000);
  Serial1.write('c');


  display.fillRect(0, 0, 128, 128, BLACK);
  display.setCursor(0, 0);
  display.print("Distanza 0");
  display.setCursor(0, 50);
  display.setTextSize(1);
  display.print("premi il pulsante per avviare");

  while (analogRead(sel) > 99) {  /// lo switch dell'encoder può essere letto solo come analogico
  }
  //fare un beep o accendere un led
  delay(1000);

  Serial1.write(1);// invio al sotto il comando di iniziare la calibrazione
  display.setCursor(0, 90);
  display.print("Effettuo le letture");
  moveRobot(-2, 50, 30, 0);
  delay(10000);
  moveRobot(-1, 0, 0, 0);
  Serial1.write(1);



  display.fillRect(0, 0, 128, 128, BLACK);
  display.setTextColor(GREEN, BLACK);
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.print("Distanza 1");
  display.setCursor(0, 50);
  display.setTextSize(1);
  display.print("premi il pulsante per avviare");
  while (analogRead(sel) > 99) {
  }
  //fare un beep o accendere un led
  delay(1000);

  Serial1.write(1);// invio secondo comando
  display.setCursor(0, 90);
  display.print("Effettuo le letture");
  moveRobot(-2, 50, 30, 0);
  delay(10000);
  moveRobot(-1, 0, 0, 0);
  Serial1.write(1);


  display.fillRect(0, 0, 128, 128, BLACK);
  display.setTextColor(BLUE, BLACK);
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.print("Distanza 2");
  display.setCursor(0, 50);
  display.setTextSize(1);
  display.print("premi il pulsante per avviare");
  while (analogRead(sel) > 99) {
  }
  //fare un beep o accendere un led
  delay(1000);

  Serial1.write(1);// invio terzo comando
  display.setCursor(0, 90);
  display.print("Effettuo le letture");
  moveRobot(-2, 50, 30, 0);
  delay(10000);
  moveRobot(-1, 0, 0, 0);
  Serial1.write(1);




}
