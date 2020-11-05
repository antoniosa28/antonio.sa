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

// Insere no comeco da lista
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

// Inseri lista no final
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

// Inserir elemento em posição ordenada REVISAR
int list_insert_sorted(List *li, aluno al){

    if(li == NULL){
        return NULL_POINTER;
    }

    List_node *node, *aux;
    node = malloc(sizeof(List_node));
    aux = li->head;

    do{
        aux = aux->next;
    }while(al.mat > aux->next->data.mat);



    return SUCCESS;
}

// Retorna tamanho da lista
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

// Remove primeiro elemento
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

// Liberando lista
int list_free(List *li){

    if(li == NULL){
        return NULL_POINTER;
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

// Imprimindo lista
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
