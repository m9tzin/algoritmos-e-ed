/* Estrutura de Dados I
Matheus Marinho */

#include <stdio.h>
#define limit 10

int main(){
    int numeros[limit], aux; 
    int maior = 0, menor = 0;
    /* Criando vetor de numeros */
    printf("Insira um numero: ");
    for(int i=0; i<limit; i++){
        scanf("%d", &numeros[i]);   
    }

    /* Ordenar para saber qual sera o maior */
    for(int i=0; i<limit; i++){
         for (int j=0; j<limit-i-1; j++){
            if(numeros[j] > numeros[j+1]){
            aux = numeros[j];
            numeros[j] = numeros[j+1];
            numeros[j+1] = aux;
            }
        }
    }
    maior = numeros[9];
    menor = numeros[0];
    printf("\n");
    /* Printing */
    printf("Elementos do vetor: ");
    for(int i=0; i<limit; i++){
        printf("[%d] ", numeros[i]);
    }
    printf("\n");
    printf("Maior = %d\n", maior);
    printf("Menor = %d\n", menor);


    return 0;
}