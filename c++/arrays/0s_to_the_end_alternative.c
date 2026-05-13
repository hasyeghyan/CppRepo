#include <stdio.h>
#define n 5
int main(){

    int arr[n]= {};

    printf("Please input your array: ");
            for (int i = 0; i < n ; i++){
                 scanf("%d", &arr[i]);
            }

    int temp = 0;
    int j = 0;
    for(int i = 0; i < n ; i++){
        if (arr[i]){
            arr[j] = arr[i];
	    arr[i] = 0;
	    j++;	    
	}
    }

  printf("Result array is: ");
  for (int i = 0; i < n ; i++){
       printf("%d ", arr[i]);
  }
  printf("\n");


   return  0;
}


