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


#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NIL -1
#define MAXVALUE 2147483647 // valor maximo possivel para um inteiro

/*Estruturas de lista em BP */
typedef struct _DFS
{
  int cor;
  int pai;
  int d;
  int f;
} DFS;

typedef struct MinHeapNode
{
    int v;
    int key;
}MinHeapNode;

// Structure to represent a min heap
typedef struct MinHeap
{
    int size;     // Number of heap nodes present currently
    int capacity; // Capacity of min heap
    int *pos;     // This is needed for decreaseKey()
    struct MinHeapNode **array;
}MinHeap;


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
int **alocaMatriz(int lin, int col);
char *alocaString(int size);
int **copiaMatriz(int **mat, int lin, int col);
void desalocaMatriz(int **mat, int lin, int col);
int **leArquivo(char *nomeArqEntrada, int *lin, int *col);

GrafoA *preencher_grafo(int **mat, int tamanho);
void Busca_Profundidade(GrafoA *G);
void Caminho_DFS(int u, DFS *V);
void DFS_Visit(GrafoA *G, int s, DFS *V, int *tempo);
void adicionar_aresta_grafo_adj(int u, int v, GrafoA *G, int **mat);
GrafoA *criar_grafo_adj(int tamanho);
void liberar_grafo_adj(GrafoA *G);
void imprimir_grafo_adj(GrafoA *G);
int *Prim(GrafoA *G);
void PrimMST(GrafoA *G);
void printArr(int *arr, int n);

MinHeapNode *createNodeHeap(int value, int key);
MinHeap *build_min_heap(int capacity);
void swapMinHeapNode(MinHeapNode **a,MinHeapNode **b);
void minHeapify(MinHeap *minHeap, int index);
int isEmpty(MinHeap *minHeap);
MinHeapNode *extractMin(MinHeap *minHeap);
void decreaseKey(MinHeap *minHeap, int value, int key);
int isInMinHeap(MinHeap *minHeap, int value);
int pai (int i);
int esquerda (int i);
int direita (int i);

#endif
