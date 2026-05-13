#include <stdio.h>
#include <stdlib.h>

int* array(int n){
     int *p = (int *)malloc(n * sizeof(int));
     if(p == NULL){
       printf("Error: ");
       return NULL;
     }
     printf("PLease input your array: ");
     for(int i = 0; i < n; ++i){
        scanf("%d", &p[i]);
     }
     printf("Inital array is: ");
     for(int i = 0; i < n; ++i){
        printf("%d ", p[i]);
     }
     printf("\n");

     int* p1 = realloc(p, 2 * n * sizeof(int));
     printf("PLease input extra elements: ");
     for(int i = n; i < 2 * n; ++i){
        scanf("%d", &p1[i]);
     }
     printf("Updated array is: ");
     for(int i = 0; i < 2 * n; ++i){
        printf("%d ", p1[i]);
     }
     printf("\n");

     return p1;
}

int main(){
   int n = 0;
   printf("Please input size: ");
   scanf("%d", &n);
   int *p1 = array(n);
   free(p1);
   return 0;
}

