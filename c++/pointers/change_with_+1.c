#include <stdio.h>

int main(){
    int x = 10;
    int y = 15;
    int z = 2; 

    int *p = &x;
    *(p + 1) = 12;
    *(p + 2) = 14;
    
    printf("X is %d\n", *p);
    printf("Changed y is %d\n", *(p + 1));
    printf("Changed z is %d\n", *(p + 2));
   
   


    return 0;
}

