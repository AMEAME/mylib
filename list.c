#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct List* List_new()
{
	struct List *list;
	list->data = (int *)malloc(10);
	list->size = 0;
	return list;
}

struct List* List_new_with_size(int size)
{
	struct List *list;
	list->data = (int *)malloc(size);
	list->size = 0;
	return list;
}

struct List* list_add(struct List *list, int value)
{
	printf("1 %d\n", value);
	list->size++;
	printf("2 %d\n", value);
	if (list->size >= 10)
	{
		list->data = (int *)realloc(list->data, list->size + 1);
		printf("3 %d\n", value);
	}
	printf("4 %d\n", value);
	list->data[list->size - 1] = value;
	printf("5 %d\n", value);
	return list;
}

struct List* list_delete(struct List *list, int value)
{
	printf("del");
}

struct List* list_deleteAt(struct List* list, int index)
{
	printf("del");
}

struct List* list_dispose(struct List* list)
{
	printf("dis");
}

char* list_to_s(struct List* list)
{
	char *str;
	itoa(list->size, str, 10);
	return str;
}
