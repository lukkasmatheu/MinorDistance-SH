#include "libsTrabalho.h"

int gravarImagem(char *nomeArqSaida, char *tipo, int lin, int col, int maxval, int **mat)
{

    FILE *arq = fopen(nomeArqSaida, "w+");
    if (!arq)
    {
        printf("\nErro ao abrir o arquivo %s\n", nomeArqSaida);
        return 1;
    }
    fprintf(arq, "%s \n%d %d\n%d\n", tipo, lin, col, maxval);
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
