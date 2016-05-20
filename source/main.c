
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "utils.h"

int main()
{
	List *p_list = List_new();
	printf("%d %d %d\n", &p_list->data[0], p_list->size, p_list->size);
	printf("%d %d %d\n", &p_list->data[0], p_list->size, p_list->size);
	
	int i;
	times(10, i, {
		printf("s %d\n", i);
		printf("e %d\n", i);
	});

	// free(p_list->data);
	// for (i = 0; i < 100; i++)
	// {
	// 	printf("%d %d\n", list->data[i], list->size);
	// }
	return 0;
}
