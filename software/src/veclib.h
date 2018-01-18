/*
  veclib.h
  Useful functions for vector and matrix manipulation.

  @author
  @version
*/

/*
  ########## Guida all'utilizzo ##########
  - Poiche' il file e' un header (.h) bisogna inserire solo l'intestazione
    della funzione, il corpo viene composto nel file cpp (.cpp)

  - Ogni funzione relativa ai vettori deve iniziare con il prefisso 'vec'
    es: vecSum, vecMult, vecSet, ecc.

    Ogni funzione relativa alle matrici deve iniziare con il prefisso 'mat'
    es: matSum, matMult, matSet, ecc.

  -Ogni funzione richiede in ingresso almeno 3 parmetri:
    1) src: (sorgente) vettore sorgente
    2) dest: (destinazione) vettore di destinazione (Il risultato và qui)
    3) dim: (dimensione) la dimensione dei vettori (Ovviamente deve combaciare)
    Esempio:
    vecSum(int src[], int dest[], int dim);
*/

#ifndef veclib_h
#define veclib_h

int vecScalarMult(int A[], int B[], int dim);
void vecMult(int A[], int B[], int dim);
void vecSub(int A[] int B[], int dim);
void vecSum(int A[] int B[], int dim);
/*
  Da aggiungere:
  - Funzioni basiche matematiche sui vettori:
    1) Somma  (nome consigliato: vecSum)
    2) Sottrazione  (nome consigliato: vecSub)
    3) Moltiplicazione per un numero  (nome consigliato: vecScalarMult)
    4) Moltiplicazione fra vettori (un po' complessa)  (nome consigliato: vecMult)
*/

#endif
