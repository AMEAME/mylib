#pragma once

#define string char*

#define concatl(str1, literal)                  \
({                                              \
  char *__concat__(char *str1, char *str2)      \
  {                                             \
    char *str3 = str_concat(str3, str1, str2);  \
    return str3;                                \
  }                                             \
  char *str2 = #literal;                        \
  __concat__(str1, str2);                       \
})

#define concat(str1, str2)                      \
({                                              \
  char *__concat__(char *str1, char *str2)      \
  {                                             \
    char *str3 = str_concat(str3, str1, str2);  \
    return str3;                                \
  }                                             \
  __concat__(str1, str2);                       \
})

string str_concat(string str1, string str2, string str3);
