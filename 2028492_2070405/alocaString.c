/*
Projeto Analise Algoritmo
Universidade Tecnologica Federal do parana 
Lucas Matheus dos Santos
Julio Cesar Rogacheski
  2021
*/

#include "libsTrabalho.h"
char *alocaString(int size)
{
   char *st = (char *)malloc(size * sizeof(char));

   return st;
}
