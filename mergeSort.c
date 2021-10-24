#include "libsTrabalho.h"
void intercalar(double **A, int e, int m, int d, double **Aux)
{
    int i, j, posi;
    i = e;
    j = m + 1;
    posi = e;
    while (i <= m && j <= d)
    {
        if (A[i][0] <= A[j][0])
        {
            Aux[posi][0] = A[i][0];
            Aux[posi][1] = A[i][1];
            i++;
        }
        else
        {
            Aux[posi][0] = A[j][0];
            Aux[posi][1] = A[j][1];
            j++;
        }
        posi++;
    }
    for (i; i <= m; ++i)
    {
        Aux[posi][0] = A[i][0];
        Aux[posi][1] = A[i][1];
        posi++;
    }
    for (j; j <= d; ++j)
    {
        Aux[posi][0] = A[j][0];
        Aux[posi][1] = A[j][1];
        posi++;
    }
    for (i = e; i <= d; ++i)
    {
        A[i][0] = Aux[i][0];
        A[i][1] = Aux[i][1];
    }
}

/**/
void mergeSort(double **A, int e, int d, double **Aux)
{
    if (e < d)
    {
        int m;
        m = (d + e) / 2;
        mergeSort(A, e, m, Aux);
        mergeSort(A, m + 1, d, Aux);
        intercalar(A, e, m, d, Aux);
    }
}