/* Estrutura de Dados I
Matheus Marinho */

#include <stdio.h>

int main(){
    int numeros[10], aux; 
    int maior = 0, menor = 0;
    /* Criando vetor de numeros */
    printf("Insira um numero: ");
    for(int i=0; i<10; i++){
        scanf("%d", &numeros[i]);   
    }

    /* Verificando qual seria o maior */
    for(int i=0; i<9; i++){
         for (int j=0; j<9-i; j++){
            if(numeros[j] > numeros[j+1]){
            aux = numeros[j];
            numeros[j] = numeros[j+1];
            numeros[j+1] = aux;
            }
        }
    }
    maior = numeros[9];
    menor = numeros[0];
    
    printf("Maior = %d\n", maior);
    printf("Menor = %d\n", menor);

    return 0;
}