#include <stdio.h>
#include "utils.h"

void* p(void* argv)
{
  printf("%s", argv);
  return argv;
}
