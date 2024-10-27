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

#define M_LIN 3
#define M_COL 3

int main(){
 float temp, ppt, wind;
 int matriz[M_LIN][M_COL];
 srand(time(NULL));

    for(int j=0; j < M_COL; j++){
        int max = 33;
        int min = 12;
        temp = (float) rand() / (float) RAND_MAX;
        temp *= (max-min);
        temp += min;
        matriz[0][j] = temp;
    }

    /* Ppt values */
    for(int j=0; j < M_COL; j++){
        int max = 3;
        int min = 0;
        ppt = (float) rand() / (float) RAND_MAX;
        ppt *= (float) (max-min);
        ppt += (float) min;
        matriz[1][j] = ppt;
    }

    /* Wind values */
    for(int j=0; j < M_COL; j++){
        int max = 33;
        int min = 13;
        wind = (float) rand() / (float) RAND_MAX;
        wind *= (float) (max-min);
        wind += (float) min;
        matriz[2][j] = wind;
    }

    /* Printing the matrix */
     for(int i=0; i<M_LIN; i++){
        for(int j=0; j<M_COL; j++){
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}