#ifndef TAD_LISTA_H_INCLUDED
#define TAD_LISTA_H_INCLUDED

#include "aluno.h"

typedef struct lista Lista;

Lista* cria_lista(int tam);
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, aluno *a);
int consulta_lista_mat(Lista* li, int mat, aluno *a);
int insere_lista_final(Lista* li, aluno a);
int insere_lista_inicio(Lista* li, aluno a);
int insere_lista_ordenada(Lista* li, aluno a);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
int compactar_lista(Lista* li);


#endif // TAD_LISTA_H_INCLUDED
