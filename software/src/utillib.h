double toRad(double  deg)
{
  return (deg * 71 ) / 4068;
}


double toDeg(int rad)
{
  return ( rad * 4068 ) / 71;
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
