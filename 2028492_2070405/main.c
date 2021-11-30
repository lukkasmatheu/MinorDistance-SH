/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/

#include "libsTrabalho.h"

int main(int argc, char *argv[])
{

   printf("iniciando");
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int lin, col;
   char *nomeArqFisico;
   int **mat;
   GrafoA *grafo;

   

   if (argc != 2)
   {
      printf("Parametro invalido");
      return 1;
   }

   //Aloca espaço para a string que armazenará o nome do arquivo a ser lido
   //que foi recebido como argumento na função main
   nomeArqFisico = alocaString(20);
   strcpy(nomeArqFisico, argv[1]);

   //==Completar: chamada pra alocaString para alocação da string tipo, a qual é passada como parâmetro para a função leArquivo, onde, então, é feita a leitura do arquivo
   mat = leArquivo(nomeArqFisico, &lin, &col);
   if (mat == NULL)
   {
      printf("\nErro ao abrir Arquivo\n");
      return 1;
   }

   imprimir(mat,lin);
   grafo = preencher_grafo(mat, lin);

   start = clock();

   end = clock();
   elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
   //   printf("Tempo decorrido: %lf Distancia Minima: %lf Pontos no plano x1: %lf y1: %lf x2:%lf y2:%lf \n", elapsed_time, minorDistance, mat[first][0], mat[first][1], mat[second][0], mat[second][1]);
   liberar_grafo_adj(grafo);
   free(nomeArqFisico);
   desalocaMatriz(mat, lin, col);

   return 0;
}
