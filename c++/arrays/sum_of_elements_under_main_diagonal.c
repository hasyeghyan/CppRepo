#include <stdio.h>

int main(){

    const int n = 3;
    int matrix[n][n]={};

    printf("Input your array elements: ");
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
                scanf("%d", &matrix[i][j]);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++){
	 for(int j = 0; j < i; j++)
             sum += matrix[i][j];
     }

         printf("Sum is %d\n", sum);
   

    return 0;
}

