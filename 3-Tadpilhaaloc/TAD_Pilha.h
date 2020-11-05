
typedef struct pilha Pilha;
typedef struct pilha2 Pilha2;

Pilha* create_pilha();
int push(Pilha* pi, char c);
int pop(Pilha* pi);
int top(Pilha *pi, char *c);
void imprimi(Pilha *pi);
int pilhaVazia(Pilha *pi);
void libera(Pilha *pi);

Pilha2* create_pilha2();
int pop2(Pilha2* pi);
int push2(Pilha2* pi, int n);
int top2(Pilha2 *pi, int *n);

