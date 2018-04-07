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

void vecSet(int* vec, int dim, int n) {
  for(int i = 0 ; i < dim; i++) {
    vec[i] = n;
  }
}

void vecCpy(int* src, int* dest, int dim) {
  for(int i = 0; i < dim; i++) {
    dest[i] = src[i];
  }
}


void vecSum(int A[], int B[], int dim)
{
  for(int i = 0; i < dim; i++){
    B[i] = A[i]+B[i];
  }
}
void vecSub(int A[], int B[], int dim)
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
  for(int i = 0; i < dim; i++){
    B[i] = B[i]*A[i];
  }
}


void matSet(int** m, int dim, int n) {
  for(int i = 0; i < dim; i++) {
    for(int j = 0; j < dim; j++) {
      m[i][j] = n;
    }
  }
}