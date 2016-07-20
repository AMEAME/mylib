#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "utils.h"

typedef struct
{
	int *data;
	int size;
} list;

list List_new();
list* list_add(list *p_list, int value);
int list_delete(list *p_list, int value);
int list_deleteAt(list *p_list, int index);
void list_show(list *p_list);
void list_dispose(list *p_list);

#endif
