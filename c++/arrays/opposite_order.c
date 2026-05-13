#include <stdio.h>

int main(){

    const int size = 5;
    char arr[size] = {};

    printf("Input array elements: ");
    for(int i = 0; i < size; ++i)
       scanf(" %c", &arr[i]);
   
    int temp = 0;     
    for(int i = 0; i < size/2;  ++i){
        temp = arr[i];
	arr[i] =  arr[size - 1 -i];
	arr[size - 1 - i] = temp;
    }


       for(int i = 0; i < size; ++i)
           printf("%c ", arr[i]);

       printf("\n");






   return  0;
}

