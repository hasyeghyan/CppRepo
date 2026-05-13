#include <stdio.h>

int main(){

    const int size = 5;
    int arr[size]={};

    printf("Input your array elements: ");
    for(int i = 0; i < size; ++i)
       scanf("%d", &arr[i]);

    int i = 0;
    int j = 0;
    int temp = 0;

    while(i != size){
          if ((arr[i] %2) == 0){
	      temp = arr[i];
	      arr[i] = arr[j];
	      arr[j] = temp;
	      i++;
	      j++;
	  }
	  else 
	      i++;
    }
    
    printf("Swapped array is ");

    for(int k = 0; k < size; k++){
        printf("%d ", arr[k]);
    
    }
    printf("\n");





   return  0;
}

