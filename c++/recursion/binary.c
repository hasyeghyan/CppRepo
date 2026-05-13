#include <stdio.h>

void binary(int n){
    if(!n){
       printf("%d", 0);
       return;
    }
    binary(n / 2 );
    printf("%d", n % 2);
    
}

int main(){
    int n = 0;
    printf("PLease input your number: ");
    scanf("%d", &n);

    printf("%d's binary form is ", n);
    binary(n);
    printf("\n");

    return 0;
}

