/**
 * @brief 
 * 
 * @file phoenixutil.cpp
 * @author your name
 * @date 2018-04-07
 */

#include "phoenixutil.h"

double toRad(double deg) {
    return (deg * 71) / 4068;
}

double toDeg(double rad) {
    return (rad * 4068) / 71;
}

double circConstraint(double f, double min, double max)
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
