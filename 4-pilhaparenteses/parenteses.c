int verifica(char *c){

    Stack *pi;
    pi = stack_create();
    int i = 0;
    char teste;

    while(c[i] != '\0'){

        if(c[i] == ')'){
            stack_top(pi, &teste);
            if(teste != '('){
                stack_free(pi);
                return 0;
            }
            stack_pop(pi);

        }else if(c[i] == ']'){
            stack_top(pi, &teste);
            if(teste != '['){
                stack_free(pi);
                return 0;
            }
            stack_pop(pi);
        }else{
            stack_push(pi, c[i]);
        }

        i++;
    }

    if(stack_empty(pi) != 1){
        stack_free(pi);
        return 0;
    }

    stack_free(pi);
    return 1;
}