/* Estrutura de Dados II
    Matheus Sousa Marinho
    Shell Sort
*/

#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int tam){
    int i, j, chave;
    // Utilizando a sequência de Knuth:
    int h = 1;
    while (h < tam){
        h = 3*h + 1;
    }
    while (h > 1){ /* Implementação do Insertion com h-ordenação */
        h = h/3; /* Decremento do h */
        for (i = h; i < tam; i++){ /* Inicialização do i (>) */
            chave = arr[i];
            j = i - h; /* Inicializa o j (<) */
            while (j >= 0 && chave < arr[j]){
                arr[j + h] = arr[j];
                j = j - h;
            }
            arr[j + h] = chave;
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
    shellSort(arr, size); 
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Menor valor do array: [%d]", arr[0]);
    printf("\n");
    printf("Maior valor do array: [%d]", arr[size-1]);
    printf("\n");

    return 0;
}