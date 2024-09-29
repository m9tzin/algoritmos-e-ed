/* Estrutura de Dados I
Matheus Marinho */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int value1, value2;
    int *p_value1, *p_value2;

    printf("Insira um valor para value 1:\n");
    scanf("%d", &value1);

    printf("Insira um valor para value 2:\n");
    scanf("%d", &value2);

    p_value1 = &value1;
    p_value2 =  &value2;
    
    if(p_value1 > p_value2){
        printf("O maior endereco e o de value1: [%p]", p_value1);
    }else{
        printf("O maior endereco e o de value1: [%p]", p_value2);
    }
    
    printf("\n");
    printf("Address 1: [%p]\n", p_value1);
    printf("Address 2: [%p]\n", p_value2);


    return 0;
}