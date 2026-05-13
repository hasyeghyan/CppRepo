#include <stdio.h>

int main(){

    const int size = 5;
    int arr[size]={};

    printf("Input your array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);

    int min  = arr[0];
    for(int i = 0; i < size; ++i){
       min = arr[i] < min ? arr[i] : min;
    }

       printf("Minimum element is %d\n", min);



   return  0;
}

