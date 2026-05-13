#include <stdio.h>

int fib(int n){
    if(n >= 0 && n < 2)
       return n;
    return fib(n - 1) + fib(n - 2);
}

int main(){
    int n = 0;
    printf("PLease input your number: ");
    scanf("%d", &n);

    printf("%dth fibonachi element is %d\n", n, fib(n));

    return 0;
}
