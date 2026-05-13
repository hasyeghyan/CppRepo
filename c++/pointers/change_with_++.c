#include <stdio.h>

int main(){
    int x = 10;
    int y = 15;
    int z = 2;
    
    int *p = &x;
    *(++p) = 20;
    *(++p) = 21;
   
   printf("X is %d\n", x);
   printf("Changed y is %d\n", y);
   printf("Changed z is %d\n", z);

   return 0;
 }

