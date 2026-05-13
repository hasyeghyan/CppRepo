#include <stdio.h>

int main(){

    const int size = 5;
    int arr[size]={};
    
    printf("Please input your array: ");
     for (int i = 0; i < size ; i++){
          scanf("%d", &arr[i]);
     }
    
    int flag = 1;
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i+1]){
	   flag = 0;
           break;
	}
    }
    
    if (flag)
	printf("True\n");
    else
	printf("False\n");
    
    return 0;
}

