#include<stdio.h>

int main(){
    int a = 0, b = 0 ;
    scanf("%d%d", &a, &b);
    
    a = a + b;
    b = a - b;
    a = a - b;

    printf("%d\n", a);
    printf("%d\n", b);

    return 0;
}

