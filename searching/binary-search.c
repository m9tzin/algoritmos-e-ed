// Estrutura de Dados II
// Matheus Marinho
// Bubble Sort

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int target, int size) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;  
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1;  
        }
    }
    return -1;  
}

void bubbleSort(int arr[], int tam){
    int aux;
    for(int i = 0; i < tam - 1 ; i++){
        for(int j = 0; j < tam - i - 1; j++)
            if(arr[j] > arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
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

    /* Binary Search */
    printf("Index do elemento procurado: [%d]", binarySearch(arr, 10, size));
    printf("\n");
    return 0;
}