
/*
Index Array
0:ExpA
1:ExpB
2:ExpC
3:ExpD
*/
byte  bin [] = {B0000, B0001, B0010, B0011, B0100,B0101, B0110, B0111,B1000,B1001,B1010,B1011,B1100,B1101,B01101111};//list of binary value
boolean a = 0,b = 0,c = 0,d = 0;

void intToBin(byte var)
{
	int pos = bin[var];
	a = bitRead(pos,0);
	b = bitRead(pos,1);
	c = bitRead(pos,2);
	d = bitRead(pos,3);

/*	Serial.print(var);
	Serial.print(" - ");
	Serial.print(a);
	Serial.print(" - ");
	Serial.print(b);
	Serial.print(" - ");
	Serial.print(c);
	Serial.print(" - ");
	Serial.println(d);
	*/


	digitalWrite(mux[3],d);
	digitalWrite(mux[2],c);
	digitalWrite(mux[1],b);
	digitalWrite(mux[0],a);  
}
