/*k
    Estrutura de Dados II - Arvore B
    Matheus Marinho
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ORDER 5           // Ordem da arvore B (maximo de filhos)
#define MAX_KEYS (ORDER - 1)    // Maximo de chaves por no (4)
#define MIN_KEYS ((ORDER + 1) / 2 - 1) // Minimo de chaves por no (2)

typedef struct BTreeNode {
    int *keys;              // Array de chaves
    struct BTreeNode **children;  // Array de ponteiros para filhos
    int num_keys;           // Numero atual de chaves
    bool is_leaf;          // Verdadeiro se e folha
} BTreeNode;

// Criar um novo no
BTreeNode* createNode(bool is_leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    if (node == NULL) {
        printf("Falha ao alocar memoria.\n");
        return NULL;
    }
    
    node->keys = (int*)malloc(MAX_KEYS * sizeof(int));
    node->children = (BTreeNode**)malloc(ORDER * sizeof(BTreeNode*));
    node->num_keys = 0;
    node->is_leaf = is_leaf;
    
    // Inicializar ponteiros dos filhos como NULL
    for (int i = 0; i < ORDER; i++) {
        node->children[i] = NULL;
    }
    
    return node;
}

// Buscar uma chave na arvore B
BTreeNode* search(BTreeNode* root, int key) {
    int i = 0;
    
    // Encontrar a primeira chave maior ou igual a chave procurada
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }
    
    // Se encontrou a chave
    if (i < root->num_keys && key == root->keys[i]) {
        return root;
    }
    
    // Se e folha, a chave nao existe
    if (root->is_leaf) {
        return NULL;
    }
    
    // Buscar no filho apropriado
    return search(root->children[i], key);
}

// Dividir um filho cheio (quando tem MAX_KEYS chaves)
void splitChild(BTreeNode* parent, int index) {
    BTreeNode* full_child = parent->children[index];
    BTreeNode* new_child = createNode(full_child->is_leaf);
    
    int mid = MAX_KEYS / 2; // Indice do meio (2 para ordem 5)
    new_child->num_keys = MAX_KEYS - mid - 1; // 1 chave para o novo no
    
    // Copiar as chaves da direita para o novo no
    for (int j = 0; j < new_child->num_keys; j++) {
        new_child->keys[j] = full_child->keys[j + mid + 1];
    }
    
    // Copiar os filhos da direita se nao for folha
    if (!full_child->is_leaf) {
        for (int j = 0; j < new_child->num_keys + 1; j++) {
            new_child->children[j] = full_child->children[j + mid + 1];
        }
    }
    
    full_child->num_keys = mid; // Manter apenas as chaves da esquerda
    
    // Mover os filhos do pai para abrir espaco para o novo filho
    for (int j = parent->num_keys; j >= index + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    
    parent->children[index + 1] = new_child;
    
    // Mover as chaves do pai para abrir espaco para a nova chave
    for (int j = parent->num_keys - 1; j >= index; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    
    // Promover a chave do meio para o pai
    parent->keys[index] = full_child->keys[mid];
    parent->num_keys++;
}

// Inserir em um no que nao esta cheio
void insertNonFull(BTreeNode* node, int key) {
    int i = node->num_keys - 1;
    
    if (node->is_leaf) {
        // Mover as chaves para abrir espaco para a nova chave
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        
        node->keys[i + 1] = key;
        node->num_keys++;
    } else {
        // Encontrar o filho onde a nova chave deve ser inserida
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;
        
        // Verificar se o filho esta cheio
        if (node->children[i]->num_keys == MAX_KEYS) {
            splitChild(node, i);
            
            // Decidir qual dos dois filhos deve receber a nova chave
            if (node->keys[i] < key) {
                i++;
            }
        }
        
        insertNonFull(node->children[i], key);
    }
}

// Inserir uma chave na arvore B
BTreeNode* insert(BTreeNode* root, int key) {
    // Se a arvore esta vazia
    if (root == NULL) {
        root = createNode(true);
        root->keys[0] = key;
        root->num_keys = 1;
        return root;
    }
    
    // Se a raiz esta cheia, criar uma nova raiz
    if (root->num_keys == MAX_KEYS) {
        BTreeNode* new_root = createNode(false);
        new_root->children[0] = root;
        
        splitChild(new_root, 0);
        
        // A nova raiz tem duas filhas, decidir qual deve receber a nova chave
        int i = 0;
        if (new_root->keys[0] < key) {
            i++;
        }
        insertNonFull(new_root->children[i], key);
        
        return new_root;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Imprimir a arvore B de ordem 5
void printBTree(BTreeNode* root, int indent) {
    if (root != NULL) {
        // Identaçao 
        for (int i = 0; i < indent; i++) printf("    ");
        printf("[");
        for (int i = 0; i < root->num_keys; i++) {
            printf("%d", root->keys[i]);
            if (i < root->num_keys - 1) printf(", ");
        }
        printf("]\n");

        // Imprime os filhos
        if (!root->is_leaf) {
            for (int i = 0; i <= root->num_keys; i++) {
                printBTree(root->children[i], indent + 1);
            }
        }
    }
}

// Percorrer a árvore em ordem
void inOrder(BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->num_keys; i++) {
            if (!root->is_leaf) {
                inOrder(root->children[i]);
            }
            printf("%d ", root->keys[i]);
        }
        
        if (!root->is_leaf) {
            inOrder(root->children[i]);
        }
    }
}


// Função auxiliar para encontrar o índice da primeira chave maior ou igual a key
int findKey(BTreeNode* node, int key) {
    int idx = 0;
    while (idx < node->num_keys && node->keys[idx] < key)
        ++idx;
    return idx;
}

// Função para remover uma chave da subárvore enraizada em node
void removeFromNode(BTreeNode* node, int key);

// Função para obter o predecessor de uma chave
int getPredecessor(BTreeNode* node, int idx) {
    BTreeNode* cur = node->children[idx];
    while (!cur->is_leaf)
        cur = cur->children[cur->num_keys];
    return cur->keys[cur->num_keys - 1];
}

// Função para obter o sucessor de uma chave
int getSuccessor(BTreeNode* node, int idx) {
    BTreeNode* cur = node->children[idx + 1];
    while (!cur->is_leaf)
        cur = cur->children[0];
    return cur->keys[0];
}

// Função para fundir dois filhos de node
void merge(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx + 1];
    child->keys[MIN_KEYS] = node->keys[idx];
    for (int i = 0; i < sibling->num_keys; ++i)
        child->keys[i + MIN_KEYS + 1] = sibling->keys[i];
    if (!child->is_leaf) {
        for (int i = 0; i <= sibling->num_keys; ++i)
            child->children[i + MIN_KEYS + 1] = sibling->children[i];
    }
    for (int i = idx + 1; i < node->num_keys; ++i)
        node->keys[i - 1] = node->keys[i];
    for (int i = idx + 2; i <= node->num_keys; ++i)
        node->children[i - 1] = node->children[i];
    child->num_keys += sibling->num_keys + 1;
    node->num_keys--;
    free(sibling->keys);
    free(sibling->children);
    free(sibling);
}

// Função para emprestar uma chave do irmão anterior
void borrowFromPrev(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx - 1];
    for (int i = child->num_keys - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];
    if (!child->is_leaf) {
        for (int i = child->num_keys; i >= 0; --i)
            child->children[i + 1] = child->children[i];
    }
    child->keys[0] = node->keys[idx - 1];
    if (!child->is_leaf)
        child->children[0] = sibling->children[sibling->num_keys];
    node->keys[idx - 1] = sibling->keys[sibling->num_keys - 1];
    child->num_keys += 1;
    sibling->num_keys -= 1;
}

// Função para emprestar uma chave do irmão seguinte
void borrowFromNext(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx + 1];
    child->keys[child->num_keys] = node->keys[idx];
    if (!child->is_leaf)
        child->children[child->num_keys + 1] = sibling->children[0];
    node->keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->num_keys; ++i)
        sibling->keys[i - 1] = sibling->keys[i];
    if (!sibling->is_leaf) {
        for (int i = 1; i <= sibling->num_keys; ++i)
            sibling->children[i - 1] = sibling->children[i];
    }
    child->num_keys += 1;
    sibling->num_keys -= 1;
}

// Função para preencher o filho idx se ele tem menos que MIN_KEYS chaves
void fill(BTreeNode* node, int idx) {
    if (idx != 0 && node->children[idx - 1]->num_keys >= MIN_KEYS + 1)
        borrowFromPrev(node, idx);
    else if (idx != node->num_keys && node->children[idx + 1]->num_keys >= MIN_KEYS + 1)
        borrowFromNext(node, idx);
    else {
        if (idx != node->num_keys)
            merge(node, idx);
        else
            merge(node, idx - 1);
    }
}

// Função principal de remoção
void removeFromNode(BTreeNode* node, int key) {
    int idx = findKey(node, key);
    if (idx < node->num_keys && node->keys[idx] == key) {
        if (node->is_leaf) {
            for (int i = idx + 1; i < node->num_keys; ++i)
                node->keys[i - 1] = node->keys[i];
            node->num_keys--;
        } else {
            if (node->children[idx]->num_keys >= MIN_KEYS + 1) {
                int pred = getPredecessor(node, idx);
                node->keys[idx] = pred;
                removeFromNode(node->children[idx], pred);
            } else if (node->children[idx + 1]->num_keys >= MIN_KEYS + 1) {
                int succ = getSuccessor(node, idx);
                node->keys[idx] = succ;
                removeFromNode(node->children[idx + 1], succ);
            } else {
                merge(node, idx);
                removeFromNode(node->children[idx], key);
            }
        }
    } else {
        if (node->is_leaf) {
            // Chave não encontrada
            return;
        }
        bool flag = (idx == node->num_keys);
        if (node->children[idx]->num_keys < MIN_KEYS + 1)
            fill(node, idx);
        if (flag && idx > node->num_keys)
            removeFromNode(node->children[idx - 1], key);
        else
            removeFromNode(node->children[idx], key);
    }
}

// Função para remover uma chave da árvore B
BTreeNode* removeKey(BTreeNode* root, int key) {
    if (!root) return NULL;
    removeFromNode(root, key);
    if (root->num_keys == 0) {
        BTreeNode* tmp = root;
        if (root->is_leaf) {
            root = NULL;
        } else {
            root = root->children[0];
        }
        free(tmp->keys);
        free(tmp->children);
        free(tmp);
    }
    return root;
}

// Liberar memoria da arvore
void freeTree(BTreeNode* root) {
    if (root != NULL) {
        if (!root->is_leaf) {
            for (int i = 0; i <= root->num_keys; i++) {
                freeTree(root->children[i]);
            }
        }
        free(root->keys);
        free(root->children);
        free(root);
    }
}

// Funcao para criar a arvore base dos casos 1 e 2
BTreeNode* criarArvoreBase() {
    BTreeNode* root = NULL;

    // Caso 1: Inserir 20, 40, 60, 80, 70
    int caso1[] = {20, 40, 60, 80, 70};
    int n1 = sizeof(caso1) / sizeof(caso1[0]);
    for (int i = 0; i < n1; i++) {
        root = insert(root, caso1[i]);
    }

    // Caso 2: Inserir 10 e 30
    int caso2[] = {10, 30};
    int n2 = sizeof(caso2) / sizeof(caso2[0]);
    for (int i = 0; i < n2; i++) {
        root = insert(root, caso2[i]);
    }

    printf("\n");
    return root;
}

int main() {
    BTreeNode* root = NULL;

    /* Dois casos de inserção */
    printf("--- Casos de insercao: --- \n");

    // Caso 1: Inserir 20, 40, 60, 80, 70
    int caso1[] = {20, 40, 60, 80, 70};
    int n1 = sizeof(caso1) / sizeof(caso1[0]);
    printf("Caso 1: Inserindo 20, 40, 60, 80, 70\n");
    for (int i = 0; i < n1; i++) {
        root = insert(root, caso1[i]);
    }
    printBTree(root, 0);

    // Caso 2: Inserir 10 e 30
    int caso2[] = {10, 30};
    int n2 = sizeof(caso2) / sizeof(caso2[0]);
    printf("\nCaso 2: Inserindo 10 e 30\n");
    for (int i = 0; i < n2; i++) {
        root = insert(root, caso2[i]);
    }
    printBTree(root, 0);

    /* Casos de remocao */
    printf("\n--- Casos de remocao: ---");

    // 1. Remocao de folha
    root = criarArvoreBase();
    printf("\nCaso 1: Removendo o elemento 40 (folha)\n");
    root = removeKey(root, 40);
    if (root) printBTree(root, 0);

    // 2. Remocao de nó interno usando predecessor
    root = criarArvoreBase();
    printf("\nCaso 2: Removendo o elemento 30 (no interno, predecessor)\n");
    root = removeKey(root, 30);
    if (root) printBTree(root, 0);

    // 3. Remocao de nó interno usando sucessor
    root = criarArvoreBase();
    printf("\nCaso 3: Removendo o elemento 60 (no interno, sucessor)\n");
    root = removeKey(root, 60);
    if (root) printBTree(root, 0);

    // 4. Remocao de nó interno com fusao dos filhos
    root = criarArvoreBase();
    printf("\nCaso 4: Removendo o elemento 20 (no interno, fusao)\n");
    root = removeKey(root, 20);
    if (root) printBTree(root, 0);

    // 5. Remocao de subarvore com redistribuicao (emprestimo do irmao)
    root = criarArvoreBase();
    printf("\nCaso 5: Removendo o elemento 10 (redistribuicao)\n");
    root = removeKey(root, 10);
    if (root) printBTree(root, 0);

    // 6. Remocao de subarvore com fusao (quando ambos filhos e irmao tem n-1 chaves)
    root = criarArvoreBase();
    printf("\nCaso 6: Removendo o elemento 70 (fusao de folhas)\n");
    root = removeKey(root, 70);
    if (root) printBTree(root, 0);

    /* Casos de busca */
    printf("\nCasos de busca:\n");
    root = criarArvoreBase();

    int buscas[] = {10, 15, 30, 40, 55, 70};
    int n_buscas = sizeof(buscas) / sizeof(buscas[0]);
    for (int i = 0; i < n_buscas; i++) {
        BTreeNode* resultado = search(root, buscas[i]);
        if (resultado != NULL) {
            printf("Chave %d encontrada.\n", buscas[i]);
        } else {
            printf("Chave %d nao encontrada.\n", buscas[i]);
        }
    }

    // Liberar memoria
    freeTree(root);
    return 0;
}