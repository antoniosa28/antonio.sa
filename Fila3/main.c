#include <stdio.h>
#include <stdlib.h>
#include "TAD-Queue.h"

int main()
{

    student s[6] = {{115, "Antonio", 6.0, 7.6, 9.8},
                   {110, "Samantha", 9.7, 6.6, 6.0},
                   {124, "Ricardo", 6.5, 6.1, 5.8},
                   {125, "Jorge", 10.0, 10.0, 6.3},
                   {127, "Augusto", 8.0, 4.4, 6.5},
                   {103, "Pedro", 6.5, 6.0, 5.0}};


    int check;
    Queue *qu;
    qu = create_queue(5);

    check = dequeue(qu);
    if(check == 0){
        printf("Erro\n");
    }else if(check == -2){
        printf("Empty\n");
    }else{
        printf("Dequeue Success\n");
    }
    check = enqueue(qu, s[0]);
    check = enqueue(qu, s[1]);
    check = enqueue(qu, s[2]);
    check = enqueue(qu, s[3]);
    check = enqueue(qu, s[4]);
    check = enqueue(qu, s[4]);
    check = dequeue(qu);
    check = dequeue(qu);
    check = dequeue(qu);
    check = enqueue(qu, s[0]);
    check = enqueue(qu, s[1]);

    if(check == 0){
        printf("Erro\n");
    }else if(check == -1){
        printf("Full\n");
    }else{
        printf("Enqueue Success\n");
    }

    printf("Print: \n");
    print_queue(qu);

    check = top(qu, &s[5]);

    printf("Top Name: %s\n", s[5].name);

    compact_queue(qu);
    print_queue(qu);

    printf("Liberado\n");
    check = free_queue(qu);


    return 0;
}
