#ifndef _LIBSTRABALHO2_H_
#define _LIBSTRABALHO2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void distanciaMinimaSH(double **mat, int tamanho, int *first, int *second, int *minorDistance);
void Imprimir(int *A, int tamanho);
double **alocaMatriz(int lin, int col);
char *alocaString(int size);
void mergeSort(double **A, int e, int d, double **Aux);
double **copiaMatriz(double **mat, int lin, int col);
void desalocaMatriz(double **mat, int lin, int col);
double **leArquivo(char *nomeArqEntrada, int *lin, int *col);

#endif
