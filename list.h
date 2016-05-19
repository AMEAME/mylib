
struct List
{
	int *data;
	int size;
};

struct List List_new();
int list_add(struct List list, int value);
void list_delete(struct List list, int value);
void list_deleteAt(struct List list, int index);
void list_dispose(struct List list);
char* list_to_s(struct List list);
