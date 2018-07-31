
#define ledR 13
#define ledG 11
#define ledB 12

#define ledSmdB 22
#define ledSmdG 23


int Lin1 = A0;
int Lin2 = A1;
int Lin3 = A2;
int Lin4 = A3;
int Lin5 = A4;
int Lin6 = A5;
int Lin7 = A6;
int Lin8 = A7;
int Lin9 = A8;


int diagb4 = 42;
int diaga4 = 43;
int diagb3 = 44;
int diaga3 = 45;
int diagb2 = 46;
int diaga2 = 47;
int diagb1 = 48;
int diaga1 = 49;

int v[10];
int massimo;

int startUSread=4;  //inizia le letture continue degli ultrasuoni
int usAx= A14;
int usDx= A15;
int usPx= A12;
int usSx= A13;

int distAx, distPx, distDx, distSx; 

int valLin = 0;

String cancelletto = "#", str="abc", strTemp="abc";


void setup(){
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(diagb4, INPUT_PULLUP);
  pinMode(diaga4, INPUT_PULLUP);
  pinMode(diagb3, INPUT_PULLUP);
  pinMode(diaga3, INPUT_PULLUP);
  pinMode(diagb2, INPUT_PULLUP);
  pinMode(diaga2, INPUT_PULLUP);
  pinMode(diagb1, INPUT_PULLUP);
  pinMode(diaga1, INPUT_PULLUP);  

  pinMode(ledR, OUTPUT);   
  pinMode(ledG, OUTPUT); 
  pinMode(ledB, OUTPUT); 
  pinMode(ledSmdB, OUTPUT); 
  pinMode(ledSmdG, OUTPUT);

  usBegin();

}


void loop(){
//  Serial.print(analogRead(A0));
//   Serial.print("\t");
//   Serial.print(analogRead(A1));
//   Serial.print("\t");
//   Serial.print(analogRead(A2));
//   Serial.print("\t");
//   Serial.print(analogRead(A3));
//   Serial.print("\t");
//   Serial.print(analogRead(A4));
//   Serial.print("\t");
//   Serial.print(analogRead(A5));
//   Serial.print("\t");
//   Serial.print(analogRead(A6));
//   Serial.print("\t");
//   Serial.print(analogRead(A7));
//   Serial.print("\t");
//   Serial.print(analogRead(A8));
//   Serial.print("\t");
//   Serial.print(analogRead(A9));
//   Serial.print("\t");
//   Serial.print(analogRead(A10));
//   Serial.print("\t");
//   Serial.print(analogRead(A11));
//   Serial.println("\t");
   
     str = "";
     
     valLin = readLin();     
//   delay(400);
//   Serial.println("\n\n");
   
 
  digitalWrite(ledSmdG, 1);
  readUs();
  /*
  Serial.print(distAx);
   Serial.print("\t");
   Serial.print(distDx);
   Serial.print("\t");
   Serial.print(distPx);
   Serial.print("\t");
   Serial.println(distSx);
   */
  digitalWrite(ledSmdG, 0);


  str = str + "#";

  str = str + valLin;
  str = str + ",";
  str = str + massimo;
  str = str + ",";
  str = str + distAx;
  str = str + ",";
  str = str + distDx;
  str = str + ",";
  str = str + distPx;
  str = str + ",";
  str = str + distSx;
  str = str + ",";
  Serial.print ("str = ");
  Serial.println(str);

  analogWrite(ledB, 30);
  analogWrite(ledR, 30);
  digitalWrite(ledSmdB, 1);



  analogWrite(ledB, 0);
  analogWrite(ledR, 0);
  digitalWrite(ledSmdB, 0);

  delay(5);

}// loop

int readLin(){

  int i;
  int x;


  for(i=0; i<10; i++)
  {   
    v[i]=0;   
  }

  for(i=0; i<20; i++)
  {  
    v[0]+=analogRead(A0);
    v[1]+=analogRead(A1);
    v[2]+=analogRead(A2);
    v[3]+=analogRead(A3);
    v[4]+=analogRead(A4);
    v[5]+=analogRead(A5);
    v[6]+=analogRead(A6);
    v[7]+=analogRead(A7);
    v[8]+=analogRead(A8);
  }


  for(i=0; i<20; i++)  {   
    v[i] = v[i]/20;
  }
 


  if ((v[0]<1)&&(v[1]<1)&&(v[2]<1)&&(v[3]<1)&&(v[4]<1)&&(v[5]<1)&&(v[6]<1)&&(v[7]<1)&&(v[8]<1))
  {
    //Serial.println("non vedo la linee!");  
    return 99;
  }
  else
  {
    Serial.println(posLinea());
    return posLinea();
  }
} /// readLin






int posLinea(){   ////////////// trovo il valore minimo dell'array
  int linea = 0;
  massimo = v[0];
  for (int i=1; i<9; i++){
    if (massimo < v[i]){
      linea = i;
      massimo = v[i];
    }
  }
  return linea;
}


/*
int trovaMassimo(){
 int massimo = array[0];
 for (int i=1; i<arraySize; i++){
 if (massimo < array[i]){
 massimo = array[i];
 }
 }
 return massimo;
 }
 */






