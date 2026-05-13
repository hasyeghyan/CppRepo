#include<stdio.h>

int main(){
    int num = 0;
    int n = 0;
    scanf("%d", &num);
    scanf("%d", &n);

    num |= (1 << n);
    printf("%d\n", num);


   return 0;
}
