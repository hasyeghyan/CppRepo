#include <stdio.h>

int main(){

    const int size = 5;
    int arr1[size] = {};
    int arr2[size] = {};

    printf("Input array1 elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr1[i]);
   
    printf("Input array2 elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr2[i]);


    for(int i = 0; i < size; ++i){
       arr1[i] = arr1[i] * arr2[i];
    }

    printf("Resut is: ");
    for(int i = 0; i < size; ++i)
       printf("%d ", arr1[i]);

    printf("\n");




   return  0;
}

