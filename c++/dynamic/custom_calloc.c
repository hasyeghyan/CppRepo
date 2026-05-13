#include <stdio.h>
#include <stdlib.h>

void* custom_calloc(size_t num, size_t size){
     int *p = (int *)malloc(num * size);
     if(p == NULL){
       printf("Error: ");
       return NULL;
     }
     for(int i = 0; i < num; ++i){
        p[i] = 0;
     }
     for(int i = 0; i < num ; ++i){
        printf("%d ", p[i]);
     }
     printf("\n");

     return p;
}

int main(){
   int n = 0;
   printf("Please input size: ");
   scanf("%d", &n);
   int *p = custom_calloc(n, sizeof(int));
   free(p);
   return 0;
}

