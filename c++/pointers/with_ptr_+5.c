#include <stdio.h>

int main(){
    int a = 0;
    int b = 0;
    int c = 0;

    int *p = &a;
    *p = 10;
    *(p + 1) = 20;
    *(p + 2) = 30;

    *p += 5;
    *(p + 1) += 5;
    *(p + 2) += 5;



    printf("X is %d\n", *p);
    printf("Changed y is %d\n", *(p + 1));
    printf("Changed z is %d\n", *(p + 2));





    return 0;
}

