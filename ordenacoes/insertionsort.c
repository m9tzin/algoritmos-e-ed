/* Estrutura de Dados II
Matheus Marinho
Insertion Sort */

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int tam){
    int chave, j;
    for(int i = 1; i < tam; i++){
        chave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > chave){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = chave;        
    }
}

int main(){
    int arr[] = {50, 16, 23, 5, 7, 12, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Vetor original: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Chamando a função para ordenar o array
   insertionSort(arr, size); 
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Menor valor do array: [%d]", arr[0]);
    printf("\n");
    printf("Maior valor do array: [%d]", arr[size-1]);
    return 0;
}

