/*
    Estrutura de Dados II
    AVL Tree 
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
    Node* node =(Node*)malloc(sizeof(Node));
    if(node == NULL){
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
    if(node == NULL){
        return 0;
    }
    return node->altura;
}

int fatorBalanceamento(Node* node){
    if (node == NULL){
        return 0;
    }
    int alturaEsq = pegarAltura(node->esquerda);
    int alturaDir = pegarAltura(node->direita);
    return alturaDir - alturaEsq;
}



int main(){
    return 0;
}