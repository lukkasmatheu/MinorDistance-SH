#include "libsTrabalho.h"
#include "libHeap.h"

int pai (int i) {
   return (i - 1)/2;
}

int esquerda (int i) {
   return (i * 2) + 1;
}

int direita (int i) {
   return (i * 2) + 2;
}



MinHeap *build_min_heap(int tamanho){
    
    MinHeap *minHeap = (MinHeap *) malloc (sizeof(MinHeap));

    minHeap->pos = (int *) malloc (tamanho * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = tamanho;
    minHeap->array = (MinHeapNode **) malloc (tamanho * sizeof(MinHeapNode *));
   
    return minHeap;
}

MinHeapNode *createNodeHeap(int value, int key)
{
    MinHeapNode *minHeapNode = (MinHeapNode *) malloc (sizeof(MinHeapNode));
    minHeapNode->v = value;
    minHeapNode->key = key;
    return minHeapNode;
}

void swapMinHeapNode(MinHeapNode **a,MinHeapNode **b)
{
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int index)
{
    
   int e = esquerda (index);
   int d = direita (index);
   int menor;

    if (e < minHeap->size && minHeap->array[e]->key < minHeap->array[menor]->key)
        menor = e;

    if (d < minHeap->size && minHeap->array[d]->key < minHeap->array[menor]->key)
        menor = d;

    if (menor != index)
    {

        minHeap->pos[minHeap->array[menor]->v] = index;
        minHeap->pos[minHeap->array[index]->v] = menor;

        swapMinHeapNode(&minHeap->array[menor], &minHeap->array[index]);

        minHeapify(minHeap, menor);
    }
}

//Verifica se Heap esta vazia
int isEmpty(MinHeap *minHeap)
{
    return minHeap->size == 0 ? 1 : 0;
}


MinHeapNode *extractMin(MinHeap *minHeap){
    int size = minHeap->size;
    if (isEmpty(minHeap))
        return NULL;
    
    //Cabeça do heap
    MinHeapNode *head = minHeap->array[0];

    MinHeapNode *lastNode = minHeap->array[size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[head->v] = size - 1;
    minHeap->pos[lastNode->v] = 0;

    minHeap->size = size - 1;
    minHeapify(minHeap, 0);

    return head;
}

void decreaseKey(MinHeap *minHeap, int value, int key)
{
    int i = minHeap->pos[value];

    minHeap->array[i]->key = key;

    while (i > 0 && minHeap->array[i]->key < minHeap->array[pai(i)]->key)
    {

        minHeap->pos[minHeap->array[i]->v] = pai(i);
        minHeap->pos[minHeap->array[pai(i)]->v] = i;
        swapMinHeapNode(&minHeap->array[i],&minHeap->array[pai(i)]);
        i = pai(i);
    }
}

int isInMinHeap(MinHeap *minHeap, int value)
{
    if (minHeap->pos[value] < minHeap->size)
        return 1;
    return 0;
}

// Heap Usando vetor
// void trocar (int V[], int a, int b) {
//    int aux = V[a];
//    V[a] = V[b];
//    V[b] = aux;
// }
// void imprimir (int V[], int size) {
//    int i;
//    for (i = 0; i < size; i++) {
//       printf("%d ", V[i]);
//    }
//    printf("\n");
// }
// void build_min_heap(int v[],int size)
// {
//    for(int i=(size/2)-1;i>=0;i--)
//       min_heapify (v,size,i);
// }

// int heap_minimun(int v[])
// {
//    return v[0];
// }
// int heap_extract_min(int v[], int size){
//     int min;
// 	if(size < 1)
//     {
//         printf("\nErro\n");
//     }
//     min=heap_minimun(v);
//     v[0]= v[size-1];
//     size= size -1;
//     min_heapify(v,size,0);
//     return min;
// }
// void heap_increase_key(int v[],int i, int chave){
//     if(chave < v[i])
//     {
//         printf("\nErro: chave maior que a atual\n");
//         return ;
//     }
//     v[i]=chave;
//     while(i>0 && v[pai(i)]>v[i]){
//         trocar(v,i,pai(i));
//         i=pai(i);
//     }
// }
// void heap_decrease_key (int v[], int i, int chave, int size) {
//     if(chave > v[i])
//     {
//         printf("\nChave menor que a atual\n");
//     }
//     v[i]=chave;
//      while(i>0 && v[pai(i)]>v[i]){
//         trocar(v,i,pai(i));
//         i=pai(i);
//     }
// }
