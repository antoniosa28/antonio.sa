typedef struct node node;
typedef struct List_circ List;

List *List_create();
int List_push_front(List *li, int n);
int List_push_back(List *li, int n);
int List_pop_front(List *li);
int List_pop_back(List *li);
void List_print(List *li);
int List_next_elem(List *li, int *num);
