#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node List_node;

struct list{
    List_node *head;
};

struct list_node{
    struct aluno data;
    List_node *next;
};

// Criando lista
List* list_create(){

    List *li;
    li = malloc(sizeof(List));

    if(li != NULL){
        li->head = NULL;
    }

    return li;
}


int list_push_front(List *li, aluno al){

    if(li == NULL){
        return NULL_POINTER;
    }
    List_node *node;
    node = malloc(sizeof(List_node));
    node->next = li->head;
    li->head = node;

    node->data = al;

    return SUCCESS;
}


int list_push_back(List *li, aluno al){

    if(li == NULL){
        return NULL_POINTER;
    }else if (li->head == NULL){
        return list_push_front(li, al);
    }

    List_node *aux, *node;
    node = malloc(sizeof(List_node));

    aux = li->head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = node;
    node->data = al;
    node->next = NULL;

    return SUCCESS;

}


int list_insert(List *li, int pos, aluno al){

    if(li == NULL){
        return NULL_POINTER;
    }else if(li->head == NULL && pos > 1){
        return OUT_OF_MEMORY;
    }else if(pos == 1){
        return list_push_front(li, al);
    }
    List_node *node, *aux;
    node = malloc(sizeof(List_node));
    aux = li->head;

    int cont = 2;
    while(cont < pos){
        aux = aux->next;
        cont++;
    }
    if(aux == NULL){
        return OUT_OF_MEMORY;
    }
    node->data = al;
    node->next = aux->next;
    aux->next = node;

    return SUCCESS;
}


int list_insert_sorted(List *li, aluno al){

    if(li == NULL){
        return NULL_POINTER;
    }else if(al.mat < li->head->data.mat){
        return list_push_front(li, al);
    }

    List_node *node, *aux;
    node = malloc(sizeof(List_node));
    node->data = al;
    aux = li->head;

    while(al.mat > aux->data.mat && aux->next != NULL){
        if(al.mat < aux->next->data.mat){
            break;
        }
        aux = aux->next;
    }

    node->next = aux->next;
    aux->next = node;

    return SUCCESS;
}



int list_size(List *li){

    List_node *node;
    node = li->head;

    int cont = 0;
    while(node != NULL){
        node = node->next;
        cont++;
    }

    return cont;
}



int list_pop_front(List *li){

    if(li == NULL){
        return NULL_POINTER;
    }else if(li->head == NULL){
        return ELEM_NOT_FOUND;
    }

    List_node *aux;
    aux = li->head->next;
    li->head = aux;

    return SUCCESS;
}


int list_pop_back(List *li){

    if(li == NULL){
        return NULL_POINTER;
    }else if(li->head == NULL){
        return ELEM_NOT_FOUND;
    }else if(li->head->next == NULL){
        li->head = NULL;
        return SUCCESS;
    }

    List_node *node;
    node = li->head;

    while(node->next->next != NULL){
        node = node->next;
    }

    node->next = NULL;

    return SUCCESS;
}


int list_erase(List *li, int pos){

    int tam = list_size(li);

    if(li == NULL){
        return NULL_POINTER;
    }else if(li->head == NULL || pos > tam){
        return ELEM_NOT_FOUND;
    }else if(pos == 1){
        return list_pop_front(li);
    }else if(pos == tam){
        return list_pop_back(li);
    }

    List_node *node;
    node = li->head;
    int cont = 1;

    while(cont != pos-1){
        node = node->next;
        cont++;
    }

    node->next = node->next->next;
    return SUCCESS;
}


int list_find_pos(List *li, int pos, aluno *al){

    if(li == NULL){
        return NULL_POINTER;
    }else if(li->head == NULL || pos > list_size(li)){
        return ELEM_NOT_FOUND;
    }else if(pos == 1){
        *al = li->head->data;
        return SUCCESS;
    }

    List_node *node;
    node = li->head;
    int cont = 1;

    while(pos != cont){
        node = node->next;
        cont++;
    }

    *al = node->data;
    return SUCCESS;
}


int list_find_mat(List *li, int mat, aluno *al){

    if(li == NULL){
        return NULL_POINTER;
    }else if(li->head == NULL){
        return ELEM_NOT_FOUND;
    }

    List_node *node;
    node = li->head;

    while(node->next != NULL){
        if(node->data.mat == mat){
            break;
        }
        node = node->next;
    }

    if(mat != node->data.mat){
        return ELEM_NOT_FOUND;
    }

    *al = node->data;
    return SUCCESS;
}


int list_front(List *li, aluno *al){

    if(li == NULL){
        return NULL_POINTER;
    }else if(li->head == NULL){
        return ELEM_NOT_FOUND;
    }

    *al = li->head->data;
    return SUCCESS;
}


int list_back(List *li, aluno *al){

    if(li == NULL){
        return NULL_POINTER;
    }else if(li->head == NULL){
        return ELEM_NOT_FOUND;
    }

    List_node *node;
    node = li->head;

    while(node->next != NULL){
        node = node->next;
    }

    *al = node->data;
    return SUCCESS;
}


int list_get_pos(List *li, int nmat, int *pos){

    if(li == NULL){
        return NULL_POINTER;
    }else if(li->head == NULL){
        return ELEM_NOT_FOUND;
    }

    List_node *node;
    node = li->head;
    int cont = 1;

    while(node->next != NULL){
        if(node->data.mat == nmat){
            break;
        }
        node = node->next;
        cont++;
    }

    if(nmat != node->data.mat){
        return ELEM_NOT_FOUND;
    }

    *pos = cont;
    return SUCCESS;
}


int list_free(List *li){

    if(li == NULL){
        return NULL_POINTER;
    }
    if(li->head == NULL){
        free(li);
        return SUCCESS;
    }

    List_node *node, *aux;
    node = li->head;


    while(node != NULL){
        aux = node->next;
        free(node);
        node = aux;
    }
    free(li);
    return SUCCESS;
}


int list_print(List* li){

    if(li == NULL){
        return NULL_POINTER;
    }

    List_node *node;
    node = li->head;

    printf("\nLista Alunos: \n\n");
    while(node != NULL){
        printf("Nome: %s\n", node->data.name);
        printf("Matricula %d\n", node->data.mat);
        printf("Notas: P1 %.2f; P2 %.2f; P3 %.2f\n\n", node->data.n1, node->data.n2, node->data.n3);
        node = node->next;
    }

    return SUCCESS;
}
