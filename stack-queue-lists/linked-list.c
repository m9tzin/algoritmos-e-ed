/* Estrutura de Dados I
 * 
 * Matheus Marinho
 *
 * Linked Lists - Listas simplesmente encadeada.
 *
 * [1]->[2]->[3]->...->[k]->NULL
 *
 * */

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
};

typedef struct Node Node;

struct List{
	struct Node *inicio;
	struct Node *fim;
};

typedef struct List List;

Node *aux;
Node *anterior;

List* criarLista(){
	List *lista = (List*)malloc(sizeof(List));
	if(lista != NULL){
		lista->fim = NULL;
		lista->inicio = NULL;
	}
	return lista;
}

void inserirInicio(List *lista){
	Node *novo = (Node*)malloc(sizeof(Node));
	printf("Insira o elemento que deseja inserir: ");
	scanf("%d", &novo->num);
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
		novo->prox = NULL;
		lista->fim = novo;
	}else{
		novo->prox = lista->inicio;
		lista->inicio = novo;
	}

}

void exibirLista(List *l){
	if(l->inicio == NULL){
		printf("Lista vazia.");
	}else{
		aux = l->inicio;
		do{
			printf("[%d] ", aux->num);
			aux = aux->prox;
		}while(aux != NULL);
	}
}


int main(void){
	List *l = criarLista();

	for(int k=0; k<5; k++){
	inserirInicio(l);
	};

	exibirLista(l);

	return 0;
}
