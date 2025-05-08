/* 
    Hash Table - Strings
    Matheus Marinho 

*/
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
    
/* .csv para os graficos */
typedef struct{
    int tableSize;
    int inputs;
    int colisoes;
    double insertionTime;
    double searchTime;
} Experiment;
    
/* estrutura dos nós */
typedef struct Item{ 
    char* key;
    int value;
    struct Item* next; 
} Item;
    
/* vars */
Item** hashTable = NULL;
int tableSize = 0;
int colisoes = 0;
    
/* func hash p/ strings */
unsigned int hashString(const char* str) {
    unsigned int hash = 5381;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    
    return hash % tableSize;
}
    
/* criando as strings */
Item* createItem(const char* key, int value) {
    Item* novoItem = (Item*)malloc(sizeof(Item));
    if (novoItem == NULL) {  
        fprintf(stderr, "Erro: Falha na alocação de memória\n");
        exit(1);
    }

    novoItem->key = strdup(key);
    if (novoItem->key == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para a chave\n");
        free(novoItem);
        exit(1);
    }
    
    novoItem->value = value;
    novoItem->next = NULL;
    return novoItem;
}

/* init a hash */
void initHashTable(int size) {
    tableSize = size;
    colisoes = 0;
    
    if (hashTable != NULL) {
        for (int i = 0; i < tableSize; i++) {
            Item* current = hashTable[i];
            while (current != NULL) {
                Item* temp = current;
                current = current->next;
                free(temp->key); 
                free(temp);
            }
        }
        free(hashTable);
    }

    hashTable = (Item**)calloc(size, sizeof(Item*));
    if (hashTable == NULL) {
        fprintf(stderr, "Erro: Falha na alocação da tabela.\n");
        exit(1);
    }
}

void print() {
    for (int i = 0; i < tableSize; i++) {
        printf("[%d]: ", i);
        Item* current = hashTable[i];
        while (current != NULL) {
            printf("-> (key: %s, value: %d) ", current->key, current->value);
            current = current->next;
        }
        printf("-> NULL\n");
    }
}

/* novo insert com o contador de colisoes */
void insert(const char* key, int value) {
    unsigned int index = hashString(key);
    Item* newItem = createItem(key, value);
    
    /* há colisoes? */
    if (hashTable[index] != NULL) {
        colisoes++; 
    }
    
    /* insere no início da lista (se houver) */
    newItem->next = hashTable[index];
    hashTable[index] = newItem;
}
    
Item* search(const char* key) {
    unsigned int index = hashString(key);
    Item* current = hashTable[index];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}
    
/* Garbage collector */
void freeHashTable() {  
    if (hashTable == NULL) return;
    
    for (int i = 0; i < tableSize; i++) {
        Item* current = hashTable[i];
        while (current != NULL) {
            Item* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
        hashTable[i] = NULL;
    }
    
    free(hashTable);
    hashTable = NULL;
}

/* novo generate agora para strings */
char* generateRandomString(int minLen, int maxLen) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int len = minLen + rand() % (maxLen - minLen + 1);
    
    char* str = (char*)malloc(len + 1);
    if (str == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para string aleatória.\n");
        exit(1);
    }
    
    for (int i = 0; i < len; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[len] = '\0';
    
    return str;
}

/* Função adicionada: Gerador de conjunto de strings aleatórias */
char** generateRandomStrings(int count, int minLen, int maxLen) {
    char** strings = (char**)malloc(count * sizeof(char*));
    if (strings == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para conjunto de strings\n");
        exit(1);
    }
    
    for (int i = 0; i < count; i++) {
        strings[i] = generateRandomString(minLen, maxLen);
    }
    
    return strings;
}

/* garbage collector 2 p/ strings somente */
void freeStrings(char** strings, int count) {
    for (int i = 0; i < count; i++) {
        free(strings[i]);
    }
    free(strings);
}

/* funcao responsavel pelo experimento */
Experiment runExperiment(int tableSize, int numInputs) {
    Experiment result;
    result.tableSize = tableSize;
    result.inputs = numInputs;

    initHashTable(tableSize);
    
    char** testStrings = generateRandomStrings(numInputs, 5, 15);
    
    /* medição do time */
    clock_t start = clock();
    for (int i = 0; i < numInputs; i++) {
        insert(testStrings[i], i);
    }
    clock_t end = clock();
    result.insertionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    result.colisoes = colisoes;
    
    /* tempo de busca */
    start = clock();
    for (int i = 0; i < numInputs; i++) {
        search(testStrings[i]);
    }
    end = clock();
    result.searchTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    freeStrings(testStrings, numInputs);
    freeHashTable();
    
    return result;
}

/* .csv */
void writeResultsToCSV(Experiment* results, int numResults, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(file, "TableSize,NumInputs,Collisions,InsertionTime,SearchTime\n");
        
    /* inserindo dados */
    for (int i = 0; i < numResults; i++) {
        fprintf(file, "%d,%d,%d,%f,%f\n", 
                results[i].tableSize, 
                results[i].inputs,
                results[i].colisoes,
                results[i].insertionTime,
                results[i].searchTime);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    srand((unsigned int)time(NULL));
    
    int tableSizes[] = {31, 79, 151};
    int numTableSizes = sizeof(tableSizes) / sizeof(tableSizes[0]);
    
    int inputSizes[] = {100, 1000, 10000};
    int numInputSizes = sizeof(inputSizes) / sizeof(inputSizes[0]);
    
    int totalExperiments = numTableSizes * numInputSizes;
    Experiment* results = (Experiment*)malloc(totalExperiments * sizeof(Experiment));
    
    if (results == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para resultados\n");
        return 1;
    }
    
    int resultIndex = 0;
    for (int i = 0; i < numTableSizes; i++) {
        for (int j = 0; j < numInputSizes; j++) {
            printf("Executando experimento: Tamanho da tabela = %d, Entradas = %d\n", 
                   tableSizes[i], inputSizes[j]);
            
            results[resultIndex] = runExperiment(tableSizes[i], inputSizes[j]);
            resultIndex++;
        }
    }
    
    writeResultsToCSV(results, totalExperiments, "hash_results.csv");
    
    printf("\n--- Resultados dos Experimentos ---\n");
    printf("%-10s %-10s %-12s %-15s %-15s\n", 
           "Tamanho", "Entradas", "Colisoes", "Tempo Insercao", "Tempo Busca");
    
    for (int i = 0; i < totalExperiments; i++) {
        printf("%-10d %-10d %-12d %-15f %-15f\n", 
               results[i].tableSize,
               results[i].inputs,
               results[i].colisoes,
               results[i].insertionTime,
               results[i].searchTime);
    }
    
    printf("\nResultados gerados com sucesso no arquivo hash_results.csv\n");
    free(results);
    
    return 0;
}