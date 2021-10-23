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
   Imprimir(*mat, lin);
   if (mat == NULL)
   {
      printf("\nErro ao abrir Arquivo\n");
      return 1;
   }

   start = clock();

   int first, second;
   distanciaMinimaSH(mat, lin, &first, &second);
   end = clock();
   elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;

   free(nomeArqFisico);
   desalocaMatriz(mat, lin, col);

   return 0;
}
