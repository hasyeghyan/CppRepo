#include <stdio.h>

int max(int arr[], int size){
    if(!size){
       return arr[size];
    }
      return  max(arr, size - 1) > arr[size - 1] ? max(arr, size - 1) : arr[size - 1];
}

int min(int arr[], int size){
    if(!size){
       return arr[size];
    }
      return  min(arr, size - 1) < arr[size - 1] ? min(arr, size - 1) : arr[size - 1];
}

int main(){
    const int size = 5;
    int arr[size] = {};
    printf("PLease input your array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
  }

        printf("Maximum element is %d\n",max(arr, size));
        printf("Minimum element is %d\n",min(arr, size));


    return 0;
}

