#include "libsTrabalho.h"
char *alocaString(int size)
{
   char *st = (char *)malloc(size * sizeof(char));

   return st;
}
