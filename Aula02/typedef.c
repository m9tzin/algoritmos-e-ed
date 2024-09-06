/* Estrutura de Dados I
Matheus Sousa Marinho */

/* Complete o código typedef.c . Depois, clone os dados para um outro aluno que teve a mesma média mas com matrícula diferente. */

#include <stdio.h>

// Redefinindo os tipos float e int
typedef float nota; /* Fica claro que a nota passa a ser do tipo float */
typedef int   inteiro; /* inteiro = int */

struct Aluno {
    inteiro matricula;
    nota prova1;
    nota prova2;
};

// Redefinindo uma struct (encurta o comando na declaracao)
typedef struct Aluno Aluno;

int main(void) {
    Aluno aluno1, aluno2;
    nota media = 0;

    printf("Informe o numero de matricula: ");
    scanf("%d", &aluno1.matricula);
    printf("Informe a nota da primeira prova: ");
    scanf("%f", &aluno1.prova1);
    printf("Informe a nota da segunda prova: ");
    scanf("%f", &aluno1.prova2);

    media = (aluno1.prova1  + aluno1.prova2) / 2;

    printf("Informe o numero de matricula: ");
    scanf("%d", &aluno2.matricula);

    aluno2.prova1 = aluno1.prova1;
    aluno2.prova2 = aluno1.prova2;

    printf("\nMatricula.....: %d\n", aluno1.matricula);
    printf("Media do aluno: %.1f\n", media);

    printf("\nMatricula.....: %d\n", aluno2.matricula);
    printf("Media do aluno: %.1f\n", media);

    getchar();

    return(0);
}