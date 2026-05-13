#include<stdio.h>

int main(){
    int a = 0;
    scanf("%d", &a);

    int b = 0;
    scanf("%d", &b);
    
    int res1 = a << 1;
    int res2 = b >> 1;

    printf("%d\n", res1);
    printf("%d\n", res2);
    
    return 0;
}

