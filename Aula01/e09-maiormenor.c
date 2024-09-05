/* Estrutura de Dados I
 Matheus Marinho */

/* Elabore um programa que faça leitura de vários números inteiros, até que se digite
um número negativo. O programa deve mostrar todos os números digitados (sem
o negativo). */

#include <stdio.h>
#define limit 100

int main(){
    int num, i=0;
    int numeros[limit];

    printf("Insira um numero inteiro: (Numero negativo = encerra o programa.)\n");
    scanf("%d", &num);
    
    if(num >= 0){
        numeros[i] = num;
        i++;
    }

    while(num >= 0){
        printf("Insira um numero inteiro: (Numero negativo = encerra o programa.)\n");
        scanf("%d", &num);
        
        if(num >= 0){
        numeros[i] = num;
        i++;
        }
    }
       
    printf("Numeros inseridos:\n");
    for(int k=0; k<i; k++){
        printf("[%d] ", numeros[k]);
    }

    printf("\nPrograma encerrado.");

     return 0;
 }
