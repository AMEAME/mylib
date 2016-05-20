
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List* List_new()
{
	List list;
	list.data = (int *)malloc(10);
	list.size = 0;
	List *p_list = &list;
	return p_list;
}

List* List_new_with_size(int size)
{
	List list;
	list.data = (int *)malloc(size);
	list.size = 0;
	List *p_list = &list;
	return p_list;
}

List* list_add(List *p_list, int value)
{
	printf("1 %d %d\n", value, p_list->size);
	p_list->size++;
	printf("2 %d %d\n", value, p_list->size);
	if (p_list->size >= 10)
	{
		p_list->data = (int *)realloc(p_list->data, p_list->size + 1);
		printf("3 %d %d\n", value, p_list->size);
	}
	printf("4 %d %d\n", value, p_list->size);
	p_list->data[p_list->size - 1] = value;
	printf("5 %d\n", value);
	return p_list;
}

List* list_delete(List *p_list, int value)
{
	printf("del");
	return p_list;
}

List* list_deleteAt(List* p_list, int index)
{
	printf("del");
	return p_list;
}

List* list_dispose(List* p_list)
{
	printf("dis");
	return p_list;
}

char* list_to_s(List* p_list)
{
	char *str = "[]";
	
	return str;
}
