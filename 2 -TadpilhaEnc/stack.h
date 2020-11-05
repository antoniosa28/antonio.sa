#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "aluno.h"


typedef struct list Pilha;

Pilha* create_pilha();
int push(Pilha* pi, aluno al);
int pop(Pilha* pi);
int top(Pilha* pi, aluno *al);
void imprimi(Pilha* pi);
void libera(Pilha* pi);

#endif // STACK_H_INCLUDED
