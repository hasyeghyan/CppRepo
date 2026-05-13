#include <stdio.h>

int main(){

    const int n = 3;
    const int m = 2;
    int arr[n][m]={};

    printf("Input your array elements: ");
    for(int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
              scanf("%d", &arr[i][j]);

    int max = arr[0][0];
    int max_row_index = 0;
    int max_col_index = 0;
    for (int i = 0; i < n; i++){
         for(int j = 0; j < m; j++ ){
             max = arr[i][j] > max ? arr[i][j] : max;
	     if(arr[i][j] == max){
		max_row_index = i;
	        max_col_index = j;
             }
	 }
     }

    printf("Max element is %d\n", max);
    printf("Max element's row index  is %d\n", max_row_index);
    printf("Max element's column  index  is %d\n", max_col_index);
    return 0;
}


