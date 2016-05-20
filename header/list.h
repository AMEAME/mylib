#pragma once

typedef struct
{
	int *data;
	int size;
} List;

List* List_new();
List* List_new_with_size(int size);
List* list_add(List *p_list, int value);
List* list_delete(List *p_list, int value);
List* list_deleteAt(List *p_list, int index);
List* list_dispose(List *p_list);
char* list_to_s(List *p_list);
