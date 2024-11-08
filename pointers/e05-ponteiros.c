/* Estrutura de Dados I
Matheus Marinho */

/* Elaborar um programa que leia dois valores inteiros (A e B).
Em seguida faça uma função que retorne a soma do dobro dos dois números lidos.
A função deverá armazenar o dobro de A na própria variável A e o dobro de B na própria variável B
 */

#include <stdio.h>
#include <stdlib.h>

int somaDobro(int *numero1, int *numero2){
    *numero1 = *numero1 * 2;
    *numero2 = *numero2 * 2;
    return *numero1 + *numero2;
}

int main(void){
    int a, b;
    int *ptr_a, *ptr_b;

    printf("Insira um valor para A:\n");
    scanf("%d", &a);
    printf("Insira um valor para B:\n");
    scanf("%d", &b);

    ptr_a = &a;
    ptr_b = &b;

    somaDobro(ptr_a, ptr_b);
    printf("A soma do dobro dos numeros lidos e: %d", somaDobro(ptr_a, ptr_b));
    
    return 0;
}