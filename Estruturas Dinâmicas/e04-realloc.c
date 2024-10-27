/* Estrutura de Dados I
Matheus Marinho */

/* Escreva um programa para fazer a realocação de um espaço reservado que já contém uma string, com o objetivo de adicionar mais espaço e, consequentemente, mais caracteres. Mostre o resultado da string e seu endereço de memória.

Exemplo:
String = LinguagemC, Address = 8
String = LinguagemCBrasil, Address = 8
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *p;
    p = (char*)malloc(10);
    
    if(p == NULL){
        printf("Erro.");
        return -1;
    }

    strcpy(p, "Palavra");
    printf("String = %s, Address: %u\n", p, p);

    p = (char*)realloc(p, 20);
    strcat(p, "Adicionada");
    printf("String = %s, Address: %u\n", p, p);

    free(p);

    return 0;
}