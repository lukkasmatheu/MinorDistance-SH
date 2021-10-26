#include "libsTrabalho.h"
double **alocaMatriz(int lin, int col)
{
   int i;
   double **mat = (double **)malloc(lin * sizeof(double *));
   for (i = 0; i < lin; i++)
   {
      mat[i] = (double *)malloc(col * sizeof(double));
   }
   return mat;
}
