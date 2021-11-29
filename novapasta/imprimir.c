#include "libsTrabalho.h"
void imprimir(double **A, int tamanho)
{
    int i;
    printf("Vetor:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("x:%lf y:%lf ", A[i][0],A[i][1]);
    }
    printf("\n");
}