#include "ListaEncadeada.h"
#include "TAD-Queue.h"


Queue* queue_create(){
return list_create();
}

int enqueue(Queue *qu, aluno al){
return list_push_front(qu, al);
}

int dequeue(Queue *qu){
return list_pop_back(qu);
}

int front(Queue *qu, aluno *al){
return list_front(qu, al);
}

int back(Queue *qu, aluno *al){
return list_back(qu, al);
}

void print(Queue *qu){
    list_print(qu);
}
