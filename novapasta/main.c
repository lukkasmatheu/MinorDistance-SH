#include "libsTrabalho.h"

int main(int argc, char *argv[])
{
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int opt = 1, lin, col, maxVal;
   char *nomeArqFisico;
   double **mat;

   if (argc != 2)
   {
      printf("Parametro invalido");
      return 1;
   }

   //Aloca espaço para a string que armazenará o nome do arquivo(imagem) a ser lido, o qual foi
   //foi recebido como argumento na função main
   nomeArqFisico = alocaString(20);
   strcpy(nomeArqFisico, argv[1]);

   //==Completar: chamada pra alocaString para alocação da string tipo, a qual é passada como parâmetro para a função leArquivo, onde, então, é feita a leitura do arquivo
   mat = leArquivo(nomeArqFisico, &lin, &col);
   imprimir(mat, lin);
   if (mat == NULL)
   {
      printf("\nErro ao abrir Arquivo\n");
      return 1;
   }

   start = clock();

   int first, second;
   double minorDistance;
   distanciaMinimaSH(mat, lin , &first, &second, &minorDistance);
   // minorDistance = ditanciaBruteForce(mat,lin);
   end = clock();
   elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;

   printf("menorDistance: %lf tempo de execusão: %lf",minorDistance,elapsed_time);

   printf("Tempo decorrido: %lf Distancia Minima: %lf Pontos no plano x1: %lf y1: %lf x2:%lf y2:%lf",elapsed_time , minorDistance ,mat[first][0],mat[first][1],mat[second][0],mat[second][1]);
   free(nomeArqFisico);
   desalocaMatriz(mat, lin, col);

   return 0;
}
