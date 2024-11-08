/* Estrutura de Dados I
Matheus Marinho */

/* Faça um programa que leia dez números e os imprima em ordem inversa. */

#include <stdio.h>

int main(){
    int numeros[10]; /* [0] ... [9] - 10 lugares */
    /* Lendo os numeros */
    printf("Insira um numero: ");
    for(int i=0; i<10; i++){
        scanf("%d", &numeros[i]);
    }

    /* Imprimindo na ordem inversa */
    for(int k=9; k>=0; k--){
        printf("[%d] ", numeros[k]);
    }


    return 0;
}