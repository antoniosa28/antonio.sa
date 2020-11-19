#include "aluno.h"

#define SUCCESS 0
#define OUT_OF_MEMORY -1
#define ELEM_NOT_FOUND -2
#define NULL_POINTER -3

typedef struct list List;

List* list_create();
int list_free(List *li);
int list_push_front(List *li, aluno al);
int list_push_back(List *li, aluno al);
int list_insert(List *li, int pos, aluno al);
int list_insert_sorted(List *li, aluno al);
int list_size(List *li);
int list_pop_front(List *li);
int list_pop_back(List *li);
int list_erase(List *li, int pos);
int list_find_pos(List *li, int pos, aluno *al);
int list_find_mat(List *li, int mat, aluno *al);
int list_front(List *li, aluno *al);
int list_back(List *li, aluno *al);
int list_get_pos(List *li, int nmat, int *pos);
int list_print(List* li);
