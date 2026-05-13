#include <stdio.h>
#include <stdlib.h>

float* array(int n){
     float* p = (float *)calloc(n ,sizeof(float));
     if(p == NULL){
       printf("Error: ");
       return NULL;
     }
     printf("PLease input your array: ");
     for(int i = 0; i < n; ++i){
        scanf("%f", &p[i]);
     }
     for(int i = 0; i < n; ++i){
        printf("%f ", p[i]);
     }
     printf("\n");
     return p;
}

int main(){
   int n = 0;
   printf("Please input size: ");
   scanf("%d", &n);
   float *p = array(n);
   free(p);
   return 0;
}
