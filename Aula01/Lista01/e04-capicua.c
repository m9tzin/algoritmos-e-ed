/* Estrutura de Dados I
Matheus Marinho */

/* Alan deve pegar um número com quatro dígitos e verificar se o reverso desse número é ele mesmo. Se for, Alan deve responder "sim", caso contrário, deve responder "não".

Escreva um programa em C que implemente essa verificação conforme descrita a seguir.

Entrada
Um inteiro n ≥ 1 representando a quantidade de números que Alan deve analisar.
n números inteiros de até quatro dígitos.
Saída
As frases "sim" ou "não", que correspondem à resposta para cada número analisado. */

#include <stdio.h>

void palindromoCheck(int number){
    int original = number, inverse = 0, lastDigit;

    /* Inverter o numero */
    while(number != 0){
        lastDigit = number % 10; /* Ultimo digito */
        inverse = inverse * 10 + lastDigit; /* Construindo o inverso */
        number /= 10; /* Remover o ultimo digito da esquerda */
    }

    if(inverse == original){
        printf(" yes");
    }else{
        printf(" no");
    }
}

void verify(int limit){
    int array[limit];
    for(int i=0; i<limit; i++){
        printf("Insira um numero: \n");
        scanf("%d", &array[i]);
    }
    for(int k=0; k<limit; k++){
        palindromoCheck(array[k]); 
    }
}

int main(){
    int limit;

    printf("Quantos numeros serao analisados? \n");
    scanf("%d", &limit);
    verify(limit);

    return 0;
}