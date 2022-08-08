// ## is token paste operator which pastes two tokens together to create a new token

#include <stdio.h>
#include <stdlib.h>

// Generic definition
#define GENERIC_MAX(TYPE) \
    TYPE TYPE##_max(TYPE a, TYPE b) \
    {                               \
        return (a > b) ? a : b;     \
    }                               \

GENERIC_MAX(int);
GENERIC_MAX(float);

int main() {
    printf("max of 1 and 2 is: %d\n", int_max(1, 2)); 
    printf("max of 1.0 and 2.0 is: %f\n", float_max(1.0, 2.0));
    return 0;
}
