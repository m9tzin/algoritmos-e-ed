/* Linear Search 
    Matheus Marinho
        */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int index;
    int value;
}Elemento;

int linearSearch(Elemento arr[], int size, int target){
    if(arr == NULL || size == 0){
        return -1;
    }
    for(int i = 0; i <= size-1; i++){
        if(arr[i].value == target){
            return arr[i].index;
        }
    }
    return -1;
}

int main(int argc, char* argv[]){
    Elemento elementos[] = {
        {0, 10}, {1, 2}, {2, 3}, {3, 7}, {4, 23},
        {5, 1}, {6, 9}, {7, 12}, {8, 11}, {9, 4}
    };

    if (argc != 2) {
        printf("Incorrect value to target. Please, insert again.\n");
        return 1;
    }
    /* Values */
    int size = sizeof(elementos) / sizeof(elementos[0]);
    int target = atoi(argv[1]);
    int idx = linearSearch(elementos, size, target);
    
    /* ./linearsearch <target> */

    if(idx == -1){
        printf("Value not found.\n");
    }
    else{
        printf("Value found. Index: [%d]\n", idx);
    }
    return 0;
}