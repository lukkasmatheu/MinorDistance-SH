/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/

#include "libsTrabalho.h"
int **copiaMatriz(int **mat, int lin, int col)
{
  int i, j;
  int **matcopia = alocaMatriz(lin, col);
  for (i = 0; i < lin; i++)
  {
    for (j = 0; j < col; j++)
    {
      matcopia[i][j] = mat[i][j];
    }
  }
  return matcopia;
}
