#include <stdio.h>
#include <stdlib.h>
#include "TAD-ListaCirc.h"

int main()
{
  List *li;
    li = List_create();
    int num[6] = {1,2,3,4,5};


    List_push_front(li, num[0]);

    List_print(li);

    List_push_front(li, num[1]);

    List_print(li);

    List_push_back(li, num[2]);

    List_print(li);

    printf("Next elemento: \n");
    List_next_elem(li, &num[5]);
    printf("%d ", num[5]);
    List_next_elem(li, &num[5]);
    printf("%d ", num[5]);
    List_next_elem(li, &num[5]);
    printf("%d ", num[5]);
    List_next_elem(li, &num[5]);
    printf("%d \n", num[5]);
    List_print(li);
    List_pop_front(li);
    List_print(li);
    return 0;
}
