// Estrutura de Dados em C
// 30/08/2024
// Matheus Marinho

/* Leia o valor do raio de um círculo e calcule e imprima a área dele.
 */

#include <stdio.h> 
#include <math.h>
int main(){
    int r;
    float area;

    printf("Insira o valor do raio:");
    scanf("%d", &r);
    area = (float)(M_PI * pow(r,2)); 

    printf("Area = %.1f", area);

    return 0;
}