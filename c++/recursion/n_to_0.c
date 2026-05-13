#include <stdio.h>

void n_to_0(int n){
    if(!n){
       printf("%d", n);
       return;
    }
    printf("%d ", n);
    n_to_0(n - 1);
}

int main(){
    int n = 0;
    printf("PLease input your number: ");
    scanf("%d", &n);

    n_to_0(n);
    printf("\n");

    return 0;
}

