
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "utils.h"

int main()
{
	List list = List_new();
	List *p_list = &list;

	times(10, { list_add(p_list, i); });
	list_show(p_list);
	
	p("Hello");
	
	list_dispose(p_list);
	return 0;
}
