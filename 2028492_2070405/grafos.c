#include "libsTrabalho.h"

/*Função para criar um grafo com lista de adjacências.*/
GrafoA *criar_grafo_adj(int tamanho)
{
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++)
   {
      G->Adj[v] = NULL;
   }
   return G;
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj(GrafoA *G)
{
   int v;
   for (v = 0; v < G->V; v++)
   {
      if (G->Adj[v] != NULL)
      {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*-------------------------------*/
void imprimir_grafo_adj(GrafoA *G)
{
   int u;
   printf("Grafo (lista adjacência):\n");
   for (u = 0; u < G->V; u++)
   {
      printf("%2d -> ", u);
      NoA *v;
      for (v = G->Adj[u]; v != NULL; v = v->next)
      {
         printf("%2d (peso: %lf) ", v->id,v->peso);
      }
      printf("\n");
   }
   printf("\n");
}


void PrimMST(GrafoA *graph)
{
   int size = graph->V;
    int V = graph->V; // Get the number of vertices in graph
    int parent[V];    // Array to store constructed MST
    int key[V];       // Key values used to pick minimum weight edge in cut
    MinHeap *minHeap = createMinHeap(V);
    // minHeap represents set E
   

    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] =  9999999;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0] = 0;

    // Initially size of min heap is equal to V
    minHeap->size = V;
    // In the following loop, min heap contains all nodes
    // not yet added to MST.
    while (size == 0)
    {
        // Extract the vertex with minimum key value
        struct MinHeapNode *minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
        NoA *pCrawl = graph->Adj[u];
        while (pCrawl != NULL)
        {
            int v = pCrawl->id;

            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if (isInMinHeap(minHeap, v) && pCrawl->peso < key[v])
            {
                key[v] = pCrawl->peso;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    // print edges of MST
    printArr(parent, V);
}


void Prim(GrafoA *G)
{
   int pa[G->V];
   for (int w = 0; w < G->V; ++w)
      pa[w] = -1;
   pa[0] = 0;
   while (1)
   {
      int min = MAXVALUE;
      int x, y;
      for (int k = 0; k < G->V; ++k)
      {
         if (pa[k] == -1)
            continue;
         for (NoA *a = G->Adj[k]; a != NULL; a = a->next)
            if (pa[a->id] == -1 && a->peso < min)
            {
               min = a->peso;
               x = k, y = a->id;
            }
      }
      if (min == MAXVALUE)
         break;
      // A
      pa[y] = x;
   }
   printArr(pa, G->V);
}

void printArr(int *arr, int n)
{
   for (int i = 1; i < n; ++i)
      printf("%d - %d\n", arr[i], i);
}
/*-------------------------------*/

void adicionar_aresta_grafo_adj(int u, int v, GrafoA *G, int **mat)
{
   G->E++;
   double pesoAresta = distancia(mat, u, v);
   NoA *aux, *ultimo = NULL;
   for (aux = G->Adj[u]; aux != NULL; aux = aux->next)
   {
      if (aux->id == v)
      {
         printf("a aresta (%d,%d) já existe!!!", u, v);
         return;
      }
      ultimo = aux;
   }
   NoA *novo = (NoA *)malloc(sizeof(NoA));
   novo->id = v;
   novo->peso = pesoAresta;
   novo->next = NULL;
   if (ultimo != NULL)
   {
      printf("U:%d V:%d\n U->V: %lf",u,v, distancia(mat,u,v) );
      ultimo->next = novo;
   }
   else
   {
      G->Adj[u] = novo;
   }
}

void DFS_Visit(GrafoA *G, int s, DFS *V, int *tempo)
{
   V[s].cor = CINZA;
   *tempo = (*tempo) + 1;
   V[s].d = *tempo;
   NoA *z;
   for (z = G->Adj[s]; z != NULL; z = z->next)
   {
      if (V[z->id].cor == BRANCO)
      {
         V[z->id].pai = s;
         DFS_Visit(G, z->id, V, tempo);
         printf("Aresta de árvore: (%d - %d)\n", s, z->id);
      }
      else
      {
         printf("Aresta outra:     (%d - %d)\n", s, z->id);
      }
   }
   V[s].cor = PRETO;
   *tempo = (*tempo) + 1;
   V[s].f = *tempo;
}

void Caminho_DFS(int u, DFS *V)
{
   printf("Caminho: ");
   while (u != NIL)
   {
      printf("%d ", u);
      u = V[u].pai;
   }
   printf("\n");
}

void Busca_Profundidade(GrafoA *G)
{
   int u;

   DFS *V = (DFS *)malloc(G->V * sizeof(DFS));

   for (u = 0; u < G->V; u++)
   {
      V[u].cor = BRANCO;
      V[u].pai = NIL;
   }
   int tempo = 0;
   for (u = 0; u < G->V; u++)
   {
      if (V[u].cor == BRANCO)
      {
         DFS_Visit(G, u, V, &tempo);
      }
   }
   Caminho_DFS(0, V);
}

GrafoA *preencher_grafo(int **mat, int tamanho)
{

   GrafoA *G = criar_grafo_adj(tamanho);
   for (int i = 0; i < tamanho; i++)
   {
      for (int j = 0; j < tamanho; j++)
      {
         if (i != j)
         {
            adicionar_aresta_grafo_adj(i, j, G, mat);
         }
      }
   }
   imprimir_grafo_adj(G);
   return G;
}
