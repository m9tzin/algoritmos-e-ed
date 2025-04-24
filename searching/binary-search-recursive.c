/* Estrutura de Dados II
Matheus Marinho
Binary Search recursive */

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int target, int size, int left, int right) {
    int mid;    
        mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;  
        } else if (arr[mid] > target) {
            binarySearch(arr, target, size, left, mid - 1); 
        } else {
            binarySearch(arr, target, size, mid + 1, right);  
        }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Vetor original: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    /* Binary Search */
    printf("Index do elemento procurado: [%d]", binarySearch(arr, 8, size, 0, size-1));
    printf("\n");
    return 0;
}