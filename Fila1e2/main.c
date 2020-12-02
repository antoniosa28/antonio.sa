#include "TAD-Queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    aluno a[6] = {{115, "Antonio", 6.0, 7.6, 9.8},
                  {110, "Samantha", 9.7, 6.6, 6.0},
                  {124, "Ricardo", 6.5, 6.1, 5.8},
                  {125, "Jorge", 10.0, 10.0, 6.3},
                  {127, "Augusto", 8.0, 4.4, 6.5},
                  {103, "Pedro", 6.5, 6.0, 5.0}};

    int i;
    Queue *qu;
    qu = queue_create();

    printf("\n INSERÇÃO: \n");
    for(i = 0; i < 4; i++){
        enqueue(qu, a[i]);
    }
    print(qu);

    printf("Remove um elemento dessa da fila");
    dequeue(qu);

    print(qu);

    back(qu, &a[5]);

    printf("Primeiro elemento a entrar na fila %s", a[5].name);
}


