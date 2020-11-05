#include "TAD_lista.h"
#include <stdio.h>
#include <math.h>

struct lista{
    int qtd;
    int tamanho;
    aluno *dados;
};

Lista* cria_lista(int tam){
     Lista *l;
     l = malloc (sizeof(Lista));
     l->dados = malloc(tam*sizeof(aluno));
     l->tamanho = tam;
     if(l != NULL && l->dados != NULL){
        l->qtd = 0;
     }
     return l;
}

 void libera_lista(Lista *li){
     free(li->dados);
     free(li);
 }

 int consulta_lista_pos(Lista* li, int pos, aluno *a){

     if(li == NULL){
        return 0;
     }else if(pos+1 > li->qtd || pos+1 <= 0){
        return -2;
    }

     *a = li->dados[pos-1];
     return 1;
}

 int consulta_lista_mat(Lista* li, int mat, aluno *a){

     int i;

     if(li == NULL){
        return 0;
     }
     for(i = 0; i < li->qtd; i++){
         if(li->dados[i].matricula == mat){
            *a = li->dados[i+1];
            return 1;
         }
     }
    return -2;
}

 int insere_lista_final(Lista* li, aluno a){

     if(li == NULL){
        return 0;
     }else if(li->qtd == li->tamanho){
         li->tamanho *= 2;
         li->dados = realloc(li->dados, li->tamanho*sizeof(aluno));
     }

     li->dados[li->qtd] = a;
     li->qtd++;
    return 1;
}


 int insere_lista_inicio(Lista* li, aluno a){

     if(li == NULL){
        return 0;
     }else if(li->qtd == li->tamanho){
         li->tamanho *= 2;
         li->dados = realloc(li->dados, li->tamanho*sizeof(aluno));
     }

     int i;

     for(i = li->qtd; i > 0 ;i--){
        li->dados[i] = li->dados[i-1];
     }

     li->dados[0] = a;
     li->qtd++;

    return 1;
 }

 int insere_lista_ordenada(Lista* li, aluno a){

     if(li == NULL){
        return 0;
     }else if(li->qtd == li->tamanho){
        li->tamanho *= 2;
        li->dados = realloc(li->dados, li->tamanho*sizeof(aluno));
     }
     aluno aux;
     li->dados[li->qtd] = a;
     li->qtd++;

     if(li->qtd > 1){

        int i, j;

        for(i = 0; i < li->qtd; i++){
            for(j = i+1; j < li->qtd; j++){
                if(li->dados[j].matricula < li->dados[i].matricula){
                    aux = li->dados[i];
                    li->dados[i] = li->dados[j];
                    li->dados[j] = aux;
                }
            }
        }
    }
    return 1;
 }

 int remove_lista(Lista* li, int mat){

     int i;

     if(li == NULL){
        return 0;
     }else if(li->qtd == 0){
        return -3;
     }
     for(i = 0; i < li->qtd; i++){
         if(li->dados[i].matricula == mat){
            li->dados[i] = li->dados[li->qtd-1];
            li->qtd--;
            return 1;
         }
    }

    return -4;
 }

 int remove_lista_inicio(Lista* li){
 if(li == NULL){
 return 0;
 }else if(li->qtd == 0){
 return -3;
 }

 int i;

 for(i = 0; i < li->qtd; i++){
 li->dados[i] = li->dados[i+1];
 }

 li->qtd--;
 return 1;
 }

 int remove_lista_final(Lista* li){

     if(li == NULL){
        return 0;
     } else if(li->qtd == 0){
        return -3;
     }
     li->qtd--;
     return 1;
}
int tamanho_lista(Lista* li){

     if(li == NULL){
        return 0;
     } else if(li->qtd == 0){
        return -2;
     }
     return li->qtd;
 }

 int lista_cheia(Lista* li){
     if(li == NULL){
        return 0;
     } else if(li->qtd == li->tamanho){
        return -1;
     } else{
        return 1;
     }
 }

 int lista_vazia(Lista* li){
     if(li == NULL){
        return 0;
     } else if(li->qtd == 0){
        return -3;
     } else{
        return 1;
     }
 }

 void imprime_lista(Lista* li){

     int i;

     if(li->qtd == 0){
        printf("Lista Vazia");

     }else{
        printf("\nLista: \n");

        for(i = 0; i < li->qtd; i++){
             printf("Matricula: %d\n", li->dados[i].matricula);
             printf("Nome: %s\n", li->dados[i].nome);
             printf("Notas: p1 %.2f, p2 %.2f, p3 %.2f\n\n", li->dados[i].n1, li->dados[i].n2, li->dados[i].n3);
         }
    }
 }

 int compactar_lista(Lista* li){
     int tam;
     tam = ceil(li->qtd/li->tamanho)*li->tamanho;

     if(li == NULL){
        return 0;
     }else if(li->qtd == 0){
        return -3;
     }else if(li->qtd == li->tamanho){
        return -1;
     }
    li->dados = realloc(li->dados, tam*sizeof(aluno));
    return 1;
}
