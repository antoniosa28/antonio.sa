#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "aluno.h"

int main()
{
    aluno a[6] = {{115, "Antonio", 6.0, 7.6, 9.8},
                  {110, "Samantha", 9.7, 6.6, 6.0},
                  {124, "Ricardo", 6.5, 6.1, 5.8},
                  {125, "Jorge", 10.0, 10.0, 6.3},
                  {127, "Augusto", 8.0, 4.4, 6.5},
                  {103, "Pedro", 6.5, 6.0, 5.0}};

    Pilha *pi;

    pi = cria_lista(5);

    for(int i=0; i < 5; i++){
        push(pi, a[i]);
    }
    pop(pi);

    top(pi, &a[5]);
    printf("\nNome: %s\n", a[5].nome);

    imprimi_pilha(pi);

    libera_pilha(pi);


    return 0;
}
