#include <stdio.h>

int main(){
     
    const int size = 5;
    int arr[size]={};
   
    printf("Input your array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);

    int max  = arr[0];
    for(int i = 0; i < size; ++i){
       max = arr[i] > max ? arr[i] : max;
    }

       printf("Maximum element is %d\n", max );


             
   return  0;
}
