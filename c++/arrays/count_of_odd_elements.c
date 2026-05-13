#include <stdio.h>

int main(){

    const int size = 5;
    int arr[size] = {};

    printf("Input array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);
    
    int count = 0;
    for(int i = 0; i < size; ++i){
        if((arr[i] % 2) == 1)
            count++;
    }
     printf("Count of odd numbers is %d\n", count);

    return 0;
}

