/* Hash Table
    Matheus Marinho */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define table_size 10

typedef struct{
    int key;
    int value;
    struct Item* next; // pointer to next item
}Item;

Item* hashTable[table_size];

/* Função qeu retorna uma nova chave available. */
int hashFun(int key){
    return key % table_size;
}

Item* createItem(int key, int value){
    Item* novoItem = malloc(sizeof(Item));
    novoItem->key = key;
    novoItem->value = value;
    novoItem->next = NULL;
    return novoItem;
}

void print(Item* p){
    for(int i = 0; i <= table_size-1; i++){
        Item* current = p;
        while(current != NULL){
            printf("key: {%d}, value: [%d]", current->key, current->value);
            current = current->next;
        }
    }
}

void insert(int key, int value){
    int index = hashFun(key);
    Item* newItem = createItem(key, value);

    if(hashTable[index] == NULL){
        hashTable[index] = newItem;
    }else{
        newItem->next = hashTable[index];
        hashTable[index] = newItem;
    }
}

int search(){

}

void generateRandomData() {
    srand(time(NULL));   
    for (int i = 0; i < 10; i++) {
        int key = rand() % 100;  
        int value = rand() % 100;  
        insert(key, value);
    }
}

int main(int argc, char* argv[]){
    return 0;
}