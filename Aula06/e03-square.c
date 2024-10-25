/* Estrutura de Dados I
Matheus Marinho */

/* Escreva um programa que calcule o quadrado dos N primeiros números (a partir de 1)
Exemplo:
Número de elementos: 9
1 4 9 16 25 36 49 64 81 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char* argv[]){
    int *p, length;
    
    length = atoi(argv[1]); /* Quantidade de Elementos */

    if(argc == 2 ){
        
        p = (int*)malloc(length * sizeof(int));
        
        if (p == NULL){
            printf("Erro de alocacao.");
            return -1;
        }
        
        /* p[] = {1,2,..., length}  -> p[]={1,4,9, ..., length^2} */
        for(int i=1; i<=length; i++){
            p[i-1] = i*i;
        }

        for(int i=0; i<length; i++){
            printf("%d ", p[i]);
        }
    
    free(p);

    }else{
        printf("Sem parametro.");
    }
    
    return 0;
}