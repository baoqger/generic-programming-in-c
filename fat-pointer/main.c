#include <stdio.h>
#include <stdlib.h>
#include "fat-pointer.h" 


int main() {
    int *arr = arrnew();

    for (int i = 0; i < 10; i++) {
        arrappend(arr, i);
    }
    
    for (int j = 0; j < arrlen(arr); j++) {
        printf("%d ", arr[j]);
    }

    printf("\n");
    return 0;
}


