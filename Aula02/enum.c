/* Estrutura de Dados I
Matheus Sousa Marinho */

/* Escreva uma demo para testar o código enum.c */

#include <stdio.h>

enum Status { LOW, MEDIUM, HIGH };
enum Semana { Seg = 1, Ter = 2, Qua = 3, Qui = 4, Sex = 5, Sab = 6, Dom = 7};

int main() {
    enum Status resultado = MEDIUM;
    enum Semana dia = Ter;
    
    return 0;
}
