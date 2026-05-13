#include <stdio.h>

int main(){

    const int size = 5;
    int arr[size]={};

    printf("Input your array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);

    int min  = arr[0];
    int max = arr[0];
    int min_index = 0;
    int max_index = 0;

    for(int i = 0; i < size; ++i){
       min = arr[i] < min ? arr[i] : min;
       if(min == arr[i])
          min_index = i;

       max = arr[i] > max ? arr[i] : max;
       if(max == arr[i])
          max_index = i;
 }

       printf("Difference of maximum and minimum element's index is %d\n", max_index - min_index);
       




   return  0;
}

