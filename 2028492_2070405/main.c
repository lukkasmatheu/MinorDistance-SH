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

   grafo = preencher_grafo(mat, lin);

   
   start = clock();
   double result =  executeProcess(grafo,mat);
   end = clock();
   elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
   printf("%lf %lf\n",elapsed_time,result);
   liberar_grafo_adj(grafo);
   free(nomeArqFisico);
   desalocaMatriz(mat, lin, col);

   return 0;
}
