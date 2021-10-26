#include "libsTrabalho.h"
double **copiaMatriz(double **mat, int lin, int col)
{
  int i, j;
  double **matcopia = alocaMatriz(lin, col);
  for (i = 0; i < lin; i++)
  {
    for (j = 0; j < col; j++)
    {
      matcopia[i][j] = mat[i][j];
    }
  }
  return matcopia;
}
