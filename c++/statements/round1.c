#include <stdio.h>

int main(){

    int num = 0;
    printf("Please input your number: ");
    scanf("%d", &num);

    int last_digit = num % 10;
    

    if (last_digit >= 5)
        num += 10 - last_digit;

    else
        num -= last_digit;

    printf("Rounded num is %d\n", num);

   return 0;
}

