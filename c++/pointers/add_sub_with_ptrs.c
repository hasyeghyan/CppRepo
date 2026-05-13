#include <stdio.h>

int main(){
    int num1 = 10;
    int num2 = 15;

    int *ptr1 = &num1;
    int *ptr2 = &num2;
    
    int sum = *ptr1 + *ptr2;
    int sub = *ptr1 - *ptr2;

    printf("Sum is %d\n", sum);
    printf("Sub is %d\n", sub);


    return 0;
}

