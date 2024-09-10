/* Estrutura de Dados I
Matheus Marinho */

/* Recentemente, a BioSymbol (BS), startup criada por alunos do INF/UFG, inventou um computador de base 4 (tetrade), inspirado nas quatro bases nitrogenadas da Biologia (Adenina, Citosina, Guanina, Timina). A BS contratou você para desenvolver um programa em C que receba números inteiros positivos na base decimal e os converta para a base 4 utilizando divisões sucessivas.

Considerações
Utilize os símbolos A, C, G e T na base 4 para representar os dígitos 0, 1, 2 e 3, respectivamente.

Entrada
Um número inteiro representando a quantidade de números, 1 ≤ n ≤ 100, que serão convertidos.
Em seguida, n números inteiros não negativos.
Saída
Os valores correspondentes na base 4 para cada número digitado. */

/* Representação A=0, C=1, G=2, T=3 */

#include <stdio.h>

void convertNumbers(int limit) {
    int array[limit];
    char base4Mapping[] = {'A', 'C', 'G', 'T'}; /* Mapping do vetor de base4 */

    /* Armazenando os números */
    for (int i = 0; i < limit; i++) {
        printf("Insira um numero:\n");
        scanf("%d", &array[i]);
    }

    /* Convertendo cada número do array para base 4 */
    for (int k = 0; k < limit; k++) {
        int base4[100];  
        int i = 0;
        int num = array[k];

        /* Caso 0: */
        if (num == 0) {
            printf("%d na base 4: A\n", array[k]);
            continue;
        }

        /* Converte o número atual para base 4 */
        while (num > 0) {
            base4[i] = num % 4; 
            num = num / 4;       
            i++;
        }

        /* Printing na ordem inversa */
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", base4Mapping[base4[j]]); /* char */
        }
        printf(" ");
    }
}

int main(void) {
    int limit;
    printf("Quantos numeros serao convertidos? \n");
    scanf("%d", &limit);

    convertNumbers(limit);

    return 0;
}
