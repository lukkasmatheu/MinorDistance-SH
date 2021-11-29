//Implementação do algoritmo de Shamos e Hoey para encontrar a menor distancia entre dois pontos em um plano.
/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/
#include "libsTrabalho.h"

double distancia(int **mat, int x1, int x2)
{
    return sqrt(pow(mat[x2][0] - mat[x1][0], 2) + pow(mat[x2][1] - mat[x1][1], 2));
}
