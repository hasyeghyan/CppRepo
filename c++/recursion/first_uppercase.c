#include <stdio.h>

int uppercase(char arr[], int size){
    if(!size){
       return -1;
    }

    if(*arr >= 'A' && *arr <= 'Z'){
       return *arr;
    }
    else 
      return  uppercase(arr + 1,size - 1);
  
     
     
}

int main(){
    const int size = 5;
    char arr[size] = {};
    printf("PLease input your array: ");
    for(int i = 0; i < size; i++){
        scanf("%c", &arr[i]);
    }
    
    
    if(uppercase (arr,size) == -1)
	printf("All lowercases.\n");
    else
        printf("First uppercase is %c\n",uppercase(arr, size));
        

    return 0;
}

