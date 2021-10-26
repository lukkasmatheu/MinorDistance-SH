#ifndef _LIBSTRABALHO2_H_
#define _LIBSTRABALHO2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void distanciaMinimaSH(double **mat, int tamanho, int *first, int *second, int *minorDistance);
double distancia(double **mat, int x1, int x2);
void imprimir(double **A, int tamanho);
double distaciaRecSH(double **mat, int p, int tam, int *first, int *second);
double **alocaMatriz(int lin, int col);
char *alocaString(int size);
double ditanciaBruteForce(double **mat, int tamanho);
void mergeSort(double **A, int e, int d, double **Aux);
double **copiaMatriz(double **mat, int lin, int col);
void desalocaMatriz(double **mat, int lin, int col);
double **leArquivo(char *nomeArqEntrada, int *lin, int *col);

#endif
