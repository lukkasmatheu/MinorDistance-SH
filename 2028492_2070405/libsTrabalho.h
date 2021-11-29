/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/

#ifndef _LIBSTRABALHO2_H_
#define _LIBSTRABALHO2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Estrutura de lista em BP */
typedef struct _DFS
{
  int cor;
  int pai;
  int d;
  int f;
} DFS;

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA
{
  double peso;      /* Peso referente as arestas (u,v)*/
  int id;           /*Identificador armazenado no nó. */
  struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA
{
  int E;     /* Quantidade de arestas. */
  int V;     /* Quantidade de vértices. */
  NoA **Adj; /* Lista de adjacências. */
} GrafoA;

double distancia(int **mat, int x1, int x2);
void imprimir(int **A, int tamanho);
double **alocaMatriz(int lin, int col);
char *alocaString(int size);
double **copiaMatriz(int **mat, int lin, int col);
void desalocaMatriz(int **mat, int lin, int col);
int **leArquivo(int *nomeArqEntrada, int *lin, int *col);
GrafoA *preencher_grafo(int **mat, int tamanho);
void Busca_Profundidade(GrafoA *G);
void Caminho_DFS(int u, DFS *V);
void DFS_Visit(GrafoA *G, int s, DFS *V, int *tempo);
void adicionar_aresta_grafo_adj(int u, int v, GrafoA *G, int **mat);
GrafoA *criar_grafo_adj(int tamanho);
#endif
