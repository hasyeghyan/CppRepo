#include<stdio.h>

int main(){
    int num = 0;
    printf("Please input your number: ");
    scanf("%d", &num);
    
    int min = 9;
    int digit = 0;
    int temp = num;

    while (temp) {
           digit  = temp % 10;
           min = digit < min ? digit : min;
           temp /= 10;
         }

    printf("Minimum digit is %d\n", min);

    return 0;
}

