#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void initArray(DynamicArray *arr, size_t initial_capacity){
     arr->size = 0;
     arr->capacity = initial_capacity;
     arr->capacity = arr->capacity == 0 ? 4 : arr->capacity;
     arr->data = (int *)malloc(arr->capacity * sizeof(int));
     if(arr->data == NULL){
       printf("Error: ");
       return;
     }
}

void push_back(DynamicArray *arr, int value){ 
     if(arr->size == arr->capacity){
       int *p  = (int * )realloc(arr->data,2 * arr->capacity *sizeof(int));
       if(p == NULL){
         printf("Error: ");
	 return;
       }
       arr->data = p;
       arr->capacity *= 2;
     }
     arr->data[arr->size] = value;
     ++arr->size;
}

void insert(DynamicArray *arr, size_t index, int value){ 
     if(index >= arr->size){
       printf("Invalid index: ");
       return;
     }
     if(arr->size == arr->capacity){
       int *p1  = (int * )realloc(arr->data,2 * arr->capacity *sizeof(int));
       if(p1  == NULL){
         printf("Error: ");
         return;
       }
       arr->data = p1;
       arr->capacity *= 2;
     }
     for(int i = arr->size; i > index; --i){
        arr->data[i] = arr->data[i - 1];
     }
     ++arr->size;
     arr->data[index] = value; 
}

void erase(DynamicArray *arr, size_t index){
     if(index >= arr->size){
       printf("Invalid index: ");
       return;
     }
     for(int i = index; i < arr->size - 1; ++i){
         arr->data[i] = arr->data[i + 1];
     }
     --arr->size;
}

void printArray(DynamicArray *arr){
     printf("Here are your array elements: ");
     for(int i = 0; i < arr->size; ++i){
        printf("%d ",arr->data[i]);
     }
     printf("\n");
}

void freeArray(DynamicArray *arr){
     free(arr->data);
     arr->size = 0;
     arr->capacity = 0;
}

void popArray(DynamicArray *arr){
     if(arr->size == 0){
       printf("Array is empty: ");
       return;
     }
     --arr->size;
}

void shrink_to_fit(DynamicArray *arr){
     if(arr->size == 0){
       printf("Array is empty: ");
       free(arr->data);
       arr->capacity = 0;
       return;
     }
     int *p2 = (int *)realloc(arr->data,arr->size * sizeof(int));
     if(p2 == NULL){
       printf("Error: ");
       return;
     } 
     arr->data = p2;
     arr->capacity = arr->size;
}


