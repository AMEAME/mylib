#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *concat(char *str1, char *str2)
{
    char *concatenated_str = (char*)malloc((strlen(str1)
        + strlen(str2) + 1) * sizeof(char));
    strcpy(concatenated_str, str1);
    strcat(concatenated_str, str2);
    return concatenated_str;
}

int main()
{
    puts(concat("Hello ", "World!"));
    return 0;
}
