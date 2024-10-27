/* Estrutura de Dados I
Matheus Sousa Marinho */

/* Mostre o tamanho para cada tipo de dado primário em primary.c */

#include <stdio.h>

int main(){
    unsigned char uc;
    signed char sc; 
    double d;
    long double ld;
    unsigned int ui;
    signed int si;
    short s;
    long l;
    long long ll;
    void v(void);

    /* Tamanho do tipo de dado
       %lu: usado para valores 'unsigned long'
       %zu: usado para valores 'size_t' (unsigned long)
    */ 

    printf("Tamanho do uchar    : %zu bytes\n", sizeof(uc));
    printf("Tamanho do schar    : %zu bytes\n", sizeof(sc));
    printf("Tamanho do double   : %zu bytes\n", sizeof(d));
    printf("Tamanho do ldouble  : %zu bytes\n", sizeof(ld));
    printf("Tamanho do uint     : %zu bytes\n", sizeof(ui));
    printf("Tamanho do sint     : %zu bytes\n", sizeof(si));
    printf("Tamanho do short    : %zu bytes\n", sizeof(s));
    printf("Tamanho do long     : %zu bytes\n", sizeof(l));
    printf("Tamanho do long long: %zu bytes\n", sizeof(ll));
    printf("Tamanho do void     : %zu bytes\n", sizeof(v()));
    printf("Tamanho do size_t   : %zu bytes\n", sizeof(size_t));

    return 0;
}