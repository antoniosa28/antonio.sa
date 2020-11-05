#include "1ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    aluno al;
    aluno a[6] = {{115, "Antonio", 6.0, 7.6, 9.8},
                  {110, "Samantha", 9.7, 6.6, 6.0},
                  {124, "Ricardo", 6.5, 6.1, 5.8},
                  {125, "Jorge", 10.0, 10.0, 6.3},
                  {127, "Augusto", 8.0, 4.4, 6.5},
                  {103, "Pedro", 6.5, 6.0, 5.0}};

    List *li;
    li = list_create();

    int verifica, i, pos;
    for(i = 4; i >= 0; i--){
        verifica = list_push_front(li, a[i]);
        if(verifica == -3){
            printf("\nNull Pointer\n");
        }else{
            printf("\nPush front Success\n");
        }
    }

    verifica = list_push_back(li, a[0]);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else{
        printf("\nPush Back Success\n");
    }

    verifica = list_print(li);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else{
        printf("\nPrint Success\n");
    }
    verifica = list_insert(li, 1, a[3]);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else if(verifica == -1){
        printf("\nOut of memory\n");
    }else{
        printf("\nInsert pos Success\n");
    }


    verifica = list_print(li);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else{
        printf("\nPrint Success\n");
    }

    verifica = list_insert_sorted(li, a[5]);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else{
        printf("\nInsert Sorted Success\n");
    }

    verifica = list_print(li);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else{
        printf("\nPrint Success\n");
    }

    printf("\nTamanho da lista %d\n", list_size(li));

    verifica = list_pop_front(li);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else if(verifica == -2){
        printf("\nElement Not Found");
    }else{
        printf("\nPop Front Success\n");
    }

    verifica = list_pop_back(li);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else if(verifica == -2){
        printf("\nElement Not Found\n");
    }else{
        printf("\nPop Back Success\n");
    }


    verifica = list_erase(li, 7);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else if(verifica == -2){
        printf("\nElement Not Found\n");
    }else{
        printf("\nErase Success\n");
    }

    verifica = list_print(li);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else{
        printf("\nPrint Success\n");
    }

    verifica = list_find_pos(li, 4, &al);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else if(verifica == -2){
        printf("\nElement Not Found\n");
    }else{
        printf("\nFind Pos Success\n");
        printf("Aluno: %s\n", al.name);
    }

    verifica = list_find_mat(li, 110, &al);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else if(verifica == -2){
        printf("\nElement Not Found\n");
    }else{
        printf("\nFind Mat Success\n");
        printf("Aluno: %s\n", al.name);
    }

    verifica = list_front(li, &al);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else if(verifica == -2){
        printf("\nElement Not Found\n");
    }else{
        printf("\nFind Front Success\n");
        printf("Aluno: %s\n", al.name);
    }

    verifica = list_back(li, &al);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else if(verifica == -2){
        printf("\nElement Not Found\n");
    }else{
        printf("\nFind Back Success\n");
        printf("Aluno: %s\n", al.name);
    }

    verifica = list_get_pos(li, 110, &pos);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else if(verifica == -2){
        printf("\nElement Not Found\n");
    }else{
        printf("\n Get Pos Success\n");
        printf("Pos: %d\n", pos);
    }


    verifica = list_free(li);
    if(verifica == -3){
        printf("\nNull Pointer\n");
    }else{
        printf("\nFree Success\n");
    }

}
