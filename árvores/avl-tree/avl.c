/*
    Estrutura de Dados II
    AVL Tree 
    for example:   
                   [0]
                 /    \
                [1]     [0]
                   \ 
                    [0]

                */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    int altura;
    struct Node *direita;
    struct Node *esquerda;
}Node;

// Criar o Node:
Node* createNode(int value){
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Falha ao alocar a memória.");
    }
    
    // Parâmetros 
        node->value = value;
        node->altura = 1;
        node->direita = NULL;
        node->esquerda = NULL;
    
    return node;
}

int pegarAltura(Node* node){
    if  (node == NULL)  {
        return 0;
    }
    
    return node->altura;
}

int fatorBalanceamento(Node* node){
    if (node == NULL)   {
        return 0;
    }
        int alturaEsq = pegarAltura(node->esquerda);
        int alturaDir = pegarAltura(node->direita);
    
    return alturaDir - alturaEsq;
}

void updateAltura(Node* node){
    if (node != NULL){
        int alturaEsq = pegarAltura(node->esquerda);
        int alturaDir = pegarAltura(node->direita);
        node->altura = 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
        
    }
}

/* NULL @@@@@@@@ will be @@@@@@@ Node: 
                                         [value]
                                        /       \                   
                                       esq      dir
                                        
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                           
*/

/*BST - menores à esquerda, maiores à direita*/

Node* insert(Node* node, int value){
    if (node == NULL){
        return createNode(value);
    }
    if (value < node->value) {
        node->esquerda = insert(node->esquerda, value);
    } else if (value > node->value) {
        node->direita = insert(node->direita, value);
    } else {
    // value == node->value
        return node;
    }
    return node;
}


int main(){
    return 0;
}