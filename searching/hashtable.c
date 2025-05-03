/* 
    Hash Table
    Matheus Marinho 

    */
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #define table_size 10
    
    typedef struct Item{ 
        int key;
        int value;
        struct Item* next; 
    } Item;
    
    Item* hashTable[table_size] = {NULL}; 
    
    int hashFun(int key) {
        return key % table_size;
    }
    
    Item* createItem(int key, int value) {
        Item* novoItem = (Item*)malloc(sizeof(Item));
        if (novoItem == NULL) {  
            fprintf(stderr, "Erro: Falha na alocação de memória\n");
            exit(1);
        }
        novoItem->key = key;
        novoItem->value = value;
        novoItem->next = NULL;
        return novoItem;
    }
    
    void print() {
        for (int i = 0; i < table_size; i++) {
            printf("[%d]: ", i);
            Item* current = hashTable[i];
            while (current != NULL) {
                printf("-> (key: %d, value: %d) ", current->key, current->value);
                current = current->next;
            }
            printf("-> NULL\n");
        }
    }
    
    void insert(int key, int value) {
        int index = hashFun(key);
        Item* newItem = createItem(key, value);
    
        if (hashTable[index] == NULL) {
            hashTable[index] = newItem;
        } else {
            newItem->next = hashTable[index];
            hashTable[index] = newItem;
        }
    }
    
    Item* search(int key) {
        int index = hashFun(key);
        Item* current = hashTable[index];
        while (current != NULL) {
            if (current->key == key) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
    
    /* Garbage collector */
    void freeHashTable() {  
        for (int i = 0; i < table_size; i++) {
            Item* current = hashTable[i];
            while (current != NULL) {
                Item* temp = current;
                current = current->next;
                free(temp);
            }
            hashTable[i] = NULL;
        }
    }
    
    void generateRandomData() {
        srand(time(NULL));
        for (int i = 0; i < 10; i++) {
            int key = rand() % 100;
            int value = rand() % 100;
            insert(key, value);
        }
    }
    
    int main(int argc, char* argv[]) {
        generateRandomData();
    
        printf("Tabela Hash:\n");
        print();
    
        int keyToSearch = 42;
        Item* foundItem = search(keyToSearch);
        if (foundItem != NULL) {
            printf("\nItem encontrado: key = %d, value = %d\n", foundItem->key, foundItem->value);
        } else {
            printf("\nItem com key = %d não encontrado.\n", keyToSearch);
        }
    
        freeHashTable();  
        return 0;
    }