/* Estrutura de Dados II
Matheus Marinho
Selection Sort */

#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int arr[], int tamanho){
    int menor, aux;
        for(int i = 0; i < tamanho-1; i++){
            menor = i;
            for(int j = i+1; j < tamanho; j++){
                if(arr[j] < arr[menor]){
                    menor = j;
                }
            }
            if( i != menor){
                aux = arr[i];
                arr[i] = arr[menor];
                arr[menor] = aux;
            }
        }
}

int main(){
    // Declarando um array arbitrário
    // Input arr = [50, 16, 23, 5, 7, 12, 10]
    int arr[] = {50, 16, 23, 5, 7, 12, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Vetor original: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Chamando a função para ordenar o array
    SelectionSort(arr, size); 
    
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