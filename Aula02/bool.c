/* Estrutura de Dados I
Matheus Sousa Marinho */

/* Estude bool.c  e explique como funciona o tipo de dado booleano e quais seriam possíveis utilidades num código. */
/* O dado boolean sempre retorna valores verdadeiros ou falsos, uma possivel utilidade seria em condicionais
fazendo com que realize determinada tarefa caso algo seja verdadeiro e outra caso seja falso. */

#include <stdio.h>
#include <stdbool.h>

int main() {
    bool emCrash = true; // Tipo logico (boolean)

    if(!emCrash)
        printf("Sistema OK!\n");
    else
        printf("Sistema em CRASH.\n");

    return (0);
}