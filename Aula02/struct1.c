/* Estrutura de Dados I
Matheus Sousa Marinho */

/* Usando typedef.c  como base, crie um vetor para salvar dados de uma turma de 40 alunos. */

#include <stdio.h>
#define limit 40

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
    Aluno aluno[limit];
    nota media[limit];
    int i=0;

    while(i<limit){
        printf("Informe o numero de matricula: ");
        scanf("%d", &aluno[i].matricula);
        printf("Informe a nota da primeira prova: ");
        scanf("%f", &aluno[i].prova1);
        printf("Informe a nota da segunda prova: ");
        scanf("%f", &aluno[i].prova2);

        media[i] = (aluno[i].prova1  + aluno[i].prova2) / 2;

        i++;
    }
    
    for(int k=0; k<limit; k++){
        printf("\nMatricula.....: %d\n", aluno[k].matricula);
        printf("Media do aluno [%d]: %.1f\n", k, media[k]);
    }
   
    getchar();

    return(0);
}