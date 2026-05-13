#include <stdio.h>

int sum(int n){
    if(!n)
       return 0;
    return sum(n / 10) + (n % 10);
}

int main(){
    int n = 0;
    printf("PLease input your number: ");
    scanf("%d", &n);

    printf("%d's digits sum is  %d\n", n, sum(n));

    return 0;
}

