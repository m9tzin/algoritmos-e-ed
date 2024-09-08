/* Estrutura de Dados I
Matheus Marinho */

/* Escreva um programa C que, dado o ano atual, determine qual
é o próximo ano em que o cometa Halley será visível novamente.
Se o ano atual é um ano de passagem do cometa, considere que o
cometa já passou nesse ano, ou seja, considere sempre o próximo
ano de passagem após o atual. */

#include <stdio.h>

int proximoHalley (int anoAtual){
    int anoRef = 1986, ciclo = 76, proximoAno;
    
    if(anoAtual >= anoRef){
        proximoAno = anoRef;
        while(proximoAno <= anoAtual){
            proximoAno += ciclo;
        }
    }else{
        proximoAno = anoRef;
        while(proximoAno > anoAtual){
            proximoAno -= ciclo;
        }
        proximoAno += ciclo;
    }
    return proximoAno;
}

int main(){
    int anoAtual, proximoAnoHalley;

    printf("Insira o ano atual: ");
    scanf("%d", &anoAtual);

    proximoAnoHalley = proximoHalley(anoAtual); 

    printf("O proximo ano em que o Halley sera visto: [%d]", proximoAnoHalley);

    return 0;
}

