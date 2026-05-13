#include<stdio.h>

int main(){
    int a = 0;
    scanf("%d", &a);

    int b = 0;
    scanf("%d", &b);

    a = a ^ b ;
    b = a ^ b;
    a = a ^ b;

    printf("%d\n", a);
    printf("%d\n", b);

    return 0;
}

