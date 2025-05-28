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
        node->altura = 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir); // se alturaEsq > alturaDir :::: true -> alturaEsq :::: false -> alturaDir
        
    }
}

/* NULL @@@@@@@@ will be @@@@@@@ Node: 
                                         [value]
                                        /       \                   
                                       esq      dir
                                        
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                           
*/


/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                                 antes:
                                        y (nó desbalanceado)
                                       /  \
                                      x    T3
                                     / \
                                    T1  T2  

                                depois:
                                x (nova raiz)
                               / \
                              T1   y
                             / \
                            T2  T3
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   */
/* Rotações */
/* Right */
Node* rotateRight(Node* y){
    /* antes da rotação */
    Node* x = y->esquerda;
    Node* T2 = x->direita;
    
    /* na rotação */
    x->direita = y;
    y->esquerda = T2;
    updateAltura(y);
    updateAltura(x);
    return x;
}

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                                 antes:
    x (nó desbalanceado)
   /  \
  T1   y
      / \
     T2  T3  

                                depois:
                                y (nova raiz)
                               / \
                              x   T3
                             / \
                            T1  T2
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   */


/* Left */
Node* rotateLeft(Node* x){
    /* antes da rotação */
    Node* y = x->direita;
    Node* T2 = y->esquerda;
    
    /* na rotação */
    y->esquerda = x;
    x->direita = T2;

    updateAltura(x);
    updateAltura(y);
    return y;
}
/* Integramos as rotações duplas (caso houverem) na função inserir */
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

    /* Rotações duplas */
    /* Olhando pelo referencial da direita:
        i) rotateRight_Right (fb > 1)
        ii) rotateRight_Left (fb > 1) 
    */

    /* rotateRightRight */
    if(fatorBalanceamento > 1 && value > node->direita->value){
        return rotateLeft(node);
    }

    /* rotateRightLeft */
    if(fatorBalanceamento > 1 && value < node->direita->value){
        node->direita = rotateRight(node->direita);
        return rotateLeft(node);
    }

    /* Olhando pelo referencial da esquerda:
        i) rotateLeft_Right (fb < -1)
        ii) rotateLeft_Left (fb < -1) 
    */

    /* rotateLeftRight */
    if(fatorBalanceamento < -1 && value > node->esquerda->value){
        node->esquerda = rotateLeft(node->esquerda);
        return rotateRight(node);
    }

    /* rotateLeftLeft */
    if(fatorBalanceamento < -1 && value > node->esquerda->value){
        node->esquerda = rotateRight(node);
    }

    return node;
}

/* Impressões */
void print(Node* root) {
    if (root != NULL) {
        printf("%d(h:%d) ", root->value, root->altura);
        preOrder(root->esquerda);
        preOrder(root->direita);
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
    
    printf("Inserindo valores: 10, 20, 30, 40, 50, 25\n");
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    
    printf("Árvore em ordem: ");
    inOrder(root);
    printf("\n");
    
    printf("Árvore em pré-ordem (com alturas): ");
    preOrder(root);
    printf("\n");
    
    // Liberar memória
    freeTree(root);
    
    return 0;
    return 0;
}