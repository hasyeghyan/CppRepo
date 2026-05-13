#include <stdio.h>

int main(){

    const int size = 5;
    int arr[size]={};

    printf("Input your array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);

    for(int i = 0; i < size; ++i){
       arr[i] = arr[i] / size;
    }

    printf("Updated array is: ");
    for(int i = 0; i < size; ++i)
       printf("%d ", arr[i]);
    
    printf("\n");




   return  0;
}


