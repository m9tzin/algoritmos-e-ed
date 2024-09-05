/* Estrutura de Dados I
 Matheus Marinho */

/* Elabore um programa que faça leitura de vários números inteiros, até que se digite
um número negativo. O programa deve mostrar todos os números digitados (sem
o negativo). */

#include <stdio.h>

int main(){
    int num, menor, maior;

    printf("Insira um numero inteiro: (Numero negativo = encerra o programa.)\n");
    scanf("%d", &num);
    
    maior = num;
    menor = num;

    while(num > 0){
        if (num > maior){
            maior = num;
        }
        if (num < menor){
            menor = num;
        }
        printf("Insira um numero inteiro: (Numero negativo = encerra o programa.)\n");
        scanf("%d", &num);
    }
        
        printf("O maior numero foi [%d] e o menor foi [%d].\n", maior, menor);

        printf("Programa encerrado.");

     return 0;
 }
