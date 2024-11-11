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

typedef struct Node{
	int num;
	struct Node *prox;
}Node;

typedef struct List{
	struct Node *inicio;
	struct Node *fim;
}List;

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
	printf("Insira o elemento que deseja inserir no inicio: ");
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

void inserirFinal(List *l){
	Node* novo = (Node*)malloc(sizeof(Node));
	printf("Insira o valor a ser inserido no fim: ");
	scanf("%d", &novo->num);

	if(l->inicio == NULL){
		l->inicio = novo;
		l->fim = novo;
		l->inicio->prox == NULL;
	}else{
		l->fim->prox = novo;
		l->fim = novo;
		l->fim->prox = NULL;
	}
}	

void removerElemento(List *l){
	int numero;
	int achou;
	if(l->inicio == NULL){
		printf("\nFila esta vazia.");
	}else{
		printf("Insira o numero a ser inserido: ");
		scanf("%d", &numero);
	
		aux = l->inicio;
		anterior = NULL;
		achou = 0;
		
	}
}




int main(void){
	List *l = criarLista();

	for(int k=0; k<5; k++){
	inserirInicio(l);
	};
	
	inserirFinal(l);
	exibirLista(l);

	return 0;
}

