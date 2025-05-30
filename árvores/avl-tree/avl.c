/*
    Estrutura de Dados II - Matheus Sousa Marinho (202206132) e Henryque Oliveira Affiune (202201634) 
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
    
    // Parametros 
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

/* @@@@@@@@@@@@@@@@@ - rotateRight - @@@@@@@@@@@@@@@@@
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

/* @@@@@@@@@@@@@@ - rotateLeft - @@@@@@@@@@@@@@@
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
    Node* y = x->direita;
    Node* T2 = y->esquerda;
    
    y->esquerda = x;
    x->direita = T2;

    updateAltura(x);
    updateAltura(y);
    return y;
}
/* Inserir */
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

/* Funcao para calcular a profundidade maxima da arvore */
int calcularProfundidade(Node* root) {
    if (root == NULL) return 0;
    int profEsq = calcularProfundidade(root->esquerda);
    int profDir = calcularProfundidade(root->direita);
    return 1 + (profEsq > profDir ? profEsq : profDir);
}

/* Funcao para imprimir espacos */
void imprimirEspacos(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

/* Estrutura para armazenar informacoes dos nos em cada nivel */
typedef struct {
    Node* no;
    int posicao;
} NoNivel;

/* Funcao melhorada para imprimir a arvore verticalmente */
void imprimirArvoreVertical(Node* root) {
    if (root == NULL) {
        printf("Arvore vazia\n");
        return;
    }
    
    int profundidade = calcularProfundidade(root);
    int larguraMaxima = (1 << profundidade) * 6; // Aumentado para melhor espaçamento
    
    // Array para cada nivel
    NoNivel** niveis = (NoNivel**)malloc(profundidade * sizeof(NoNivel*));
    int* tamanhosNivel = (int*)calloc(profundidade, sizeof(int));
    int* capacidadeNivel = (int*)malloc(profundidade * sizeof(int));
    
    // Inicializar arrays
    for (int i = 0; i < profundidade; i++) {
        capacidadeNivel[i] = 1 << i;
        niveis[i] = (NoNivel*)malloc(capacidadeNivel[i] * sizeof(NoNivel));
    }
    
    // Preencher niveis usando BFS
    NoNivel* fila = (NoNivel*)malloc(1000 * sizeof(NoNivel));
    int inicio = 0, fim = 0;
    
    fila[fim++] = (NoNivel){root, larguraMaxima / 2};
    
    int nivelAtual = 0;
    int nosNivelAtual = 1;
    int nosProcessados = 0;
    
    while (inicio < fim) {
        NoNivel atual = fila[inicio++];
        
        if (atual.no != NULL) {
            niveis[nivelAtual][tamanhosNivel[nivelAtual]++] = atual;
            
            int espacamento = larguraMaxima / (1 << (nivelAtual + 2));
            
            if (atual.no->esquerda || atual.no->direita) {
                fila[fim++] = (NoNivel){atual.no->esquerda, atual.posicao - espacamento};
                fila[fim++] = (NoNivel){atual.no->direita, atual.posicao + espacamento};
            }
        }
        
        nosProcessados++;
        if (nosProcessados == nosNivelAtual) {
            nivelAtual++;
            nosNivelAtual *= 2;
            nosProcessados = 0;
        }
    }
    
    // Imprimir cada nivel
    for (int nivel = 0; nivel < profundidade; nivel++) {
        if (tamanhosNivel[nivel] == 0) break;
        
        // Verificar se ha nos nao nulos neste nivel
        int temNos = 0;
        for (int i = 0; i < tamanhosNivel[nivel]; i++) {
            if (niveis[nivel][i].no != NULL) {
                temNos = 1;
                break;
            }
        }
        
        if (!temNos) break;
        
        // Imprimir conexoes melhoradas (exceto para o primeiro nivel)
        if (nivel > 0) {
            // Primeiro, imprimir as linhas de conexao
            for (int j = 0; j < tamanhosNivel[nivel-1]; j++) {
                if (niveis[nivel-1][j].no != NULL) {
                    Node* pai = niveis[nivel-1][j].no;
                    int posicaoPai = niveis[nivel-1][j].posicao;
                    
                    // Verificar se tem filhos e onde estao
                    int posEsq = -1, posDir = -1;
                    
                    for (int k = 0; k < tamanhosNivel[nivel]; k++) {
                        if (niveis[nivel][k].no == pai->esquerda && pai->esquerda != NULL) {
                            posEsq = niveis[nivel][k].posicao;
                        }
                        if (niveis[nivel][k].no == pai->direita && pai->direita != NULL) {
                            posDir = niveis[nivel][k].posicao;
                        }
                    }
                    
                    // Imprimir linha horizontal se ambos os filhos existem
                    if (posEsq != -1 && posDir != -1) {
                        imprimirEspacos(posEsq + 1);
                        for (int x = posEsq + 1; x < posDir + 1; x++) {
                            if (x == posicaoPai) {
                                printf("|");
                            } else {
                                printf("-");
                            }
                        }
                        printf("\n");
                    }
                }
            }
            
            // Barras diagonais
            int ultimaPos = 0;
            for (int i = 0; i < tamanhosNivel[nivel]; i++) {
                if (niveis[nivel][i].no != NULL) {
                    int posicaoAtual = niveis[nivel][i].posicao;
                    
                    // Encontrar o pai deste no
                    for (int j = 0; j < tamanhosNivel[nivel-1]; j++) {
                        if (niveis[nivel-1][j].no != NULL) {
                            Node* pai = niveis[nivel-1][j].no;
                            int posicaoPai = niveis[nivel-1][j].posicao;
                            
                            if (pai->esquerda == niveis[nivel][i].no) {
                                // Filho da esquerda
                                int espacos = posicaoAtual - ultimaPos;
                                if (espacos > 0) imprimirEspacos(espacos);
                                printf("/");
                                ultimaPos = posicaoAtual + 1;
                                break;
                            } else if (pai->direita == niveis[nivel][i].no) {
                                // Filho da direita
                                int espacos = posicaoAtual - ultimaPos;
                                if (espacos > 0) imprimirEspacos(espacos);
                                printf("\\");
                                ultimaPos = posicaoAtual + 1;
                                break;
                            }
                        }
                    }
                }
            }
            printf("\n");
        }
        
        // Imprimir nos
        int ultimaPosicao = 0;
        for (int i = 0; i < tamanhosNivel[nivel]; i++) {
            if (niveis[nivel][i].no != NULL) {
                int espacos = niveis[nivel][i].posicao - ultimaPosicao;
                if (espacos > 0) imprimirEspacos(espacos);
                
                if (nivel == 0) {
                    printf("[%d]", niveis[nivel][i].no->value);
                } else {
                    printf("[%d]", niveis[nivel][i].no->value);
                }
                
                ultimaPosicao = niveis[nivel][i].posicao + 3; // 3 = tamanho de "[x]"
            }
        }
        printf("\n");
    }
    
    // Limpar memoria
    for (int i = 0; i < profundidade; i++) {
        free(niveis[i]);
    }
    free(niveis);
    free(tamanhosNivel);
    free(capacidadeNivel);
    free(fila);
}

/* Funcao principal para impressao */
void printTree(Node* root) {
    if (root == NULL) {
        printf("Arvore vazia\n");
        return;
    }
    
    printf("Estrutura da Arvore AVL:\n");
    imprimirArvoreVertical(root);
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
    
    int valores[] = {1, 6, 23, 10, 2, 11};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    /* Insercoes */
    for(int i = 0; i < n; i++){
        root = insert(root, valores[i]);
        printf("Apos inserir %d:\n", valores[i]);
        printTree(root);
        printf("\n");
    }

    printf("Arvore Final:\n");
    printTree(root);
    
    printf("\nPercurso em ordem: ");
    inOrder(root);
    printf("\n");
    
    freeTree(root);
    
    return 0;
}