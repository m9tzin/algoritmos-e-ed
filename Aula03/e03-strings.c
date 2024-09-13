/* Estrutura de Dados I
Matheus Marinho */

/* Faça um programa que permita salvar seu “nome e sobrenome” em uma única string. */

#include <stdio.h>
#include <string.h>
#define limit 100

int main(void){
    char nomeCompleto[limit];
    char nome[] = "world";
        char cmp1[] = "abcdefg";
        char cmp2[] = "wasd";

    printf("Insira seu nome: ");
    if(fgets(nomeCompleto, sizeof(nomeCompleto), stdin) != NULL){
        printf("Seu nome e %s\n", nomeCompleto);
    }else{
        printf("Erro de input.\n");
    }

    /* Responda: Descubra o que fazem as seguintes funções:
    strlen, strcpy, strcat, strcmp, strncmp, stricmp */

    printf("%d caracteres\n", (strlen(nomeCompleto)-1)); /* strlen retorna o tamanho da string */
    printf("%s\n", strcpy(nome, nomeCompleto)); /* strcopy copia o conteudo de uma string para outro vetor de string */
    strcat(nome, " hello"); /* strcat acrescenta parte de uma string no fim da outra */
    printf("%s\n", nome);
    int cmp = strcmp(cmp2, cmp1); /* strcmp compara a quantidade de caracteres de duas strings, fazendo a diferença de caracteres entre elas. */
    printf("%d\n", cmp);
    int ncmp = strncmp(cmp2, cmp1, 4); /* strncmp compara os n primeiros caracteres retornando um inteiro indicando qual o maior */
    printf("%d\n", ncmp);
    int icmp = stricmp(cmp2, cmp1); /* stricmp compara duas strings ignorando caracteres maíusculos e minúsculos */
    printf("%d\n", icmp); /* 1>0 => cmp2 > cmp1 - Comparação feita em ASCII */
    
    return 0;
}