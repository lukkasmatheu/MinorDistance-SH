/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/

#ifndef _LIBSTHEAP_H_
#define _LIBSHEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAXVALUE 2147483647 // valor maximo possivel para um inteiro

typedef struct minHeapNode{
  int v;
  int key;
}MinHeapNode;

// Structure to represent a min heap
typedef struct heapMinimo{
  int size;
  int capacity;
  int *pos;     
  MinHeapNode **array;
}MinHeap;


//HEAP Functions 
int pai (int i);
int esquerda (int i);
int direita (int i);
MinHeap *build_min_heap(int tamanho);
MinHeapNode *createNodeHeap(int value, int key);
void swapMinHeapNode(MinHeapNode **a,MinHeapNode **b);
void minHeapify(MinHeap *minHeap, int index);
int isEmpty(MinHeap *minHeap);
MinHeapNode *extractMin(MinHeap *minHeap);
void decreaseKey(MinHeap *minHeap, int value, int key);
int isInMinHeap(MinHeap *minHeap, int value);

void printTo();



#endif
