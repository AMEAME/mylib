#include <stdio.h>
#include "utils.h"

void* p(void* argv)
{
  printf("%s\n", argv);
  return argv;
}

void* pi(int argv)
{
  printf("%d\n", argv);
}

void* pc(char argv)
{
  printf("%c\n", argv);
}
