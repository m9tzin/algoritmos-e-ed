/*
    Estrutura de Dados II - Matheus Sousa Marinho
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
        return NULL;
    }
    
    // Parâmetros 
    node->value = value;
    node->altura = 1;
    node->direita = NULL;
    node->esquerda = NULL;
    
    return node;
}

int pegarAltura(Node* node){
    if (node == NULL) {
        return 0;
    }
    return node->altura;
}

int fatorBalanceamento(Node* node){
    if (node == NULL) {
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

/* Right */
Node* rotateRight(Node* y){
    Node* x = y->esquerda;
    Node* T2 = x->direita;
    
    x->direita = y;
    y->esquerda = T2;
    
    updateAltura(y);
    updateAltura(x);
    return x;
}

/* Left */
Node* rotateLeft(Node* x){
    Node* y = x->direita;
    Node* T2 = y->esquerda;
    
    y->esquerda = x;
    x->direita = T2;

    updateAltura(x);
    updateAltura(y);
    return y;
}

/* BST */
Node* insert(Node* node, int value){
     /* 1. Inserção BST normal */
    if (node == NULL){
        return createNode(value);
    }
    if (value < node->value) {
        node->esquerda = insert(node->esquerda, value);
    } else if (value > node->value) {
        node->direita = insert(node->direita, value);
    } else {
        return node; // Não permite duplicatas
    }
    
    /* 2. Atualizar altura */
    updateAltura(node);

    /* 3. Obter fb */
    int balance = fatorBalanceamento(node);

    /* 4. Verificar e aplicar rotações */
    
    /* Caso Direita-Direita (RR) */
    if(balance > 1 && fatorBalanceamento(node->direita) >= 0){
        return rotateLeft(node);
    }

    /* Caso Direita-Esquerda (RL) */
    if(balance > 1 && fatorBalanceamento(node->direita) < 0){
        node->direita = rotateRight(node->direita);
        return rotateLeft(node);
    }

    /* Caso Esquerda-Direita (LR) */
    if(balance < -1 && fatorBalanceamento(node->esquerda) > 0){
        node->esquerda = rotateLeft(node->esquerda);
        return rotateRight(node);
    }

    /* Caso Esquerda-Esquerda (LL) */
    if(balance < -1 && fatorBalanceamento(node->esquerda) <= 0){
        return rotateRight(node);
    }

    return node;
}

/* Impressões */
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d(h:%d,fb:%d) ", root->value, root->altura, fatorBalanceamento(root));
        preOrder(root->esquerda);
        preOrder(root->direita);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->esquerda);
        printf("%d ", root->value);
        inOrder(root->direita);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->esquerda);
        freeTree(root->direita);
        free(root);
    }
}

int main(){
    Node* root = NULL;
    
    int valores[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    for(int i = 0; i < n; i++){
        root = insert(root, valores[i]);
        printf("Após inserir %d:\n", valores[i]);
        printf("Ordem: ");
        preOrder(root);
        printf("\n");
        printf("Em ordem: ");
        inOrder(root);
        printf("\n\n");
    }

    printf("Arvore (valor, altura, fator balanceamento): ");
    preOrder(root);
    printf("\n");
    
    printf("Arvore em ordem: ");
    inOrder(root);
    printf("\n");
    
    freeTree(root);
    
    return 0;
}