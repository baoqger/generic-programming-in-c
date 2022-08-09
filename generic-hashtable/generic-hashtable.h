#ifndef _DICT_H
#define _DICT_H 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef unsigned int Index;
typedef Index Position;

struct data;
typedef struct data ET;
struct HashEntry;
typedef struct HashEntry Cell;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable initializeTable(int TableSize);
void DestroyTable(HashTable H);
HashTable put(char *key, void *value, HashTable H);



#endif 
