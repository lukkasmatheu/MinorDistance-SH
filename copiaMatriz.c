#include "libsTrabalho.h"
double **copiaMatrizImagem(double **mat, int lin, int col)
{
  int i, j;
  double **matcopia = alocaMatrizImagem(lin, col);
  for (i = 0; i < lin; i++)
  {
    for (j = 0; j < col; j++)
    {
      matcopia[i][j] = mat[i][j];
    }
  }
  return matcopia;
}
