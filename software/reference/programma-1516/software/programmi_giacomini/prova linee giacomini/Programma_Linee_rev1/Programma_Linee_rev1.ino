// Programma_Linee_rev1.ino

const int GradiExt[] = {80,100,170,190,260,280};
const int Esterni[] = { 22,23,24,25,26,27};
const int Interni[] = { 30,31,32};
int counterLinea = 0;
int sensoreA,sensoreB,sommaLinea,valoreLinea,triggerLinea;

// Pin Motori
const int PWM1 = 11, PWM2 = 10, PWM3 = 6, PWM4 = 3;   //PWM Motori
const int INA1 = 13, INB1 = 12, INB2 = 9, INA2 = 8, INA3 = 7, INB3 = 5,INB4 = 4,INA4 = 2; //Dir Motori
double vx, vy, rw;


void setup() 
{
  setupLinee();
  setupMotori();
}

void loop() {

  moveRobot(0,0,150,0);
  checkLine();

 
}




