#include <stdio.h>
#include <stdlib.h>
#include "TAD_Pilha.h"

struct pilha{
    int qtd;
    int tamanho;
    char *c;
};

struct pilha2{
    int *n;
    int qtd;
    int tamanho;
};


// Pilha de inteiro
Pilha2* create_pilha2(){

    Pilha2 *pi;
    pi = malloc(sizeof(Pilha2));
    pi->n = malloc(50*sizeof(int));
    pi->qtd = 0;
    pi->tamanho = 50;

    return pi;
}

int push2(Pilha2* pi, int n){

    if(pi->qtd == pi->tamanho){
        return 0;
    }
    pi->n[pi->qtd] = n;
    pi->qtd++;
    return 1;

}

int pop2(Pilha2* pi){

    if(pi->qtd == 0){
        return 0;
    }

    pi->qtd--;

    return 1;
}

int top2(Pilha2 *pi, int *n){

    if(pi->qtd == 0){
        return 0;
    }

    *n = pi->n[pi->qtd-1];

    return 1;
}

// Pilha de char
Pilha* create_pilha(){

    Pilha *pi;
    pi = malloc(sizeof(Pilha));
    pi->c = malloc(50*sizeof(char));
    pi->qtd = 0;
    pi->tamanho = 50;

    return pi;
}

int push(Pilha* pi, char c){

    if(pi->qtd == pi->tamanho){
        return 0;
    }
    pi->c[pi->qtd] = c;
    pi->qtd++;
    return 1;

}

int pop(Pilha* pi){

    if(pi->qtd == 0){
        return 0;
    }

    pi->qtd--;

    return 1;
}

int top(Pilha *pi, char *c){

    if(pi->qtd == 0){
        return 0;
    }

    *c = pi->c[pi->qtd-1];

    return 1;
}

void imprimi(Pilha *pi){

    int cont = 0;
    while(cont != pi->qtd){
        printf("\n%c", pi->c[cont]);
        cont++;
    }
}

int pilhaVazia(Pilha *pi){
    if(pi->qtd == 0){
        return 1;
    }
    return 0;
}

void libera(Pilha *pi){
    free(pi);
}
