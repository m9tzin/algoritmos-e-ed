/* Estrutura de Dados I
Matheus Marinho */

/* Escreva um programa para armazenar um nome de até N bytes digitados pelo usuário: */
/* Requisitos:
Verifique que a memória seja alocada corretamente e caso não seja informe ao usuário
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    char *p; /* pointer to char */
    int n; /* número de bytes */

     if(argc == 2){
        n = atoi(argv[1]); 
        p = (char*)malloc(n * sizeof(char));

        if(p == NULL){
            printf("Memoria Insuficiente.\n");
            return -1;
        }
        printf("Insira o nome: ");
        fgets(p, n, stdin);

        printf("Nome: %s\n", p);

        free(p);

    }else{
        printf("Parametro nao informado.\n");  
    } 
    
    return 0;
}