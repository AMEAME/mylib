#pragma once

#define string char*

#define sconcatl(str1, literal)                 \
({                                              \
  char *__concat__(char *str1, char *str2)      \
  {                                             \
    char *str3 = str_concat(str3, str1, str2);  \
    return str3;                                \
  }                                             \
  char *str2 = #literal;                        \
  __concat__(str1, str2);                       \
})

#define sconcat(str1, str2)                     \
({                                              \
  char *__concat__(char *str1, char *str2)      \
  {                                             \
    char *str3 = str_concat(str3, str1, str2);  \
    return str3;                                \
  }                                             \
  __concat__(str1, str2);                       \
})
char char_at(string str, int index);
string str_concat(string str1, string str2, string str3);
int sindex(string str1, string str2);
int sincludeQ(string str1, string str2);
int semptyQ(string str);
int sequalQ(string str1, string str2);
int slength(string str);
string str_replace(string str1, string str2);
string str_slice(string str);
string str_delete(string str1, string str2);
string str_delete_at(string str, int index);
string str_reverse(string str);
