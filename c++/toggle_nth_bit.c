#include<stdio.h>

int main(){
    int a = 0;
    scanf("%d", &a);
    
    printf("%d", 34 ^ (1 << a));
    return 0;
}
