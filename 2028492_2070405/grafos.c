#include "libsTrabalho.h"
#include "libHeap.h"

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

//Realizar o parse de arvore geradora minima para um grafo
int **parseAGM(int *v, int size, int **primaryMat){
   int **matrizSaidaAGM = alocaMatriz((size - 1)*2, 2);
   int k,i = 0;
   k++; // k inicia em 1
   while(k< size && i < (size-1)*2){
      matrizSaidaAGM[i][0]= primaryMat[v[k]][0];
      matrizSaidaAGM[i][1]= primaryMat[v[k]][1];
      matrizSaidaAGM[i+1][0] = primaryMat[k][0];
      matrizSaidaAGM[i+1][1] = primaryMat[k][1];
      k++;
      i= i + 2;
   }
   return matrizSaidaAGM;
}

void PrimMST(GrafoA *graph, int *listAGM)
{


   int size = graph->V;
   MinHeap *minHeap = build_min_heap(size);// criando a estrutura da fila de prioridade HEAP Min
   double keyValues[size];
    //inicializando o Heapminimo pelo vertice de posição 0
   keyValues[0] = 0;
   minHeap->array[0] = createNodeHeap(0, keyValues[0]);
   minHeap->pos[0] = 0;
   
   for (int i = 1; i < size; i++)
   {
      listAGM[i] = -1;//todos os vertices da arvore iniciam apontando para -1 (vertice inexistente)
      keyValues[i] =  MAXVALUEFLOAT; //Grupo de chaves de pesos inicia com peso maximo nas arestas
      minHeap->array[i] = createNodeHeap(i, keyValues[i]);
      minHeap->pos[i] = i;
   }

   minHeap->size = size; // Atualiza tamanho do Heap

   while (!isEmpty(minHeap)){
       
      MinHeapNode *minHeapNode = extractMin(minHeap);
      int u = minHeapNode->v; 
      NoA *NodeHead = graph->Adj[u];
      NodeHead = NodeHead->next;
      for (NoA *v = graph->Adj[u]; v != NULL; v = v->next)
      {
         if (isInMinHeap(minHeap, v->id) && NodeHead->peso < keyValues[v->id])
         {
               keyValues[v->id] = NodeHead->peso;
               listAGM[v->id] = u;
               decreaseKey(minHeap, v->id, keyValues[v->id]);
         }
         
      }
   } 
  
}
 
/*Adiciona uma Aresta ligando os vertices u e v pela lista de adjacencia de u, adiciona o peso da aresta ,e adiciona esse novo nó a lista */

void adicionar_aresta_grafo_adj(int u, int v, GrafoA *G, int **mat)
{
   G->E++;// incrementa o numero de arestas
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
   //Cria um novo nó adjacente
   NoA *novo = (NoA *)malloc(sizeof(NoA));
   novo->id = v;
   novo->peso = pesoAresta;
   novo->next = NULL;
   if (ultimo != NULL)
   {
      ultimo->next = novo;
   }
   else
   {
      G->Adj[u] = novo;
   }
}

void DFS_Visit(GrafoA *G, int s, DFS *V, int *caminho, int *iterator)
{
   //Marca o vertice como visitado
   V[s].cor = CINZA;
   NoA *z;
   caminho[*iterator] = s;
   *iterator = (*iterator) + 1 ;
   //percorre visitando seus adjacentes até que todos filhos abaixo dos adjacentes estejam visitados
   for (z = G->Adj[s]; z != NULL; z = z->next)
   {
      if (V[z->id].cor == BRANCO)
      {
         V[z->id].pai = s;
         DFS_Visit(G, z->id, V, caminho, iterator);
      }
   }
   //todos os adjacentes abaixo ja foram visitados então é marcado como preto para não ser visitado novamente
   V[s].cor = PRETO;
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

int *Busca_Profundidade(GrafoA *G)
{
   int u;

   DFS *V = (DFS *)malloc(G->V * sizeof(DFS));
   //inicializa todos os vertices como não visitados
   for (u = 0; u < G->V; u++)
   {
      V[u].cor = BRANCO;
      V[u].pai = NIL;
   }
   int tempo,i = 0;
   int *caminho = (int *) malloc (G->V * sizeof(int));
   for (u = 0; u < G->V; u++)
   {
      //percorre os vertices os visitando caso não tenham sido visitados
      if (V[u].cor == BRANCO)
      {
         DFS_Visit(G, u, V, caminho , &i);
      }
   }
   free(V);
   return caminho;
}

//Cria e preenche as arestas do grafo, e busca o peso das arestas de acordo com as distancia entre os vertices
GrafoA *preencher_grafo(int **mat, int tamanho){
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
   return G;
}

//Executa o processo de AGM, BP , Ciclo - e grava os arquivos de saida
double executeProcess(GrafoA *G,int **mat){
    
  int size = G->V;
  int *a = (int *) malloc (size * sizeof(int)); // Vetor que amazena os vertices finais da AGM

  PrimMST(G,a);

  int **mAux = parseAGM(a, size, mat);
  if(!gravarArquivo("tree.txt",(size- 1)*2,2,mAux)){
   //   printf("Arquivo Gravado com sucesso");
  }
  // grafo Auxiliar para arvore geradora minima e ciclo
   GrafoA *Ga = criar_grafo_adj(size); 
   for (int i = 1; i < size; ++i){
      adicionar_aresta_grafo_adj(a[i], i, Ga, mat); //adiciona arestas da arvore 
      adicionar_aresta_grafo_adj(i, a[i], Ga, mat);  
   } 
  double resultValue = ciclo(G,Ga,mat,mAux);
  free(a);
  desalocaMatriz(mAux,(size - 1)* 2 , 2);
  liberar_grafo_adj(Ga);
  return resultValue;
}

double ciclo(GrafoA *G,GrafoA *Ga,int **mat, int **mAux){
   int size = Ga->V;
   int *caminho =  Busca_Profundidade(Ga); // realiza busca em profundidade na arvore e retorna o caminho feito
  
  float PesoCiclo = 0;
  //preenche a matriz auxiliar com os pontos x,y do ciclo montado ao realizar a BP e busca o somas o peso das arestas do ciclo
  for(int i = 0; i < size - 1; i++){
     mAux[i][0] = mat[caminho[i]][0];
     mAux[i][1] = mat[caminho[i]][1];
     PesoCiclo = PesoCiclo + distancia(mat,caminho[i], caminho[i+1]);
  }
  
  PesoCiclo = PesoCiclo + distancia(mat,caminho[size - 1], caminho[0]);
  mAux[size][0] = mat[0][0];
  mAux[size][1] = mat[0][1]; 
  if(!gravarArquivo("cycle.txt",size + 1 , 2, mAux)){
   //   printf("Arquivo Gravado com sucesso");
  }
  free(caminho);
  
  return PesoCiclo;
}