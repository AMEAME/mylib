
struct List
{
	int *data;
	int size;
};

struct List* List_new();
struct List* List_new_with_size(int size);
struct List* list_add(struct List *list, int value);
struct List* list_delete(struct List *list, int value);
struct List* list_deleteAt(struct List *list, int index);
struct List* list_dispose(struct List *list);
char* list_to_s(struct List *list);
