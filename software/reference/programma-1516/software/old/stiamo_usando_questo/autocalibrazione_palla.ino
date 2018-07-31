
void autocalibrazionePalla() {
  Serial1.write('c');
  while (digitalRead(sel) == HIGH) {
  }
  //fare un beep o accendere un led
  delay(1000);

  Serial1.write(1);// invio al sotto il comando di iniziare la calibrazione

  moveRobot(-2, 50, 100, 0);
  delay(10000);
  moveRobot(-1, 0, 0, 0);
  Serial1.write(1);


  while (digitalRead(sel) == HIGH) {
  }
  //fare un beep o accendere un led
  delay(1000);

  Serial1.write(1);// invio secondo comando

  moveRobot(-2, 50, 100, 0);
  delay(10000);
  moveRobot(-1, 0, 0, 0);
  Serial1.write(1);

  while (digitalRead(sel) == HIGH) {
  }
  //fare un beep o accendere un led
  delay(1000);

  Serial1.write(1);// invio terzo comando

  moveRobot(-2, 50, 100, 0);
  delay(10000);
  moveRobot(-1, 0, 0, 0);
  Serial1.write(1);
}
