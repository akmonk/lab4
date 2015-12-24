#include "stdio.h"
int main(int argc, char *argv[])

{
  int i;
  char *pid;
  // переданы ли pid
  if (argc < 2)
  {
    printf("Ошибка. Введите pwdx pid1 [pid2]\n");
    return 1;
  }
  else
  {
    for (i=1;i<argc;i++)
    envx(argv[i]);
  }
  return 0;
} 
