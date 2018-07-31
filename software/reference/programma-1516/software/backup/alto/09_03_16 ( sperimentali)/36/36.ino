/*
 .oooo.       .ooo   
.dP""Y88b    .88'     
      ]8P'  d88'      
    <88b.  d888P"Ybo. 
     `88b. Y88[   ]88 
o.   .88P  `Y88   88P 
`8bd88P'    `88bod8' 

Questo programma permetterà di leggere e calibrare i 36 sensori di linea del robot
Crazy right ?!
*/

//===========================================================================
//============================= Pin  ========================================
//===========================================================================

// MuxOut rappresentano i pin di uscita di ogni multiplexer
#define MUXOUT_1
#define MUXOUT_2
#define MUXOUT_3

//MUX_ rappresentano i pin di controllo dei multiplexer
// A = LSB --- D = MSB
#define MUX_A
#define MUX_B
#define MUX_C
#define MUX_D



//===========================================================================
//============================= Constants  ==================================
//===========================================================================

// Angoli in radianti di tutti i sensori di linea
const double gradi_Linee[] = {0,0.1745,0.3490,0.5236,0.6981,0.8727,1.0472,1.2217,1.3963,1.5708,1.74533,1.91986,2.0944,2.26893,2.44346,2.61799,2.79253,2.96706,3.14159,3.31613,3.49066,3.66519,3.83972,4.01426,4.36332,4.53786,4.71239,4.88692,5.06145,5.23599,5.41052,5.58505,5.75959,5.93412,6.10865};
//							  0,   10 ,  20  ,  30  ,  40  ,  50  ,  60  ,  70  ,  80  ,  90  ,  100  ,  110  ,  120 ,  130  ,  140  ,  150  ,	160  ,	170	 ,  180  ,	190  ,  200  ,  210  ,  220  ,  240  ,	250  ,	260  ,	270  ,  280  ,  290  ,  300  ,  310  ,  320  ,  330  ,  340  ,  350  ,
// Valori di soglia per ogni sensore
double soglia_Linee[36];

// Valori dei multiplexer
byte  bin[] = {B0000, B0001, B0010, B0011, B0100,B0101, B0110, B0111,B1000,B1001,B1010,B1011,B1100,B1101,B01101111};//list of binary value
boolean a = 0,b = 0,c = 0,d = 0;
/*
Index Array
0:ExpA
1:ExpB
2:ExpC
3:ExpD
*/


//===========================================================================
//============================= Variables  ==================================
//===========================================================================

// Variabili che contengono le componenti X,Y dei vettori
volatile long X = 0, Y = 0;






//===========================================================================
//============================= Functions  ==================================
//===========================================================================


// Multiplexer Selection function
void intToBin(byte var)
{
	int pos = bin[var];
	a = bitRead(pos,0);
	b = bitRead(pos,1);
	c = bitRead(pos,2);
	d = bitRead(pos,3);

	digitalWrite(MUX_D,d);
	digitalWrite(MUX_C,c);
	digitalWrite(MUX_B,b);
	digitalWrite(MUX_A,a);  
}

// Ogni multiplexer contiene 12 sensori ( da 0 a 11)

bool readMux()
{


}

bool readMux2()
{

}

bool readMux3()
{

}




// X = gradi_Linee[lettura]


void individuaLinee()
{
	for(int lettura=0;lettura < 12;lettura++)
	{
		if(readSensors() != 3 && readSensors() != 5 && readSensors() != 6) // Se non ci sono piu' sensori nello stesso 
		{
			X = cos()
		}

	}// for(int lettura=0;lettura < 36;lettura++)



}// void individuaLinee()


