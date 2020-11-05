#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "stack.h"

int main()
{

   aluno a[6] = {{115, "Antonio", 6.0, 7.6, 9.8},
                  {110, "Samantha", 9.7, 6.6, 6.0},
                  {124, "Ricardo", 6.5, 6.1, 5.8},
                  {125, "Jorge", 10.0, 10.0, 6.3},
                  {127, "Augusto", 8.0, 4.4, 6.5},
                  {103, "Pedro", 6.5, 6.0, 5.0}};

    Pilha *pi;
    pi = create_pilha();

    push(pi, a[0]);
    push(pi, a[1]);
    push(pi, a[2]);
    pop(pi);
    top(pi, &a[5]);
    printf("\n%s\n", a[5].name);

    imprimi(pi);
    libera(pi);


}
