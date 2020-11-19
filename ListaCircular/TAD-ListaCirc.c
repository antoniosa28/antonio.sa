#include <stdio.h>
#include <stdlib.h>
#include "TAD-ListaCirc.h"

struct node{
    struct node *next;
    int num;
};


struct List_circ{
    struct node *end;
    struct node *next_elem;
    int qtd;
};


List *List_create(){

    List *li;

    li = malloc(sizeof(List));
    li->end = NULL;
    li->qtd = 0;
    li->next_elem = NULL;

    return li;
}

int List_push_front(List *li, int n){

    if(li == NULL){
        return 0;
    }
    node *nd;
    nd = malloc(sizeof(node));
    nd->num = n;
    li->qtd++;

    if(li->end == NULL){
        li->end = nd;
        li->end->next = li->end;
        li->next_elem = li->end;
        return 1;
    }
    nd->next = li->end->next;
    li->end->next = nd;

    return 1;
}

int List_push_back(List *li, int n){


    if(li == NULL){
        return 0;
    }
    node *nd;
    nd = malloc(sizeof(node));
    nd->num = n;
    li->qtd++;

    if(li->end == NULL){
        li->end = nd;
        li->end->next = li->end;
        li->next_elem = li->end;
        return 1;
    }
    nd->next = li->end->next;
    li->end->next = nd;
    li->end = nd;

    return 1;
}

int List_pop_front(List *li){

    if(li == NULL || li->end == NULL){
        return 0;
    }

    node *nd;
    nd = li->end->next;
    li->end->next = li->end->next->next;
    free(nd);
    li->qtd--;

    return 1;
}

void List_print(List *li){

    node *node;

    node = li->end->next;


    if(node == NULL){
        printf("%d \n", li->end->next->num);
    }else{

        int cont = 0;
        printf("Lista: \n");
        while(cont < li->qtd){
            printf("%d ", node->num);
            node = node->next;
            cont++;
        }
    }

    printf("\n");
}

int List_next_elem(List *li, int *num){

    *num = li->next_elem->num;
    li->next_elem = li->next_elem->next;

    return 1;

}
