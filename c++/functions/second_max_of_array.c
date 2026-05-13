#include <stdio.h>

int second_max(int arr[], int size){
     int temp = 0;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
	    if(arr[i] > arr[j]){
	       temp = arr[i];
               arr[i] = arr[j];
	       arr[j] = temp;      
	    }
	}
    }
    for(int i = size- 1 ; i >=0; i--){
        if (arr[i] != arr[size - 1])
	   return arr[i];
    }
     return arr[size - 1];
}

int main(){
   const int size = 5;
   int arr[size] = {};
   printf("PLease input your array: ");
   for(int i = 0; i < size; i++)
       scanf("%d", &arr[i]);

   printf("Array's second maximum element is %d\n", second_max(arr, size));
   return 0;
}

