#include <stdio.h>

int main(){

    const int size = 5;
    char arr[size] = {};

    printf("Input array elements: ");
    for(int i = 0; i < size; ++i)
       scanf(" %c", &arr[i]);
   
    for(int i = 0; i < size; ++i){
        if(arr[i] >= '0' && arr[i] <= '9')
           printf(" %c", arr[i]);

    }
     

   
    printf("\n");

    return 0;
}

