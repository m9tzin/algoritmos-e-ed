// Estrutura de Dados I
//
// Matheus Marinho
//
// Pilhas - First in, Last Out.
//

#include <stdio.h>
#include <stdlib.h>

	struct Elemento{
		int num;
		struct Elemento *prox;
	};

typedef	struct Elemento Elemento;

	struct Pilha{
		struct Elemento *topo;
	};
	
typedef struct Pilha Pilha;

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

void consultarPilha(Pilha *p){
	if(p->topo == NULL){
		printf("EMpty");
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

	for(int i=0; i<10; i++){
	inserirElemento(stack);
	}
	
	consultarPilha(stack);
	
	
	return 0;
}
