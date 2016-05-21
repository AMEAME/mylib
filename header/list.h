#pragma once

typedef struct
{
	int *data;
	int size;
} List;

List List_new();
List* list_add(List *p_list, int value);
int list_delete(List *p_list, int value);
int list_deleteAt(List *p_list, int index);
void list_show(List *p_list);
void list_dispose(List *p_list);
