#include "libsTrabalho.h"

void desalocaMatrizImagem(float **mat, int lin, int col)
{
    int i;
    for (i = 0; i < lin; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
