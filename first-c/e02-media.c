// Estrutura de Dados em C
// 30/08/2024
// Matheus Marinho

/* Faça um programa que calcule a média, padrão UFG, de 3 números inteiros, sendo
que um desses números é 20 e os demais deverão ser digitados durante a
execução. */

#include <stdio.h> 
int main(){
    int p1=20, p2, p3;
    float media;

    printf("Insira a segunda nota:");
    scanf("%d", &p2);

    printf("Insira a terceira nota:");
    scanf("%d", &p3);

    media = (float)(p1+p2+p3)/3; // Casting para exibir media com um ponto flutuante.

    printf("Media = %.1f", media);

    return 0;
}