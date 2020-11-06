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
