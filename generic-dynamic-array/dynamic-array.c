#include <stdio.h>
#include <stdlib.h>
#include "dynamic-array.h"

#define ARR_INIT_CAP 2
#define ARR_GROW_RAT 2

inline struct arr*
arrnew(void) {
    return arrnewcap(ARR_INIT_CAP);
}

inline struct arr*
arrnewcap(int cap)
{
    struct arr *arr;

    if((arr = malloc(sizeof(struct arr))) == NULL ) {
        return NULL;
    }

    if((arr->buf = malloc(cap * sizeof(TYPE))) == NULL) {
        free(arr);
        return NULL;
    }

    arr->len = 0;
    arr->cap = cap;

    return arr;
}

inline void 
arrdelete(struct arr *arr) {
    free(arr->buf);
    free(arr);
}

inline int 
arrappend(struct arr* arr, TYPE val) {
    if(arr->cap <= arr->len && arrresize(arr, arr->cap * ARR_GROW_RAT) == -1) {
        return -1;
    }  
    arr->buf[arr->len++] = val;
    return 0;
} 

inline int 
arrresize(struct arr *arr, int ncap) {
    TYPE *nbuf;
    if ((nbuf = realloc(arr->buf, ncap * sizeof(TYPE))) == NULL) {
        return -1;
    }

    arr->cap = ncap;
    arr->buf = nbuf;

    return 0;
}

inline TYPE 
arrremove(struct arr *arr) {
    return arr->buf[--arr->len];
}

void 
arrprint(struct arr* arr, void(*pt)(void*)) {
    for(int i = 0; i < arr->len; i++ ) {
        (*pt)(arr->buf[i]);
    }
}


