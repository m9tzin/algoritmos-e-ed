/* Estrutura de Dados I
 * 
 * Matheus Marinho
 *
 * Fila - Queue (first in, first out)
 * [] -> [] -> ... 
 *
 */

#include <stdio.h>
#include <stdlib.h>
	
typedef struct Elemento{
	int num;
	struct Elemento *prox;
}Elemento;

typedef struct Fila{
	struct Elemento *inicio;
	struct Elemento *fim;
}Fila;

Elemento *aux;

/* Criando a fila */

Fila* criarFila(){
	/* malloc */
	Fila *fila = (Fila*)malloc(sizeof(Fila));
	if(fila != NULL){
		fila->inicio = NULL;
		fila->fim = NULL;
	}
	return fila;
}

void inserirElemento(Fila *f){
	Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
	printf("Digite o numero a ser inserido na fila: ");
	scanf("%d", &novo->num);
	
	novo->prox = NULL; /* pointer apontará para o null */

	if(f->inicio == NULL){
		f->inicio = novo;
		f->fim = novo;
	}else{ 
		f->fim->prox = novo;
		f->fim = novo;
	}
}

void exibirFila(Fila *f){
	if(f->inicio == NULL){
		printf("\nFila vazia.");
	}else{
		aux = f->inicio;
		do{
			printf("[%d] ", aux->num);
			aux = aux->prox; // aux percorrerá toda a fila
		}while(aux != NULL);
	}
}

void removerElemento(Fila *f){
	if(f->inicio == NULL){
		printf("\nFila vazia.");
	}else{
		aux = f->inicio;
		printf("[%d] foi removido!\n", f->inicio->num);
		f->inicio = f->inicio->prox;
		free(aux);
	}
}


int main(void){
	Fila *f = criarFila();
	for(int i=0; i<5; i++){
		inserirElemento(f);
	}

	removerElemento(f);
	removerElemento(f);

	exibirFila(f);
	
	return 0;
}
