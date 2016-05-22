#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

string str_concat(string str1, string str2, string str3)
{
  str1 = (char*)malloc((strlen(str2) + strlen(str3) + 1) * sizeof(char));
  strcpy(str1, str2);
  strcat(str1, str3);
  return str1;
}
