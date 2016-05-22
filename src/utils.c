#include <stdio.h>
#include "utils.h"

void* p(void* argv)
{
  printf("%s\n", argv);
  return argv;
}

void* p_i(int argv)
{
  printf("%d", argv);
}
