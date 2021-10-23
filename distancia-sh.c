//Implementação do algoritmo de Shamos e Hoey para encontrar a menor distancia entre dois pontos em um plano.
#include "libsTrabalho.h"

void distanciaMinimaSH(double **mat, int tamanho, int *first, int *second)
{
    double **aux = alocaMatriz(tamanho, 2);
    mergeSort(mat, 0, tamanho, aux);
    desalocaMatriz(aux, tamanho, 2);
}

// posivel solução

/*
1º Ordenar os pontos de acordo com as coordenadas x;
2ºDividir o grupo de pontos em dois subgrupos de mesmo tamanho por uma linha vertical {\displaystyle x=x_{mid}}{\displaystyle x=x_{mid}}
3ºResolver o problema recursivamente para os dois grupos, resultando nas distâncias mínimas nos lados esquerdos e direitos,  d_{Emin} e  d_{Dmin} respectivamente.
4ºEncontrar a distância mínima {\displaystyle d_{EDmin}}{\displaystyle d_{EDmin}} entre um par de pontos onde cada ponto está em um lado diferente da linha vertical.
5º A resposta final é o mínimo entre d_{Emin} d_{Dmin}, and  d_{EDmin}d_{EDmin}.*/