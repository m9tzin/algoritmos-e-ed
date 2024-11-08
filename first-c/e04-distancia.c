// Estrutura de Dados 1
// 31/08/2024
// Matheus Marinho

/* Escreva um programa que dadas duas coordenadas (x1, y1) e (x2, y2) de pontos
em R2, calcule sua distância. */

#include <stdio.h>
#include <math.h>

int main(){
    int x1, y1, x2, y2;
    float dist;
    printf("Calculando a distância entre dois pontos.\n");
    
    printf("Insira o valor da primeira coordenada (x1,y1):");
    scanf("%d %d", &x1, &y1);
    
    printf("Insira o valor da segunda coordenada (x2,y2):");
    scanf("%d %d", &x2, &y2);

    dist = (float)sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
    
    printf("A distancia entre os dois pontos e de: %.1f", dist);
    
    return 0;
}