#include <stdio.h>
#include <stdlib.h>
#include "TDLinkedList.h"

int main(){

    aluno a2;
    aluno a[4] = {{112, "Antonio", 7.6, 8.2, 10.0},
                  {116, "Samantha", 8.6, 9.3, 8.0},
                  {127, "Ricardo", 5.6, 6.2, 5.7},
                  {130, "Fabio", 6.0, 2.2, 3.5}};
                  {130, "Fabio", 6.0, 2.2, 3.5}};

    List *li;
    int verifica, i;

    li = list_create();




    for(i = 0; i < 2; i++){
        verifica = list_push_front(li, a[i]);
        if(verifica == -2){
            printf("\nOut of Memory\n");
        }else{
            printf("\nPush Front Success\n");
        }
    }

    verifica = list_push_back(li, a[2]);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else{
        printf("\nPush Back Success\n");
    }



    verifica = list_insert(li, 1, a[3]);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else if(verifica == -1){
        printf("\nNull Pointer\n");
    }else{
        printf("\nPrint Success\n");
    }

    int tamanho;
    tamanho = list_size(li);
    printf("\nTamanho lista: %d\n", tamanho);

    verifica = list_print_forward(li);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else{
        printf("\nPrint Success\n");
    }

    /*
    verifica = list_pop_front(li);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else if(verifica == -3){
        printf("\nOut of Range\n");
    }else{
        printf("\nPop Front\n");
    }

    verifica = list_pop_back(li);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else if(verifica == -3){
        printf("\nOut of Range\n");
    }else{
        printf("\nPop Back\n");
    }
    */

    verifica = list_erase(li, 5);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else if(verifica == -1){
        printf("\nNull Pointer\n");
    }else{
        printf("\nErase Success\n");
    }

    verifica = list_print_forward(li);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else{
        printf("\nPrint Forward Success\n");
    }

    verifica = list_find_pos(li, 4, &a2);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else if(verifica == -1){
        printf("\nNull Pointer\n");
    }else{
        printf("\nFind Pos Success\n");
        printf("Aluno: %s\n", a2.nome);
    }

    verifica = list_find_mat(li, 128, &a2);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else if(verifica == -4){
        printf("\nElement Not Found\n");
    }else{
        printf("\nFind Mat Success\n");
        printf("Aluno: %s\n", a2.nome);
    }

    verifica = list_front(li, &a2);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else if(verifica == -3){
        printf("\nOut of Range\n");
    }else{
        printf("\nFind Front Success\n");
        printf("Aluno: %s\n", a2.nome);
    }

    verifica = list_back(li, &a2);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else if(verifica == -3){
        printf("\nOut of Range\n");
    }else{
        printf("\nFind Back Success\n");
        printf("Aluno: %s\n", a2.nome);
    }

    int pos;
    verifica = list_get_pos(li, 128, &pos);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else if(verifica == -4){
        printf("\nElement Not Found\n");
    }else{
        printf("\nGet pos Success\n");
        printf("Pos: %d\n", pos);
    }

    verifica = list_print_reverse(li);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else{
        printf("\nPrint Reverse Success\n");
    }

    verifica = list_free(li);
    if(verifica == -2){
        printf("\nOut of Memory\n");
    }else{
        printf("\nFree Success\n");
    }

    return 0;
}

