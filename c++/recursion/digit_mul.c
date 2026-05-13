#include <stdio.h>

int mul(int n){
    if(!n)
       return 1;
    return mul(n / 10) * (n % 10);
}

int main(){
    int n = 0;
    printf("PLease input your number: ");
    scanf("%d", &n);

    printf("%d's digits product is  %d\n", n, mul(n));

    return 0;
}
