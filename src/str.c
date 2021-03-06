#include "str.h"

char char_at(string str, int index)
{
  if (index_error(index, slength(str)))
  {
    return 0;
  }
  return *(str + index);
}

string str_concat(string str1, string str2, string str3)
{
  str1 = (char*)malloc((strlen(str2) + strlen(str3) + 1) * sizeof(char));
  strcpy(str1, str2);
  strcat(str1, str3);
  return str1;
}

int sindex(string str1, string str2)
{
  string str = strstr(str1, str2);
  if (str == NULL) {
    return -1;
  }
  return (int)(str - str1);
}

int sincludeQ(string str1, string str2)
{
  return sindex(str1, str2) != -1 ? 1 : 0;
}

int semptyQ(string str)
{
  return slength(str) ? 0 : 1;
}

int sequalQ(string str1, string str2)
{
  if (slength(str1) != slength(str2)) return 0;
  int i, count = 0;
  for (i = 0; i < slength(str1); i++)
  {
    if (char_at(str1, i) != char_at(str2, i))
    {
      count++;
    }
  }
  return count ? 0 : 1;
}

int slength(string str)
{
  return strlen(str);
}

string str_replace(string str1, string str2)
{
  
}

string str_slice(string str)
{
  
}

string str_delete(string str1, string str2)
{
  
}

string str_delete_at(string str, int index)
{
  
}

string str_reverse(string str)
{
  
}

string *str_split(string str1, string str2)
{
  
}
