/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/

#include "libsTrabalho.h"
int **alocaMatriz(int lin, int col)
{
   int i;
   int **mat = (int **)malloc(lin * sizeof(int *));
   for (i = 0; i < lin; i++)
   {
      mat[i] = (int *)malloc(col * sizeof(int));
   }
   return mat;
}
