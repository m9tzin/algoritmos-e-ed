/* Estrutura de Dados I
Matheus Marinho */

/* Passagem de parametros no C */

#include <stdio.h>

int main(int argc, char* argv[]){
    printf("%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    
    return 0;
}
