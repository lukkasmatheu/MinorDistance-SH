#include "libsTrabalho.h"

double **leArquivo(char *nomeArqEntrada, int *lin, int *col)
{
    double **mat = NULL;
    int i, j;
    FILE *arq = fopen(nomeArqEntrada, "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo %s", nomeArqEntrada);
        return mat;
    }
    fscanf(arq, "%d", lin);
    *col = 2;
    mat = alocaMatriz(*lin, *col);

    for (i = 0; i < *lin; i++)
    {
        for (j = 0; j < *col; j++)
        {
            fscanf(arq, "%lf", &mat[i][j]);
        }
    }
    fclose(arq);
    return mat;
}
