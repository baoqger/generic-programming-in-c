#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "generic-hashtable.h"

static Position find(char *key, HashTable H);
static HashTable rehash(HashTable H);
static Position hash(char *key, int TableSize);
static int* primeList(int n);
static int nearestPrime(int n);
static int searchElement(int elem, int *a, int n);
static int arrayLength(int *);

enum KindOfEntry {Legitimate, Empty, Deleted };

struct data {
    char Key[20];
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




HashTable 
put(char *key, void *value, HashTable H) {
    Position currentPos;

    currentPos = find(key, H); // find the index of the key
    strcpy(H->TheCells[currentPos].Element.Key, key);   
    H->TheCells[currentPos].Element.Value = value;
    H->TheCells[currentPos].Info = Legitimate;
    H->numElements++;
    if (0.1 * H->numElements / H->TableSize >= 0.5 ) { // avoid integer division
        H = rehash(H);
    }
    return H;
}

static HashTable 
rehash(HashTable H) {
    HashTable newH = initializeTable(nearestPrime(2*H->TableSize)); // the tablesize should be a prime
    int i;
    for(i = 0; i < H->TableSize; i++) {
        put(H->TheCells[i].Element.Key, H->TheCells[i].Element.Value, newH);
    }
    DestroyTable(H);
    return newH;
}

static int*
primeList(int n)
{
  int p, i, j, k, l;
  int* N = calloc(n, sizeof(int)); //each cell indicates whether the index number is marked (1) or not (0)
  j = 0; //keep track of the final result list length
  for(p = 1; p < n; p++)
  {
    while(N[p] != 0 && p < n)
      p++;
    if (p >= n)
      break;
    j++;
    for(i = p; i < n; i = i + p + 1)
    {
      if(i == p)
        N[i] = 0;
      else
        N[i] = 1;
    }
  }
  int* result = calloc(j+1, sizeof(int));
  l = 1;
  for(k = 0; k < j; k++)
  {
    result[k] = l+1;
    l++;
    while(N[l] != 0)
      l++;
  }
  result[j] = INT_MAX;
  free(N);
  return result;
}

static int
nearestPrime(int n)
{
  int* array = primeList(n+10);
  int result = array[searchElement(n, array, arrayLength(array))];
  free(array);
  return result;
}

static int
searchElement(int elem, int *a, int n)
{
  int low, mid, high;

  // invariant: a[lo] < elem <= a[hi]
  low = -1;
  high = n;

  while(low + 1 < high)
  {
    mid = (low + high) / 2;
    if (a[mid] == elem)
      return mid;
    else if (a[mid] < elem)
      low = mid;
    else
      high = mid;
  }
  return high; // we return the index where elem <= a[i]
}

static int 
arrayLength(int *array) {
    int i;
    for(i = 0; array[i] != INT_MAX; i++);
    return i;
}
