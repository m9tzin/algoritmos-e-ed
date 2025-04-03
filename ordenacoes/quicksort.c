/* Estrutura de Dados II
    Matheus Marinho   
    Quick Sort
*/

#include <stdio.h>
#include <stdlib.h>

// Quick Sort por partes funcional

/* Partição do vetor para a ordenação */

void particaoVetor(int esq, int dir, int *i, int *j, int arr[]){
    /* Particionando o vetor de entrada */
    *i = esq;
    *j = dir;
    int aux;
    int x = arr[(*i + *j)/2];  /* Escolha de um pivô baseado na média dos valores */

    do{
        while(arr[*i] < x) (*i)++;  /* Buscamos um elemento maior que o pivô (>) */
        while(arr[*j] > x) (*j)--;  /* Buscamos um elemento menor que o pivô (<) */

        if (*i <= *j) { /* Troca dos elementos */
            aux = arr[*i];
            arr[*i] = arr[*j];
            arr[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

/* Processo de ordenação do quickSort */
void ordenaVetor(int esq, int dir, int arr[]){
    /* Particione o vetor */
    int i, j;
    particaoVetor(esq, dir, &i, &j, arr);
   
    /* Já tendo o vetor particionado, organiza-se o vetor por recursão */ 
   
    if(esq < j){
        ordenaVetor(esq, j, arr);
    }
    if(i < dir){
        ordenaVetor(i, dir, arr);
    }
}

void quickSort(int arr[], int tam){
    ordenaVetor(0, tam-1, arr);
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
    printf("\n");
    
    // Chamando a função para ordenar o array
    quickSort(arr, size); 
    
    printf("Vetor ordenado: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");
    printf("Menor valor do array: [%d]", arr[0]);
    printf("\n");
    printf("Maior valor do array: [%d]", arr[size-1]);
    printf("\n");

    return 0;
}