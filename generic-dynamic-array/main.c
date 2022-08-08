#include <stdlib.h>
#include <stdio.h>
#include "dynamic-array.h"

void printInt(void* i) {
    printf("%d ",*(int*)i);
}

void printStr(void* s) {
    printf("%s ", (char*)s);
}

int main() {
    printf("---Test Dynamic Array---\n");
    struct arr *arr;
    
    arr = arrnew();

    // Test int array
    for(int i = 0; i < 10; i++) {
        int *ip = malloc(sizeof(int));
        *ip = i;
        arrappend(arr, ip);
    }
    arrprint(arr, printInt);

    arrdelete(arr);

    struct arr* arrstr;
    arrstr = arrnew();
    arrappend(arrstr, "a");
    arrappend(arrstr, "b");
    arrappend(arrstr, "c");
    arrprint(arrstr, printStr);
    
    arrdelete(arrstr);

    return 0;
}

