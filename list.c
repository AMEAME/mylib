#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct List List_new()
{
	struct List list;
	list.data = (int *)malloc(40);//mallc( size ); size�̒P�ʂ̓o�C�g
	list.size = 0;
	return list;
}

int list_add(struct List list, int value)
{
	list.size++;
	if (list.size >= 10)
	{
		list.data = realloc(list.data, list.size * 4);//�����炭 int�^ �� 4byte
	}
	list.data[list.size - 1] = value;
	return 0;
}

void list_delete(struct List list,int value)
{
	printf("del");
}

void list_deleteAt(struct List list,int index)
{
	printf("del");
}

void list_dispose(struct List list)
{
	printf("dis");
}

char* list_to_s(struct List list)
{
	char *str;
	itoa(list.size, str, 10);
	return str;
}



