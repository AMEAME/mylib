#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	struct List *list = List_new();
	// printf("%d %d\n", list->data[0], list->size);
	list_add(list, 1);
	
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("s %d\n", i);
		list_add(list, i);
	  printf("e %d\n", i);
	}
	
	free(list->data);
	// for (i = 0; i < 100; i++)
	// {
	// 	printf("%d %d\n", list->data[i], list->size);
	// }
	return 0;
}
