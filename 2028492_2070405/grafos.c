#include "libsTrabalho.h"

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NIL -1

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
         printf("%2d ", v->id);
      }
      printf("\n");
   }
   printf("\n");
}

void Prim(GrafoA *G)
{
   int pa[G->V];
   for (int w = 0; w < G->V; ++w)
      pa[w] = -1;
   pa[0] = 0;
   while (1)
   {
      int min = INFINITY;
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
      if (min == INFINITY)
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
   novo->next = NULL;
   if (ultimo != NULL)
   {
      ultimo->peso = distancia(**mat, u, v);
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
