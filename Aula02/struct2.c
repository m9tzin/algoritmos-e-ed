/* Estrutura de Dados I
Matheus Sousa Marinho */

/* Usando typedef.c  como base, adicione um registro novo na estrutura tAluno que salve seus dados cadastrais de CPF e contato telefónico.
 */

#include <stdio.h>

// Redefinindo os tipos float e int
typedef float nota; /* Fica claro que a nota passa a ser do tipo float */
typedef int   inteiro; /* inteiro = int */

struct Aluno {
    inteiro matricula, cpf, telefone;
    nota prova1;
    nota prova2;
};

// Redefinindo uma struct (encurta o comando na declaracao)
typedef struct Aluno Aluno;

int main(void) {
    Aluno aluno;
    nota media = 0;

    printf("Informe o numero de matricula: ");
    scanf("%d", &aluno.matricula);
    printf("Informe o numero de CPF: ");
    scanf("%d", &aluno.cpf);
    printf("Informe o numero de telefone: ");
    scanf("%d", &aluno.telefone);
    printf("Informe a nota da primeira prova: ");
    scanf("%f", &aluno.prova1);
    printf("Informe a nota da segunda prova: ");
    scanf("%f", &aluno.prova2);

    media = (aluno.prova1  + aluno.prova2) / 2;

    printf("\nMatricula.....: %d\n", aluno.matricula);
    printf("\nTelefone......: %d\n", aluno.cpf);
    printf("\nMedia do aluno: %.1f\n", media);

    getchar();

    return(0);
}