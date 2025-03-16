// Estrutura de Dados II
// Matheus Marinho
// Bubble Sort

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int tam){
    int aux;
    for(int i = 0; i < tam - 1 ; i++){
        for(int j = 1; j < tam - i; j++)
            if(arr[j-1] > arr[j]){
                aux = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = aux;
            }
    }
}
// Array original:  [50, 16, 23, 5, 7, 12, 10]

int main(){
    int arr[] = {50, 16, 23, 5, 7, 12, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Vetor original: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Chamando a função para ordenar o array
   bubbleSort(arr, size); 
    
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