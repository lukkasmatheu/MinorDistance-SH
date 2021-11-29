/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/

#include "libsTrabalho.h"

void desalocaMatriz(int **mat, int lin, int col)
{
  int i;
  for (i = 0; i < lin; i++)
  {
    free(mat[i]);
  }
  free(mat);
}
