#include<stdio.h>

int main(){
    int a = 0;
    scanf("%d", &a);

    int b = 0;
    scanf("%d", &b);
    
    int res1 = 34 | (1 << a);
    int res2 = 34 & ~(1 << b);

    printf("%d\n", res1);
    printf("%d\n", res2);

    return 0;
}


