#include <stdio.h>
#include <stdlib.h>
#include "TDLinkedList.h"

typedef struct dlnode dlnode;
struct dlnode{
    dlnode *next;
    dlnode *prev;
    aluno data;
};

struct DLinkedList{
    dlnode *begin;
    dlnode *end;
    int size;
};

List* list_create(){

    List *li;
    li = malloc(sizeof(List));
    if(li == NULL){
        return li;
    }

    li->begin = NULL;
    li->end = NULL;
    li->size = 0;
    return li;
}

int list_push_front(List *li, aluno al){

    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    dlnode *node;
    node = malloc(sizeof(dlnode));
    if(node == NULL){
        return OUT_OF_MEMORY;
    }
    node->data = al;
    li->size++;
    node->prev = NULL;

    if(li->begin == NULL){
        node->next = NULL;
        li->begin = node;
        li->end = node;
        return SUCCESS;
    }

    li->begin->prev = node;
    node->next = li->begin;
    li->begin = node;

    return SUCCESS;
}

int list_push_back(List* li, aluno al){

    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    dlnode *node;
    node = malloc(sizeof(dlnode));
    if(node == NULL){
        return OUT_OF_MEMORY;
    }
    node->data = al;
    li->size++;
    node->next = NULL;

    if(li->begin == NULL){
        li->begin = node;
        li->end = node;
        node->prev = NULL;
        return SUCCESS;
    }

    node->prev = li->end;
    li->end->next = node;
    li->end = node;

    return SUCCESS;
}

int list_insert(List * li, int pos, aluno al){

    if(li == NULL){
        return OUT_OF_MEMORY;
    } else if(pos == 1){
        return list_push_front(li, al);
    } else if(pos > li->size+1 || pos < 1){
        return INVALID_NULL_POINTER;
    } else if(pos == li->size+1){
        return list_push_back(li, al);
    }

    dlnode *node, *aux;
    int cont = 1;

    node = malloc(sizeof(dlnode));

    if(node == NULL){
        return OUT_OF_MEMORY;
    }

    node->data = al;
    li->size++;
    aux = li->begin;

    while(cont != pos){
        aux = aux->next;
        cont++;
    }

    aux->prev->next = node;
    node->prev = aux->prev;
    aux->prev = node;
    node->next = aux;

    return SUCCESS;
}

int list_size(List* li){
    return li->size;
}

int list_pop_front(List *li){

    if(li == NULL){
        return OUT_OF_MEMORY;
    } else if(li->begin == NULL){
        return INVALID_NULL_POINTER;
    }

    dlnode *node;
    node = li->begin;
    li->size--;

    if(node->next == NULL){
        li->begin = NULL;
        li->end = NULL;
        free(node);

        return SUCCESS;
    }

    li->begin = node->next;
    li->begin->prev = NULL;

    free(node);

    return SUCCESS;
}

int list_pop_back(List *li){

    if(li == NULL){
        return OUT_OF_MEMORY;
    } else if(li->begin == NULL){
        return OUT_OF_RANGE;
    }

    dlnode *node;
    node = li->end;
    li->size--;

    if(node->prev == NULL){
        li->begin = NULL;
        li->end = NULL;

        free(node);
        return SUCCESS;
    }


    li->end = node->prev;
    li->end->next = NULL;

    free(node);

    return SUCCESS;
}


int list_erase(List* li, int pos){

    if(li == NULL){
        return OUT_OF_MEMORY;
    } else if(pos > li->size || pos < 1){
        return INVALID_NULL_POINTER;
    } else if(pos == 1){
        return list_pop_front(li);
    } else if(pos == li->size){
        return list_pop_back(li);
    }

    dlnode *node;
    int cont = 1;
    node = li->begin;
    li->size--;

    while(cont != pos){
        node = node->next;
        cont++;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);

    return SUCCESS;
}

int list_find_pos(List* li, int pos, aluno *al){

    if(li == NULL){
        return OUT_OF_MEMORY;
    } else if(pos > li->size || pos < 1){
        return INVALID_NULL_POINTER;
    }

    dlnode *node;
    int cont = 1;
    node = li->begin;

    while(cont != pos){
        node = node->next;
        cont++;
    }

    *al = node->data;

    return SUCCESS;
}

int list_find_mat(List* li, int nmat, aluno *al){

    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    dlnode *node;
    int cont = 1;
    node = li->begin;

    while(cont <= li->size){
        if(node->data.matricula == nmat){
            *al = node->data;
            return SUCCESS;
        }
        node = node->next;
        cont++;
    }

    return ELEM_NOT_FOUND;
}

int list_front(List* li, aluno *al){

    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    if(li->begin == NULL){
        return OUT_OF_RANGE;
    }

    *al = li->begin->data;
    return SUCCESS;
}

int list_back(List* li, aluno *al){

    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    if(li->begin == NULL){
        return OUT_OF_RANGE;
    }

    *al = li->end->data;
    return SUCCESS;
}

int list_get_pos(List* li, int nmat, int *pos){

   if(li == NULL){
        return OUT_OF_MEMORY;
    }

    dlnode *node;
    int cont = 1;
    node = li->begin;

    while(cont <= li->size){
        if(node->data.matricula == nmat){
            *pos = cont;
            return SUCCESS;
        }
        node = node->next;
        cont++;
    }
    return ELEM_NOT_FOUND;
}


int list_print_forward(List* li){

    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    dlnode *node;
    int cont = 0;
    node = li->begin;

    printf("\nLista: \n");
    while(cont != li->size){
        printf("\nMatricula: %d\n", node->data.matricula);
        printf("Nome: %s\n", node->data.nome);
        printf("Nota 1: %.2f, Nota 2: %.2f, Nota 3: %.2f\n", node->data.n1, node->data.n2, node->data.n3);
        node = node->next;
        cont++;
    };

    return SUCCESS;
}

int list_print_reverse(List* li){

    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    dlnode *node;
    int cont = 0;
    node = li->end;

    printf("\nLista: \n");
    while(cont != li->size){
        printf("\nMatricula: %d\n", node->data.matricula);
        printf("Nome: %s\n", node->data.nome);
        printf("Nota 1: %.2f, Nota 2: %.2f, Nota 3: %.2f\n", node->data.n1, node->data.n2, node->data.n3);
        node = node->prev;
        cont++;
    };

    return SUCCESS;

}

int list_free(List *li){

    if(li == NULL){
        return OUT_OF_MEMORY;
    }

    int cont = 0;
    dlnode *node, *aux;
    node = li->begin;

    while(cont != li->size){
        aux = node->next;
        free(node);
        node = aux;
        cont++;
    }

    free(li);

    return SUCCESS;
}


