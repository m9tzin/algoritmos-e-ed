/* Estrutura de Dados I
Matheus Marinho
 */
/******************************************************************************

Faça um programa que execute as seguintes etapas:

Digite números inteiros e os armazene em uma matriz de ordem M_LIN × M_COL
Verifique qual desses números é maior
Imprima os elementos da matriz e, em seguida, o seu maior elemento


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
 int numero, matriz[100][100];
 int M_LIN = atoi(argv[1]);
 int M_COL = atoi(argv[2]);
 int i, j;

 i = M_LIN;
 j = M_COL;

    /* Initializing the matrix */
    for(int i=0; i<M_LIN; i++){
        for(int j=0; j<M_COL; j++){
            printf("Insira um valor para A[%d][%d]: ",i,j);
            scanf("%d", &numero);
            matriz[i][j]=numero;
        }
        printf("\n");
    }
    
    /* Printing the matrix */
     for(int i=0; i<M_LIN; i++){
        printf("| ");
        for(int j=0; j<M_COL; j++){
            // printf("A[%d][%d] = %d ", i,j,matriz[i][j]);
            printf(" %d", matriz[i][j]);
        }
        printf(" |");
        printf("\n");
    }

    printf("\n");
    /* Searching the biggest */
    int maior = matriz[0][0];
    for(int i=0; i<M_LIN; i++){
        for(int j=0; j<M_COL; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }

    /* Searching the lowest */
    int lower = matriz[0][0];
    for(int i=0; i<M_LIN; i++){
        for(int j=0; j<M_COL; j++){
            if(matriz[i][j] < lower){
                lower = matriz[i][j];
            }
        }
    }

    printf("O maior = [%d]\n", maior);
    printf("O menor = [%d]\n", lower);

}