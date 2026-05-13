#include <stdio.h>

void print_array(int arr[], int size){
    if(!size){
       return;
    }
    print_array(arr, size - 1);
    printf("%d ", arr[size - 1]);
    

}

int main(){
    const int size = 5;
    int arr[size] = {};
    printf("PLease input your array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    print_array(arr, size);
    printf("\n");

    return 0;
}
