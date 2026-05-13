#include <stdio.h>

int* convert(int arr[], int size){
    int temp = 0;
    for(int i = 0; i < size / 2; i++){
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
	arr[size - 1 - i] = temp;
    }
        return arr;
}

int main(){
   const int size = 5;
   int arr[size] = {};
   printf("PLease input your array: ");
   for(int i = 0; i < size; i++)
       scanf("%d", &arr[i]);

   convert(arr, size);

   printf("Converted array is: ");
   for(int i = 0; i < size; i++)
       printf("%d ", arr[i]);
  
   printf("\n");
   return 0;
}
