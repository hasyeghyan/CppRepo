#include <stdio.h>

int main(){

    const int size = 3;
    int arr[size]= {};
    int arr1[size] = {};

    printf("Input your array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);
 
    printf("Input your array1 elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr1[i]);


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
   
    temp = 0;
    for (int i = 0; i < size; i++){
         for(int j = i + 1; j < size; j++ ){
             if (arr1[i] > arr1[j]){
                 temp = arr1[i];
                 arr1[i] = arr1[j];
                 arr1[j] = temp;
             }
         }
    }

    printf("Sorted array1 is: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr1[i]);

    }
    printf("\n");
    
   int arr2[2 * size] = {};
   int i = 0;
   int j = 0;
   int k = 0;
        while  ((i < size) && (j < size)){
	        if(arr[i] <= arr1[j]){
		       arr2[k++] = arr[i];
		       i++;
		}
		else{ 
	            arr2[k++] = arr1[j];
		    j++;
		}
	}

	if(i == size)
           while (j < size)
                  arr2[k++] = arr1[j++] ;
	if (j == size)
	    while(i < size)
	          arr2[k++] = arr[j++];
   
    printf("Sorted  merged array is: ") ;
     for(int l = 0; l < 2 * size; l++){
        printf("%d ", arr2[l]);

    }
     printf("\n");

   

  
   return 0;
}
