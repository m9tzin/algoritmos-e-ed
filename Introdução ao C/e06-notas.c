// Estrutura de Dados em C
// 31/08/2024
// Matheus Marinho

/* Fazer um programa que calcule a média de 3 notas. Caso a média seja igual ou
superior a 6, o aluno estará aprovado, caso contrário, estará reprovado. */

#include <stdio.h> 
int main(){
    float p1, p2, p3, media;

    printf("Insira a primeira nota:");
    scanf("%f", &p1);

    printf("Insira a segunda nota:");
    scanf("%f", &p2);

    printf("Insira a terceira nota:");
    scanf("%f", &p3);

    media = (p1+p2+p3)/3; 

    if(media >= 6){
        printf("O aluno esta aprovado.\n");
    }else{
        printf("O aluno foi reprovado :(\n");
    }

    printf("Media = %.1f", media);

    return 0;
}