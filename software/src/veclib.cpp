/*
  veclib.h
  Useful functions for vector and matrix manipulation.

  @author
  @version
*/

/*
  ########## Guida all'utilizzo ##########
  - Possono essere sviluppate le funzioni la cui intestazione
    e' stata precedentemente inserita in veclib.h
*/

#include "veclib.h"
void vecSum(int A[] int B[], int dim)
{
  for(int i = 0; i < dim; i++){
    B[i] = A[i]+B[i];
  }
}
void vecSub(int A[] int B[], int dim)
{
  for(int i = 0; i < dim; i++){
    B[i] = B[i]-A[i];
  }
}
int vecScalarMult(int A[], int B[], int dim)
{
  int s=0;
  for(int i = 0; i < dim; i++)
  {
    s = s+(A[i]* B[i]);
  }
  return s;
}
void vecMult(int A[], int B[], int dim)
{
  int B[dim];
  for(int i = 0; i < dim; i++){
    B[i] = B[i]*A[i];
  }
}
