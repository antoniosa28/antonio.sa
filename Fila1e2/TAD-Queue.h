#define TAD-QUEUE_H_INCLUDED

#include "aluno.h"
typedef struct list Queue;

Queue* queue_create();
int enqueue(Queue *qu, aluno al);
int dequeue(Queue *qu);
int front(Queue *qu, aluno *al);
int back(Queue *qu, aluno *al);
void print(Queue *qu);



