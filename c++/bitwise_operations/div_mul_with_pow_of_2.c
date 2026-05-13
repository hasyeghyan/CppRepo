#include<stdio.h>

int main(){
    int num = 0;
    scanf("%d", &num);
   
    int n = 0;
    scanf("%d", &n);


    int res1 = num << n;
    printf("%d multplied by %dth power of two is equal to %d\n", num, n, res1 );

    int res2 = num >>  n;
    printf("%d divided by %dth power of two is equal to %d\n", num, n, res2 );

    return 0;
}
 
