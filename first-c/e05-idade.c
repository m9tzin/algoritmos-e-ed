// Estrutura de Dados 1
// 31/08/2024
// Matheus Marinho

/* Fazer um programa que ao entrar com sua idade diga se você é maior de idade ou
não. */

#include <stdio.h>

int main(){
    int idade;
    
    printf("Voce e maior de idade?\n");
    
    printf("Qual sua idade?");
    scanf("%d", &idade);

    if(idade >= 18){
        printf("Voce e maior de idade.");
    }else{
        printf("Voce nao e maior de idade.");
    }
    
    return 0;
}