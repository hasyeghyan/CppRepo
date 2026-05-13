#include <stdio.h>

int main(){

    const int size = 5;
    int arr[size]={};

    printf("Input your array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);
    
    int temp = 0;
    for (int i = 0; i < size; i++){
         for(int j = 0; j < size; j++ ){
	     if (arr[i] < arr[j]){
	         temp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = temp;
	     }
	 }    
    }

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);

    }
    printf("\n");





   return  0;
}
