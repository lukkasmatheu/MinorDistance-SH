#include "libsTrabalho.h"

int gravarArquivo(char *nomeArqSaida, int lin, int col, int **mat)
{

    FILE *arq = fopen(nomeArqSaida, "w+");
    if (!arq)
    {
        printf("\nErro ao abrir o arquivo %s\n", nomeArqSaida);
        return 1;
    }

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fprintf(arq, "%d ", mat[i][j]);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
    return 0;
}
