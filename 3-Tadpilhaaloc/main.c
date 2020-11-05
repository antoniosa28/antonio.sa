#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_Pilha.h"

int verifica(char *c){

    Pilha *pi;
    pi = create_pilha();
    int i = 0;
    char teste;

    while(c[i] != '\0'){

        if(c[i] == ')'){
            top(pi, &teste);
            if(teste != '('){
                libera(pi);
                return 0;
            }
            pop(pi);

        }else if(c[i] == ']'){
            top(pi, &teste);
            if(teste != '['){
                libera(pi);
                return 0;
            }
            pop(pi);
        }else{
            push(pi, c[i]);
        }

        i++;
    }

    if(pilhaVazia(pi) != 1){
        libera(pi);
        return 0;
    }

    libera(pi);
    return 1;
}


char *infix_posfix(char *inf){

    int tam_inf = strlen(inf);
    int x = 0, y = 0;

    char z = ' ', *posf;
    posf = malloc((tam_inf+1)*sizeof(char));

    Pilha*  pi;
    pi = create_pilha();


    while(inf[x] != '\0'){

        if(inf[x] == '('){
            push(pi,  inf[x]);

        }else if (inf[x] == '+' || inf[x] == '-'){

            while(z != '('){
                top(pi, &z);
                if(z != '('){
                    posf[y] = z;
                    y++;
                    pop(pi);
                }
            }
            push(pi, inf[x]);
            z = ' ';
        }else if (inf[x] == '*' || inf[x] == '/'){

            while(z != '(' && z != '+' && z != '-'){
                top(pi, &z);
                if(z != '(' && z != '+' && z != '-'){
                    posf[y] = z;
                    y++;
                    pop(pi);
                }
            }
            push(pi, inf[x]);
            z = ' ';
        }else if (inf[x] == ')'){

            while(z != '('){
                top(pi, &z);

                if(z != '('){
                    posf[y] = z;
                    y++;

                }
                pop(pi);
            }
            z = ' ';

        }else{
            posf[y] = inf[x];
            y++;
        }
        x++;
    }

    posf[y] = '\0';
    return posf;
}

int calcula(int a, int b, char op){

    switch(op){
        case '+': return b+a;
        break;
        case '-': return b-a;
        break;
        case '*': return b*a;
        break;
        case '/': return b/a;
        break;
    }
}

int resultado(char *posf){

    int i = 0, result;
    Pilha2 *pi;
    pi = create_pilha2();

    int a, b;

    while(posf[i] != '\0'){

        if(posf[i] == '+' || posf[i] == '-' || posf[i] == '/' || posf[i] == '*'){

            top2(pi, &a);
            pop2(pi);
            top2(pi, &b);
            pop2(pi);

            result = calcula(a, b, posf[i]);

            push2(pi, result);

        }else{
            int aux;
            aux = posf[i]-'0';
            push2(pi,aux);

        }

        i++;
    }
    return result;
}

int main()
{

    char inf[50] = "(5*(((9+8)*(4*6))+7))";
    char c[10] = "(([()]))";

    if(verifica(c)){
        printf("Valido");

    }else{
        printf("Invalido");
    }

    char *posf;
    posf = infix_posfix(inf);
    printf("\nInfixa: %s", inf);
    printf("\nPosfixa: %s", posf);

    int result;
    result = resultado(posf);
    printf("\nResultado: %d", result);


    return 0;
}
