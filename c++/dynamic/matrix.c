#include <stdio.h>
#include <stdlib.h>

int** array(int n, int m){
     int **p = (int **)malloc(n * sizeof(int*));
     if(p == NULL){
       printf("Error: ");
       return NULL;
     }
     for(int i = 0; i < n; ++i){
        p[i] = (int *)malloc(m * sizeof(int));
        if(p[i] == NULL){
          printf("Error: ");
          return NULL;
        }
     }
     printf("PLease input your matrix: ");
     for(int i = 0; i < n; ++i){
	for(int j = 0; j < m; ++j){
           scanf("%d", &p[i][j]);
	}
     }
     for(int i = 0; i < n; ++i){
	for(int j = 0; j < m;++j){
           printf("%d " , p[i][j]);
	}
	printf("\n");
     }
 
     return p;
}

int main(){
   int n = 0;
   printf("Please input raw size: ");
   scanf("%d", &n);

   int m = 0;
   printf("Please input column size: ");
   scanf("%d", &m);

   int **p = array(n,m);
   free(p);
   return 0;
}

