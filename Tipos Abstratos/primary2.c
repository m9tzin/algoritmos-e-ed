/* Estrutura de Dados I
Matheus Sousa Marinho */

/* Mostre o tamanho para cada tipo de dado primário em primary.c */

#include <stdio.h>
#include <stdbool.h>

int main(){
    struct ContaCorrente {
    unsigned int numero; 
    char*       nomeTitular;
    unsigned int telefoneTitular;
    bool         contaConjunta;
    char*       nomeDependente;   
    float        saldoAtual;
    bool         estaAtiva;
};

    printf("Tamanho do unsigned int numero    : %zu bytes\n", sizeof(unsigned int));
    printf("Tamanho do char* nomeTitular    : %zu bytes\n", sizeof(char*));
    printf("Tamanho do unsigned int telefoneTitular    : %zu bytes\n", sizeof(unsigned int));
    printf("Tamanho do char* nomeDependente    : %zu bytes\n", sizeof(char*));
    printf("Tamanho do bool contaConjunta    : %zu bytes\n", sizeof(bool));
    printf("Tamanho do float saldoAtual    : %zu bytes\n", sizeof(float));
    printf("Tamanho do bool estaAtiva    : %zu bytes\n", sizeof(bool));

    printf("Tamanho da struct ContaCorrente    : %zu bytes\n", sizeof(struct ContaCorrente));
    
    return 0;
}