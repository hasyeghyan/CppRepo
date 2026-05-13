#include <stdio.h>

int main(){

    const int size = 5;
    int arr[size]={};

    printf("Input your array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);
    
    int *ptr  = arr;
   
    for(int i = 0; i < size; ++i){
        printf("%d ", ptr[i]);
    }
    printf("\n");

      



   return  0;
}


