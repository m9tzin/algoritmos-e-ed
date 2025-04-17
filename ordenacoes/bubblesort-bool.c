/* Estrutura de Dados II
    Matheus Marinho 
    Bubble Sort com boolean improvement */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubbleSortbool(int arr[], int size){
    int aux;
    bool swap;
    swap = true;
    for(int i = 0; i <= size-1 && swap; i++){
        swap = false;
        for(int j = 0; j<= size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap = true;
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }

}

int main(){
    int arr[] = {5, 8, 2, 10, 15, 9, 25, 27, 23, 40};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Vetor original: \n");
    for(int i=0; i<=size-1; i++){
        printf("[%d]", arr[i]);
    }
    printf("\n");
    bubbleSortbool(arr, size);
    printf("\n");
    
    printf("Vetor ordenado: \n");
    for(int i=0; i<=size-1; i++){
        printf("[%d]", arr[i]);
    }
    printf("\n");

    return 0;
}