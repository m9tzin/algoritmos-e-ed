/* Estrutura de Dados I
Matheus Marinho */

/* Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real e char.

Associe as variáveis aos ponteiros (use &).

Modifique os valores de cada variável usando os ponteiros.

Imprima os valores das variáveis antes e após a modificação. */


#include <stdio.h>
#include <stdlib.h>

int main(void){
    /* vars */
    int inteiro;
    float real;
    char character;

    /* pointers */
    int *ptr_inteiro;
    float *ptr_real;
    char *ptr_character;

    inteiro = 10;
    ptr_inteiro = &inteiro;
    printf("Memory address: %p\n", ptr_inteiro);
    printf("Content: %d", *ptr_inteiro);
    printf("\n");

    real = 12.21 ;
    ptr_real = &real;
    printf("Memory address: %p\n", ptr_real);
    printf("Content: %.2f", *ptr_real);
    printf("\n");

    character = 'A' ;
    ptr_character = &character;
    printf("Memory address: %p\n", ptr_character);
    printf("Content: %c", *ptr_character);
    printf("\n");

    /* Modify */
    *ptr_inteiro = 7;
    *ptr_real = 13.37;
    *ptr_character = 'X';
    printf("\n");

    printf("Memory address: %p\n", ptr_inteiro);
    printf("Content: %d", *ptr_inteiro);
    printf("\n");

    printf("Memory address: %p\n", ptr_real);
    printf("Content: %.2f", *ptr_real);
    printf("\n");

    printf("Memory address: %p\n", ptr_character);
    printf("Content: %c", *ptr_character);
    printf("\n");


    return 0;
}