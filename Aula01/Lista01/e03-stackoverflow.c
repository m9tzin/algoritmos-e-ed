/* Estrutura de Dados I
Matheus Marinho */

/* Elabore um programa em C que seja capaz de receber o maior número que um computador consegue representar em memória e uma expressão de soma ou multiplicação entre dois inteiros positivos. Determine se ocorrerá, ou não, overflow naquele computador.

Entrada
Um inteiro representando o maior número que o computador consegue representar.
Dois números inteiros a serem operados.
Um caractere, ‘+’ ou ‘×’, representando adição ou multiplicação.

Saída
A frase "overflow" se o resultado causar um overflow, ou "no overflow" caso contrário. */

#include <stdio.h>

int overflowCalc (int numero1, int numero2, char operator, int maiorNumero){
    int result;
    switch(operator){
        case '+':
        result = numero1 + numero2;
        break;

        case 'x':
        result = numero1 * numero2;
        break;

        default:
        printf("Invalid operator.\n");
    }

    if( result > maiorNumero){
        printf("overflow.\n");
    }else{
        printf("no overflow.\n");
    }
    return result;
}

int main(){
    int maiorNumero, numero1, numero2;
    char operator;
    
    printf("Qual o maior numero suportado? (overflow limit)\n");
    scanf("%d", &maiorNumero);

    printf("Insira dois numeros inteiros:\n");
    scanf("%d %d", &numero1, &numero2);    
    
    printf("Qual operacao? [+] = adicao, [x] = multiplicacao\n");
    scanf(" %c", &operator);   

    overflowCalc(numero1, numero2, operator, maiorNumero);
    
    return 0;
}