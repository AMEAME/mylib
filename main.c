#include <stdio.h>
#include "list.c"

int main()
{
	struct List list = List_new();

	list_add(list, 10);

	printf("%d %d\n", list.data[0], list.size);

	return 0;
}
