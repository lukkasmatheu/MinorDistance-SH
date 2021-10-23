#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

/* Funcao para verificar se argumento eh inteiro positivo. */
int ehInteiroPositivo(char number[])
{
    for (int i = 0; number[i] != '\0'; i++)
    {
        if (!isdigit(number[i]))
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[]){

	/* Verifica argumento. */
	if (argc != 2)
	{
		fprintf(stderr, "Uso: %s nro_pontos\n", argv[0]);
		return 1;
	}

	if (!ehInteiroPositivo(argv[1]))
	{
		fprintf(stderr, "nro de pontos (%s) nao eh valido.\n", argv[1]);
		return 1;
	}

	/* Recupera tamanho. */
	int npontos = atoi(argv[1]);
	
	/* Salva arquivo de entrada. */
	FILE *fp = fopen("input.txt", "w");
	if (fp == NULL)
	{
		fprintf(stderr, "Falha ao criar input.txt.\n");
		return 1;
	}

	/* Cria os pontos aleatorios. */
	fprintf(fp, "%d\n", npontos);
	srand(time(NULL));
	int n = 0;
	while (n < npontos)
	{
		double x = 10000*(double)rand()/RAND_MAX;
		double y = 10000*(double)rand()/RAND_MAX;
		n++;
		fprintf(fp, "%lf %lf\n", x, y);
	}

	fclose(fp);

	return 0;
}
