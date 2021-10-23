void Imprimir(double *A, int tamanho)
{
    int i;
    printf("Vetor:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%lf ", A[i]);
    }
    printf("\n");
}