#include <PID_v1.h>//libreria del pid proporzionalità integrali e derivate

#include <Adafruit_Sensor.h>// semplifica la lettura dei sensori

#include <Adafruit_BNO055.h>//funzioni per leggere il sensore

Adafruit_BNO055 bno= Adafruit_BNO055(55);

double setpoint,input,output;
double Kp=0.5, Ki=1, Kd=1;
PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

void setup() 
{
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255, 255);
  myPID.SetSampleTime(20);
  Serial.begin(9600);
  Serial.println("Seriale inizializzata");
  if (!bno.begin())
  {
    Serial.println("BNO055 non inizializzato");
    while (1);
  }
    Serial.println("BNO005 inizializzata");
    delay(1000);

}





void loop() 
{
  sensors_event_t event;
  bno.getEvent(&event);
  input=circConstraint(event.orientation.x,-180,180);
  myPID.Compute();
  Serial.print(input);
  Serial.print("\t");
  Serial.println(output);
}

float circConstraint(float f, int min, int max)
{
  int intervallo = max-min;
  if(f<min)
  {
    f+=intervallo;
  }
  if(f>max)
  {
    f-=intervallo;
  }
  return f;
}

