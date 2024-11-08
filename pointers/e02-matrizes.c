/* Estrutura de Dados I
Matheus Marinho */

/******************************************************************************

Dada uma quantidade de amostras N, passada como parâmetro,  armazene em uma mesma variável e em simultâneo dados simulados do clima de Goiânia:
Temperatura ∈ [12, 38] °C
Precipitação ∈ [0, 3] mm
Vento ∈ [13, 33] km/h
Dica:
    float sensor[DIM1][DIM2];
    // DIM1: Índice do tipo de sensor
    // DIM2: Tamanho dos dados

*******************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    float matriz[100][100];
    int M_LIN = 3;
    int M_COL = atoi(argv[1]);
    int limit = M_COL;
    srand(time(NULL));

    /* Temp values */
    for(int j=0; j < limit; j++){
        int max = 33;
        int min = 12;
        matriz[0][j] = (float)rand() / RAND_MAX * (max - min) + min;
    }

    /* Ppt values */
    for(int j=0; j < limit; j++){
        int max = 3;
        int min = 0;
        matriz[1][j] = (float)rand() / RAND_MAX * (max - min) + min;
    }

    /* Wind values */
    for(int j=0; j < limit; j++){
        int max = 33;
        int min = 13;
        matriz[2][j] = (float)rand() / RAND_MAX * (max - min) + min;
    }

    
    /* Printing the matrix */
    printf("Temperatura(C) | Ppt(mm) | Vento(km/h)\n");
    printf("-------------------------------------\n");
    for (int j = 0; j < M_COL; j++) {
        printf("%10.3f | %5.3f | %13.3f\n", matriz[0][j], matriz[1][j], matriz[2][j]);
    }

    return 0;
}