/* Estrutura de Dados I
Matheus Marinho */

/* José, que começou a ir à escola, está tendo problemas com os números. Para ajudá-lo a "pegar
o jeito", a professora de José escreve dois números de três dígitos e pede para ele comparar esses
números. Entretanto, ao invés de interpretá-los com o dígito mais significativo à esquerda, ele deve
interpretá-los com o dígito mais significativo à direita. Ele tem que dizer à professora qual o maior
dos dois números.
Escreva um programa em C que seja capaz de verificar as respostas de José.
 */

#include <stdio.h>

int encontrarMaiorNumero (int numero1, int numero2){
    int maiorNumero;
    int uni1, uni2, dez1, dez2, cen1, cen2;
    /* unidades = numero % 10;           
    dezenas = (numero / 10) % 10;      
    centenas = (numero / 100) % 10; */
    uni1 = numero1 % 10;
    uni2 = numero2 % 10;

    dez1 = (numero1 / 10) % 10;
    dez2 = (numero2 / 10) % 10;

    cen1 = (numero1 / 100) % 10;
    cen2 = (numero2 / 100) % 10;

    if (uni1 >= uni2){
        maiorNumero = (uni1*100 + dez1*10 + cen1*1);
    }else if(uni1 == uni2){
        if(dez1 > dez2){
            maiorNumero = (uni1*100 + dez1*10 + cen1*1);
        }else if(dez1 == dez2){
            if(cen1 > cen2){
                maiorNumero = (uni1*100 + dez1*10 + cen1*1);
            }
        }
    }
    if (uni2 >= uni1){
        maiorNumero = (uni2*100 + dez2*10 + cen2*1);
    }else if(uni2 == uni1){
        if(dez2 > dez1){
            maiorNumero = (uni2*100 + dez2*10 + cen2*1);
        }else if(dez2 == dez1){
            if(cen2 > cen1){
                maiorNumero = (uni2*100 + dez2*10 + cen2*1);
            }
        }
    }
        
    return maiorNumero;
}

int main(){
    int numero1, numero2, maiorNumero;

    printf("Insira os dois numeros: ");
    scanf("%d %d", &numero1, &numero2);

    maiorNumero = encontrarMaiorNumero(numero1, numero2);

    printf("O maior numero de Jose seria [%d].", maiorNumero);
    return 0;
}