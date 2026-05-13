#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* custom_realloc(void *ptr, size_t new_size){
     if(ptr == NULL){
       printf("Error: ");
       return NULL;
     }
     if(new_size == 0){
       free(ptr);
       return NULL;
     }
     void *new_ptr = malloc(new_size);
     memcpy(new_ptr, ptr, new_size);

     return new_ptr;
}

int main(){
   int n = 0;
   printf("Please input size: ");
   scanf("%d", &n);

   int *p = (int *)malloc(n * sizeof(int));
   printf("Please input your initial array: ");
   for(int i = 0; i < n; ++i){
      scanf("%d", &p[i]);
   }

   int *p1 = custom_realloc(p,2 * n * sizeof(int));
   for(int i = n; i < 2 * n; ++i){
      p1[i] = 3;
   }

   printf("Updated array is: ");
   for(int i = 0; i < 2 * n; ++i){
      printf("%d ", p1[i]);
   }
   printf("\n");
   free(p);
   free(p1);
   return 0;
}
