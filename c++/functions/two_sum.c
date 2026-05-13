#include <stdio.h>

int* two_sum(int arr[], int size, int target){ 
    int count = 0;
    int index_i = 0;
    int index_j = 0;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
	    if((arr[i] + arr[j]) == target){
		count++;
	    }
	}
    } 
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if((arr[i] + arr[j]) == target){
                index_i = i;
		index_j = j;
		if(count == 1){
		   arr[0] = index_i;
		   arr[1] = index_j;
		   return arr;
		}
            }
        }
    }
    arr[0] = -1;
    arr[1] = -1;
    return arr;
}

int main(){
   const int size = 5;
   int arr[size] = {};

   printf("Please input your array: ");
   for(int i = 0; i < size; i++)
       scanf("%d", &arr[i]);

   int number = 0;
   printf("Please input your number: ");
   scanf("%d", &number);

   two_sum(arr, size, number);
       if(arr[0] == -1)
	  printf("Invalid array\n");
       else
	  printf("Two indexes are %d and %d\n ", arr[0], arr[1]);
  
   
  
   return 0;
}
