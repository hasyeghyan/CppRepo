#include <stdio.h>

int main(){

    const int n = 3;
    int matrix[n][n]={};
    
    const int size = n;
    int arr[size] = {};

    printf("Input your array elements: ");
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
        	scanf("%d", &matrix[i][j]);
    }

    for (int i = 0; i < n; i++){
         arr[i] = matrix[i][i];
     }
     
    for (int i = 0; i < size; i++){
         printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

