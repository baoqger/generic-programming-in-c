#include <stdlib.h>
#include <stdio.h>
#include "generic-hashtable.h"

static Position find(char *key, HashTable H);
static HashTable rehash(HashTable H);
static Position hash(char *key, int TableSize);

enum KindOfEntry {Legitimate, Empty, Deleted };

struct data {
    char *Key;
    void *Value; // use void* as generic type
};

struct HashEntry {
    ET Element;
    enum KindOfEntry Info;
};

struct HashTbl {
    int TableSize;
    int numElements; // keep track of number of elements we store
    Cell *TheCells;
};

HashTable 
initializeTable(int TableSize) {
    HashTable H;
    int i;

    H = malloc(sizeof(struct HashTbl));
    assert(H);
    
    H->TableSize = TableSize;
    H->numElements = 0;
    H->TheCells = malloc(H->TableSize * sizeof(Cell));
    assert(H->TheCells);

    for(i = 0; i < H->TableSize; i++) {
        H->TheCells[i].Info = Empty;
    }

    return H;
}

void 
DestroyTable(HashTable H) {
    free(H->TheCells);
    free(H);
}

static Position 
hash(char *key, int TableSize) {
    unsigned int HashVal = 0;
    while( *key != '\0') {
        HashVal = (HashVal << 5) + *key++;
    }
    return HashVal % TableSize;
} 
