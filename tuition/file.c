#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void _file_error(char *file_name)
{
    FILE *fp;
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("Cannot open input file '%s'", file_name);
        exit(EXIT_FAILURE);
    }
}

int _file_get_size(char *file_name)
{
    _file_error(file_name);
    FILE *fp = fopen(file_name, "r");
    int counter = 0;
    while (getc(fp) != EOF) counter++;
    fclose(fp);
    return counter;
}

char *read(char *file_name)
{
    char ch;
    char *text = malloc(sizeof(char)
        * (_file_get_size(file_name) + 1));
    FILE *fp = fopen(file_name, "r");
    char *nil = "";
    strcpy(text, nil);
    while ((ch = getc(fp)) != EOF)
    {
        char s[] = {ch, '\0'};
        strcat(text, s);
    }
    fclose(fp);
    return text;
}

int main(int argc, char **argv)
{
    if (argc != 2) return 1;
    char *file_name = argv[1];
    char *text = read(file_name);
    puts(text);
    return 0;
}
