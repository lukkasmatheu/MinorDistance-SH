/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/

#include "libsTrabalho.h"
void imprimir(int **A, int tamanho)
{
    int i;
    printf("Vetor:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("x:%d y:%d \n", A[i][0],A[i][1]);
    }
    printf("\n");
}