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
     for(int i = 0; i < n; ++i){
        printf("%d ", p[i]);
     }
     printf("\n");
     return p;
}

int main(){
   int n = 0;
   printf("Please input size: ");
   scanf("%d", &n);
   int *p = array(n);
   free(p);
   return 0;
}
