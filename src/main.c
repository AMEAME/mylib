
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "utils.h"
#include "str.h"

int main()
{
	int i = 0;
	char ch = 0;
	float f = 0;
	long int l = 0;
	char *s = "adfgaaaa";
	
	printf("%d\n", sizeof(i));
	printf("%d\n", sizeof(ch));
	printf("%d\n", sizeof(f));
	printf("%d\n", sizeof(l));
	printf("%\dn", sizeof(s));
	
	
		
	return 0;
}
