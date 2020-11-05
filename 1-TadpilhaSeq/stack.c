#include "TAD_lista.h"
#include "stack.h"

Pilha* cria_pilha(int tam){

    Pilha* li;
    li = cria_lista(tam);

    return li;
}

int push(Pilha* pi, aluno al){

    return insere_lista_inicio(pi, al);
}

int pop(Pilha* pi){

    return remove_lista_inicio(pi);
}

int top(Pilha* pi, aluno *al){

    return consulta_lista_pos(pi, 1, al);
}

void libera_pilha(Pilha* pi){
    libera_lista(pi);
}

void imprimi_pilha(Pilha* pi){
    imprime_lista(pi);
}
