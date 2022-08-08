#include <stdlib.h>
#include <stdio.h>
#include "fat-pointer.h"

#define ARR_INIT_CAP 2
#define ARR_GROW_RAT 2

inline ARR 
arrnew(void) {
    return arrnewcap(ARR_INIT_CAP);
}

inline ARR 
arrnewcap(int cap) {
    int *buf;
    // allocate 2 more bytes memory at the beginning address 
    if((buf = malloc(cap * sizeof(TYPE) + 2 * sizeof(int))) == NULL ) {
        return NULL;
    }

    buf[0] = 0;
    buf[1] = cap; 

    return (ARR)(buf + 2);
}

inline void 
arrdelete(ARR arr) {
    free((int*)arr - 2); // pointer arithmatic is in the unit of pointer type
}

inline ARR 
arrappend(ARR arr, TYPE val) {
    int *buf, len, cap;
    buf = (int*)arr - 2;
    len = buf[0];
    cap = buf[1];

    if (cap <= len && (arr = arrresize(arr, cap * ARR_GROW_RAT)) == NULL) {
        return NULL;
    }

    buf = (int*)arr - 2;
    arr[buf[0]++] = val;
    
    return arr;
}

inline ARR 
arrresize(ARR arr, int ncap) {
    int *buf, len;

    buf = (int*)arr - 2;
    len = buf[0];

    if ((buf = realloc(buf, ncap * sizeof(TYPE) + 2 * sizeof(int))) == NULL)  {
        return NULL;
    }

    buf[0] = len;
    buf[1] = ncap;

    return (ARR)(buf + 2);
}

inline TYPE 
arrremove(ARR arr) {
    return arr[--((int*)arr - 2)[0]];
}


inline int 
arrlen(ARR arr) {
    return ((int*)arr - 2)[0];
}

inline int 
arrcap(ARR arr) {
    return ((int*)arr - 2)[1];
}

