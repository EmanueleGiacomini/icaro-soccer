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
int _output[4];//output
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
  unsigned int _ttl;// Time-To-Live della traiettoria di fuga
   LineSensor * _LineSensor;//LineSensor
   int _posLinee[16];
   int num_linee=0;
   int letture[4];

  void attivaCorrezione(int dir)
  {
    _escapeflag=true;
    // porta escape_flag a 1
    _escape_dir=dir;
    // imposta la direzione di fuga a dir
  }

  void reset()
  {
    _escapeflag=false;
    // Resetta escape_flag a 0

    // imposta ttl a
        //SaraU:a cosa?
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
            if(line_live[i][j] != letture[j])
            {
              num_linee++;

              double angolo = (letture[j]* 71 ) / 4068;//conversione in radianti
              sommaX+=cos(angolo);
              //cosa+cos0+cosb;
              sommaY+=sin(angolo);
              //sina+sin0+sinb;

              _escape_dir=atan2(sommaY, sommaX);
              _escape_dir=(_escape_dir * 4068)/71;
              _escape_dir=circConstraint(escape_dir + 180, 0, 360);

              _escapeflag=true;

            }

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

    int getDirezioneFuga()
    {
      return _escape_dir;
    }

    unsigned int getTTL();//non ho capito come devo modificarla
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
};
