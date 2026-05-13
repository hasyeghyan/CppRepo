#include <stdio.h>
#define n 5
int main(){
    
    int arr[n]= {};

    printf("Please input your array: ");
            for (int i = 0; i < n ; i++){
                 scanf("%d", &arr[i]);
            }

    int temp = 0;

    for(int i = 0; i < n ; i++){
	 for (int j = i + 1; j < n; j++){
              if(!arr[i]){
                 if (arr[j]){
		     temp = arr[i];
		     arr[i] =arr[j];
		     arr[j] = temp;
		     temp = 0;
		     break;
		 }
              }
        }
  }
  
  printf("Result array is: ");
  for (int i = 0; i < n ; i++){
       printf("%d ", arr[i]);
  }
  printf("\n");


   return  0;
}


