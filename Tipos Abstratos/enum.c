/* Estrutura de Dados I
Matheus Sousa Marinho */

/* Escreva uma demo para testar o código enum.c */

#include <stdio.h>

enum Status { LOW = 5, MEDIUM = 50, HIGH = 100 };
enum Semana { Seg = 1, Ter = 2, Qua = 3, Qui = 4, Sex = 5, Sab = 6, Dom = 7};

int main() {
    enum Status resultado = HIGH;
    enum Semana dia = Sex;
    
    /* Utilizando o switch case... */

    switch (dia) {
        case 1:
        printf("monday.\n");
        break;

        case 2:
        printf("tuesday.\n");
        break;

        case 3:
        printf("wednesday.\n");
        break;

        case 4:
        printf("thursday.\n");
        break;

        case 5:
        printf("friday.\n");
        break;

        case 6:
        printf("saturday.\n");
        break;

        case 7:
        printf("sunday.\n");
        break;

        default:
        printf("looking forward to the weekend, try again :)");
    }

    switch (resultado){
        case LOW:
        printf("help! energy status: [%d]", resultado);
        break;

        case MEDIUM:
        printf("Be careful, charge your phone! energy status: [%d]", resultado);
        break;

        case HIGH:
        printf(":) energy status: [%d]", resultado);
        break;

        default:
        printf("Default message to your battery.");    
    }

    return 0;
}
