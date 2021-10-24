//Implementação do algoritmo de Shamos e Hoey para encontrar a menor distancia entre dois pontos em um plano.
#include "libsTrabalho.h"
double combine(double **mat, double dE, double dD, int p1, int p2, int p3, int p4, int *first, int *second)
{
    double dP1P3 = distancia(mat, p1, p3);
    double dP1P4 = distancia(mat, p1, p4);
    double dP2P3 = distancia(mat, p2, p3);
    double dP2P4 = distancia(mat, p2, p4);
    double MenorDistance = dE;
    *first = p1;
    *second = p2;
    if (dD < MenorDistance)
    {
        *first = p3;
        *second = p4;
        MenorDistance = dE;
    }
    if (dP1P3 < MenorDistance)
    {
        *first = p1;
        *second = p3;
        MenorDistance = dP1P3;
    }
    if (dP1P4 < MenorDistance)
    {
        *first = p1;
        *second = p4;
        MenorDistance = dP1P4;
    }
    if (dP2P3 < MenorDistance)
    {
        *first = p2;
        *second = p3;
        MenorDistance = dP2P3;
    }
    if (dP2P4 < MenorDistance)
    {
        *first = p2;
        *second = p4;
        MenorDistance = dP2P4;
    }
    return MenorDistance;
}

void distanciaMinimaSH(double **mat, int tamanho, int *first, int *second, int *minorDistance)
{
    double **aux = alocaMatriz(tamanho, 2);

    mergeSort(mat, 0, tamanho, aux);

    *minorDistance = distaciaRecSH(mat, 0, tamanho, first, second);

    desalocaMatriz(aux, tamanho, 2);
}

double distaciaRecSH(double **mat, int p, int tam, int *first, int *second)
{
    if (tam <= p + 2)
    {
        if (tam == p + 1)
        {
            *first = p;
            *second = tam;
            return distancia(mat, p, tam);
        }
        else
        {
            *first = p;
            *second = tam;
            double minor = distancia(mat, p, tam);
            double aux = distancia(mat, p + 1, tam);
            double auxPD = distancia(mat, p, p + 1);
            if (aux < minor)
            {
                *first = p + 1;
                *second = tam;
                minor = aux;
            }
            if (auxPD < minor)
            {
                *first = p;
                *second = p + 1;
                minor = auxPD;
            }
            return minor;
        }
    }
    else
    {
        int p1, p2, p3, p4;
        int q = (p + tam) / 2;
        double dE, dD;
        dE = distaciaRecSH(mat, p, q, &p1, &p2);
        dD = distaciaRecSH(mat, q + 1, tam, &p3, &p4);
        return combine(mat, dE, dD, p1, p2, p3, p4, first, second);
    }
}

double distancia(double **mat, int x1, int x2)
{
    return sqrt(pow(mat[x2][0] - mat[x1][0], 2) + pow(mat[x2][1] - mat[x1][1], 2));
}
// posivel solução

/*
1º Ordenar os pontos de acordo com as coordenadas x;
2ºDividir o grupo de pontos em dois subgrupos de mesmo tamanho por uma linha vertical {\displaystyle x=x_{mid}}{\displaystyle x=x_{mid}}
3ºResolver o problema recursivamente para os dois grupos, resultando nas distâncias mínimas nos lados esquerdos e direitos,  d_{Emin} e  d_{Dmin} respectivamente.
4ºEncontrar a distância mínima {\displaystyle d_{EDmin}}{\displaystyle d_{EDmin}} entre um par de pontos onde cada ponto está em um lado diferente da linha vertical.
5º A resposta final é o mínimo entre d_{Emin} d_{Dmin}, and  d_{EDmin}d_{EDmin}.*/