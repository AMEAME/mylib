
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "error.h"
#include "utils.h"

List List_new()
{
	List list;
	list.data = (int *)malloc(40);
	list.size = 0;
	return list;
}

List* list_add(List *p_list, int value)
{
	p_list->size++;
	if (p_list->size > 10)
	{
		p_list->data = (int *)realloc(p_list->data, (p_list->size + 1) * 4);
	}
	p_list->data[p_list->size - 1] = value;
	return p_list;
}

int list_delete(List *p_list, int value)
{
	int i;
	for (i = 0; i < p_list->size; i++)
	{
		if (value == p_list->data[i])
		{
			list_deleteAt(p_list, i);
			return i;
		}
	}
	return -1;
}

int list_deleteAt(List* p_list, int index)
{
	if (index_error(index, p_list->size)) return 0;
	int i;
	for (i = index; i < p_list->size - 1; i++)
	{
		p_list->data[i] = p_list->data[i + 1];
	}
	p_list->size--;
	p_list->data = (int *)realloc(p_list->data, (p_list->size - 1) * 4);
	return 1;
}

void list_show(List *p_list)
{
	printf("[ ");
	each_with_index(p_list, {
		if (i == p_list->size - 1)
		{
			printf("%d ", e);
		}
		else
		{
		printf("%d, ", e);
		}
  });
	printf("]\n");
}

void list_dispose(List* p_list)
{
	free(p_list->data);
}
