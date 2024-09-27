/* Estrutura de Dados I
Matheus Marinho */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define VMAX 100
# define VMIN 1

void somaVetor(int *p, int *q, int tamanho) {
    for(int i=0; i<tamanho; i++){
        *(p+i) += *(q+i);
    }
}

void mostraVetor(int *p, int tamanho) {
    for(int i=0; i<tamanho; i++){
        printf(" [%03d] ", p[i]);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int N; // tamanho do vetor \
              (inferir a partir dos dados de entrada)

    N = argc - 1; // except the program name
    int v1[N]; // dado
    int v2[N]; // aleatorio

    // Vetor dado
    for(int i=0; i<N; i++){
        v1[i] = atoi(argv[i+1]);
    }

    // Vetor aleatorio
    for(int i=0; i<N; i++){
        v2[i] = rand() % (VMAX-VMIN+1) + VMIN;
    }

    printf("Vetor 1: ");
    mostraVetor(v1, N);
    printf("\n");
    
    printf("Vetor 2: ");
    mostraVetor(v2, N);
    printf("\n");
    
    somaVetor(v1, v2, N);
    
    printf("Soma   : ");
    mostraVetor(v1, N);
    printf("\n");

    return 0;
}