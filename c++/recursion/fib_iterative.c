#include <stdio.h>

int fib(int n){
    int a = 0;
    int b = 1;
    int res = 0;

    for(int i = 0; i < n - 1; i++){
        res = a + b;
	a = b;
	b = res;
    }
    return res;
}

int main(){
    int n = 0;
    printf("PLease input your number: ");
    scanf("%d", &n);

    printf("%dth fibonachi element is %d\n", n, fib(n));

    return 0;
}

