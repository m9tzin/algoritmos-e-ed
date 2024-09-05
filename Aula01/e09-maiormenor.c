/* Estrutura de Dados I
 Matheus Marinho */

/* Elabore um programa que faça leitura de vários números inteiros, até que se digite
um número negativo. O programa deve mostrar todos os números digitados (sem
o negativo). */

#include <stdio.h>

int main(){
    int number;
    
    while(number > 0){
        printf("Insira um numero:");
        scanf("%d", &number);
        printf("%d\n", number);
    }
    printf("Numero negativo inserido, programa encerrado.");
    return 0;
 }
