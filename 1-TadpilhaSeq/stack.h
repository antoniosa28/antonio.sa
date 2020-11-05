#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "aluno.h"

typedef struct lista Pilha;

Pilha* cria_pilha(int tam);
int push(Pilha* pi, aluno al);
int pop(Pilha* pi);
int top(Pilha* pi, aluno *al);
void libera_pilha(Pilha* pi);
void imprimi_pilha(Pilha* pi);

#endif // STACK_H_INCLUDED
