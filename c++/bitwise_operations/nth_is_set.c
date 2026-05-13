#include<stdio.h>

int main(){
    int num = 0;
    int n = 0;
    scanf("%d", &num);
    scanf("%d", &n);

    int res = num |  (1 << n);
    if(res == num)
       printf("%d's %dth bit is set\n", num, n);
    else
       printf("%d's %dth bit isn't set\n", num ,n);


   return 0;
}

