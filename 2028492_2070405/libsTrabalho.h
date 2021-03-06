/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/

#ifndef _LIBSTRABALHO_H_
#define _LIBSTRABALHO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// CONSTANTES USADAS
#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NIL -1
#define MAXVALUE 2147483647 // valor maximo possivel para um inteiro
#define MAXVALUEFLOAT 9999999999999.000000

/*Estruturas de lista em BP */
typedef struct _DFS
{
  int cor;
  int pai;
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


//Operações de Matrizes
double distancia(int **mat, int x1, int x2);
void imprimir(int **A, int tamanho);
int **alocaMatriz(int lin, int col);
char *alocaString(int size);
int **copiaMatriz(int **mat, int lin, int col);
void desalocaMatriz(int **mat, int lin, int col);
int **leArquivo(char *nomeArqEntrada, int *lin, int *col);
int gravarArquivo(char *nomeArqSaida, int lin, int col, int **mat);

//Funções grafos
int **parseAGM(int *v, int size,int **primaryMat);
int *Busca_Profundidade(GrafoA *G);
void Caminho_DFS(int u, DFS *V);
void DFS_Visit(GrafoA *G, int s, DFS *V, int *caminho, int *iterator);
void adicionar_aresta_grafo_adj(int u, int v, GrafoA *G, int **mat);
GrafoA *criar_grafo_adj(int tamanho);
void liberar_grafo_adj(GrafoA *G);
void imprimir_grafo_adj(GrafoA *G);
void PrimMST(GrafoA *G,int *listAGM);
GrafoA *preencher_grafo(int **mat, int tamanho);
double executeProcess(GrafoA *G, int **mat);
double ciclo(GrafoA *G,GrafoA *Ga,int **mat, int **mAux);
#endif
