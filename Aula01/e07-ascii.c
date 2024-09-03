// Estrutura de Dados I
// 03/09/2024
// Matheus Marinho

#include <stdio.h>

int main(){
    char letter;
    
    printf("Exibindo o codigo ASCII correspondente aos caracteres W, A, S, D:\n");
    
    printf("Qual caractere voce deseja exibir primeiro?\n");
    scanf("%c", &letter);
    /* letter = getchar(); */

    switch(letter){
        case 'W':
        printf("Codigo ASCII de W: 0101 0111.\n");
        break;

        case 'A':
        printf("Codigo ASCII de W: 0100 0001.\n");
        break;

        case 'S':
        printf("Codigo ASCII de W: 0101 0011.\n");
        break;

        case 'D':
        printf("Codigo ASCII de W: 0100 0100.\n");
        break;
    }
    
    return 0;
}