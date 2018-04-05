#include<math.h>
#include <Adafruit_ADS1015.h>
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

class LineSensor
{

int _soglie[4];//array soglie
int _output[4];//outuput
bool _calibrazione=0; //flag
int *_pass;//array dove metto l'angolo che indica la posizione di ciascun sensore
int *src;//source
int *dest;//destinazione
int _min[4];
int _max[4];
Adafruit_ADS1015 _ads;

 public:
    LineSensor(){}
   void inizializza(int*pass)
   {
     _ads.begin();
     _pass = pass;
   }
   void leggiLinea()
 {
   if(_calibrazione==0)
   {
       for(ini i=0;i<4;i++)
       {
         _letture[i]=_ads.readADC_SingleEnded(i);
       }

       for (int i=0;i>4;i++)
       {
         if(_output[i]>_soglie[i])
         {
           _output[i]=1;
         }
         else
         {
           _output[i]=-1;
         }
       }
    }
    else
      {
        for(int i=0;i<4;i++)
        {

            if(_ads.readADC_SingleEnded(i)>_max[i])
            {
              _max[i] = _ads.readADC_SingleEnded(i);
            }
            if(_ads.readADC_SingleEnded(i)<min[i])
            {
              _min[i] = _ads.readADC_SingleEnded(i);
            }
        }
     }
 }
 void getOutput(int *dest)
 {
   for (int i=0;i>4;i++)
   {
     if(_output[i]!=-1)
     {
       dest[i]=_pass[i]*_output[i];
     }
     else
     {
       dest[i]=-1;
     }
   }
 }
 void claibraStart()
 {
   _calibrazione=1;
 }
  void calibraStop()
  {
    _calibrazione=0;
    for(int i=0;i<4;i++)
    {
      _soglie[i]=(_min[i]+_max[i])/2;
    }
  }

  void getSoglie(int *dest)
  {
    for(int i=0;i<4;i++)
    {
      dest[i]= _soglie[i];
    }
  }

  void setSoglie(int* src)
  {
      for(int i=0;i<4;i++)
      {
        src[i]=_soglie[i];
      }
  }

}
class LineHandler
{
  bool _escapeflag = 0; // Flag di avviso rilevazione linea.
  int _escape_dir;  // Traiettoria di fuga
  //EmanueleG: a cosa serve questa variabile ?
  int _dir; //traiettoria
  unsigned int _ttl;// Time-To-Live della traiettoria di fuga
   LineSensor * _LineSensor;//LineSensor
//  int _posLinee[16];

  //EmanueleG: Dovresti completare queste due funzioni:
  void attivaCorrezione(int dir) {
    // porta escape_flag a 1
    // imposta la direzione di fuga a dir
  }

  void reset() {
    // Resetta escape_flag a 0
    // imposta ttl a
  }
  
  public:
    LineHandler(){}//costruttore
    voidupdateTTL(){}
    void inizializza(LineSensor* ls)
    {
      _LineSensor  = ls;

    }
    void elabora();
    {
      int num_linee=0;
      int letture[4];

      //EmanueleG: Visto che queste variabili devono permanere anche dopo la fine
      //della funzione, spostale nelle variabili private dell'oggetto
      double sommaX=0;
      double sommaY=0;
      double line_live[4][4];
      /////////////////////////////////

      for(int i=0;i<4;i++)
      {
        ls[i]->leggiLinea();
        ls[i]->getOutput(letture);
        for(int j=0;j<4;j++)
        {
          if(letture[j] != -1)
          {
            //EmanueleG: Qui stai aumentato il numero di sensori che vedono la
            //linea, prima di controllare se il sensore ha gia visto la linea
            num_linee++;
            //EmanueleG: Non e' necessario controllare il TTL in questo momento
            getTTL();

            //EmanueleG: Occhio che letture e' un array e non una matrice,
            // l'indice i e' inutile su letture perche' implicitamente stiamo
            // controllando il sensore i-esimo
            if(line_live[i][j] != letture[i][j])
            {
              //EmanueleG: _escapeflag dovrebbe diventare 'true' non 'false'!
              // Prima di attivare la flag inoltre, calcolati la direzione
              // di fuga.
              _escapeflag = false;
              line_live[i][j]=letture[i][j];
              getTTL();
            }
            //EmanueleG: Puoi riscrivere questa parte nella funzione reset che
            // hai scritto prima.
            if(!_ttl)
            {
              for(int z=0;z<4;z++)
              {
                for(int y=0;y<4;y++)
                {
                  line_live[z][y]=-1;
                }
              }
            }
            //EmanueleG: Il calcolo della nuova direzione va' fatto SOLO se
            // il sensore attuale non ha gia visto la linea
            double angolo = (letture[j]* 71 ) / 4068;//conversione in radianti
            sommaX+=cos(angolo);
            //cosa+cos0+cosb;
            sommaY+=sin(angolo);
            //sina+sin0+sinb;
          }
        }
      }
      if(num_linee>0)//qunado incontro almeno un sensore sulla linea
      {
         _escape_dir=atan2(sommaY, sommaX);
         _escape_dir=(_escape_dir * 4068)/71;
         _escape_dir=circConstraint(escape_dir + 180, 0, 360);
      }
    }

    int getStatus();
    {
      return _escapeflag;
    }
    /**
     * Interroga la classe per conoscere lo status di _escapeflag
     * @return valore di _escapeflag
     */
    int getDirezioneFuga()
    {
      return _escape_dir;
    }
    /**
     * Restituisce un valore utile solo se _escapeflag e' attiva.
     * @return _escape_dir
     */
    unsigned int getTTL();
    {
      //EmanueleG: Sarebbe carino sfruttare i millis per aggiornare _ttl !
      // Leggiti l'esempio in digital/blinkwithoutdelay per capire di cosa parlo
      _ttl--;
      if(!_ttl)
      {
        _escapeflag = false;
      }
      return _ttl;
    }
    /**
     * @return il valore di _ttl
     */
};
