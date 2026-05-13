#include <stdio.h>

int main(){

    const int size = 5;
    int arr[size]= {};
    int arr1[size] = {};

    printf("Input your array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);

    int temp = 0;
    for (int i = 0; i < size; i++){
         for(int j = i + 1; j < size; j++ ){
             if (arr[i] > arr[j]){
                 temp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = temp;
             }
         }
    }
   
    printf("Sorted array is: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);

    }
    printf("\n");


  for (int i = 0; i < size; i++){
      for(int j = i + 1; j < size; j++) {
         if(arr[i] == arr[j])
            arr1[j] = 1;
      }
  } 
  
 printf("Sorted array without duplicates: ") ;
  for (int j = 0; j < size; j++){
       if (!arr1[j])
	   printf("%d ", arr[j]);
  }
   printf("\n");
  return 0;
}

