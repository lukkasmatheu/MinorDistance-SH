#include "libsTrabalho.h"


int pai (int i) {
   return (i - 1)/2;
}

int esquerda (int i) {
   return (i * 2) + 1;
}

int direita (int i) {
   return (i * 2) + 2;
}

// A utility function to create a new Min Heap Node
MinHeapNode *newMinHeapNode(int v, int key)
{
    MinHeapNode *minHeapNode = (MinHeapNode *) malloc (sizeof(MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

// A utilit function to create a Min Heap
MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *) malloc (sizeof(MinHeap));
    minHeap->pos = (int *) malloc (capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode **) malloc (capacity * sizeof(MinHeapNode *));
    return minHeap;
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

// A utility function to check if the given minHeap is ampty or not
int isEmpty(MinHeap *minHeap)
{
    return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
MinHeapNode *extractMin(MinHeap *minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    // Store the root node
    MinHeapNode *root = minHeap->array[0];

    // Replace root node with last node
    MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decrease key value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(MinHeap *minHeap, int v, int key)
{
    // Get the index of v in  heap array
    int i = minHeap->pos[v];

    // Get the node and update its key value
    minHeap->array[i]->key = key;

    // Travel up while the complete tree is not hepified.
    // This is a O(Logn) loop
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
    {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
int isInMinHeap(MinHeap *minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
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
