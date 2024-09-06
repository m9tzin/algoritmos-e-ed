#include <stdio.h>
/* Estrutura de Dados I
Matheus Sousa Marinho */

/* Estude union.c  e explique como funciona uma união e qual a diferença dela comparada com uma estrutura struct. */

// Uma unica variavel que representa multipos tipos de dados
union Data {
    int   intN;
    float floatF;
} data; 

int main() {
    union Data data;

    data.intN = 5;
    data.floatF = 3.4;

    printf("%d\n", data.intN);
    printf("%f\n", data.floatF);

    return(0);
}