#define N 100
char pilha[N];
int t;

char *infixaParaPosfixa (char *inf) {
   int n = strlen (inf);
   char *posf;
   posf = malloc ((n+1) * sizeof (char));
   criapilha ();
   empilha (inf[0]);       // empilha '('

   int j = 0;
   for (int i = 1; inf[i] != '\0'; ++i) {
      switch (inf[i]) {
         char x;
         case '(': empilha (inf[i]);
                   break;
         case ')': x = desempilha ();
                   while (x != '(') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   break;
         case '+':
         case '-': x = desempilha ();
                   while (x != '(') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x);
                   empilha (inf[i])
                   break;
         case '*':
         case '/': x = desempilha ();
                   while (x != '(' && x != '+' && x != '-') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x);
                   empilha (inf[i]);
                   break;
         default:  posf[j++] = inf[i];
      }
   }
   posf[j] = '\0';
   return posf;
}


