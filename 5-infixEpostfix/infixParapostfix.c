
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
