// Estrutura de Dados I
//
// Matheus Marinho
//
// Pilhas - First in, Last Out.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
	int num;
	struct Elemento *prox;
}Elemento;


typedef struct Pilha{
	struct Elemento *topo;
}Pilha;
	

// Pointer auxiliar
	Elemento *aux;

Pilha* criarPilha(){
	Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
	if(pilha != NULL){
		pilha->topo = NULL;
	}
	return pilha;
}

void inserirElemento(Pilha *p){
	Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
	printf("Insira o novo elemento: ");
	scanf("%d", &novo->num);
	
	novo->prox = p->topo;
	p->topo = novo;

}

void retirarElemento(Pilha *p){
	if(p->topo == NULL){
		printf("Empty stack.");
	}else{
		aux = p->topo;
		printf("[%d] foi removido!\n", p->topo->num);
		p->topo = p->topo->prox;
		
		free(aux);
	}
}

void consultarPilha(Pilha *p){
	if(p->topo == NULL){
		printf("Empty stack.");
	}else{
		Elemento *aux = p->topo; // pointer para o topo
		do{
			printf("[%d]\n", aux->num);
			aux = aux->prox;
		}while(aux != NULL);
	}
	
}

int main(void){
	Pilha *stack = criarPilha();

	for(int i=0; i<5; i++){
	inserirElemento(stack);
	}
	printf("\n\n");	
	consultarPilha(stack);
	printf("\n\n");
	retirarElemento(stack);
	printf("\n\n");
	consultarPilha(stack);

	return 0;
}
