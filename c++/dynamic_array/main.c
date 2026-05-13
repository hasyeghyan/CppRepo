#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(){
    DynamicArray arr;
    initArray(&arr, 2);

    push_back(&arr, 10);
    push_back(&arr, 20);
    push_back(&arr, 30);
    printArray(&arr);

    insert(&arr, 1, 15);
    printArray(&arr);

    erase(&arr, 2);
    printArray(&arr);

    freeArray(&arr);
    return 0;
}
