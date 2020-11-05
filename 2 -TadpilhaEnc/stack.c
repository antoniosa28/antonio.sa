#include "ListaEncadeada.h"
#include "stack.h"

Pilha* create_pilha(){
    Pilha *pi;
    pi = list_create();

    return pi;
}

int push(Pilha* pi, aluno al){

    return list_push_front(pi,al);
}

int pop(Pilha* pi){

    return list_pop_front(pi);
}

int top(Pilha* pi, aluno *al){

    return list_find_pos(pi, 1, al);
}

void imprimi(Pilha* pi){
    list_print(pi);
}
void libera(Pilha* pi){
    list_free(pi);
}
