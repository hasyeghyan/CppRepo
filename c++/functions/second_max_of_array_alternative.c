#include <stdio.h>

int second_max(int arr[], int size){
     int max = arr[0];
     int second = -2147483648;
     int temp = 0;
     for(int i = 1; i < size; i++){
         temp = max;
         max = arr[i] > max ? arr[i] : max;
	 if(max == arr[i])
            second = temp;
	 else
              if (arr[i] > second && arr[i] < max){
		     second = arr[i];		 
     }
     }

     return second;
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

