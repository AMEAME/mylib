#include <stdio.h>
#include "error.h"

int index_error(int arg1, int arg2)
{
  if (arg1 < 0 || arg2 <= arg1)
	{
		puts("IndexError: list index out of range\n");
    return 1;
	}
  return 0;
}
