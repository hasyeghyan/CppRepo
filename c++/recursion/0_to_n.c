#include <stdio.h>

void to_n(int n){  
    if(!n){
       printf("%d ", n);
       return;
    }
    to_n(n - 1);
    printf("%d ", n);

}

int main(){
    int n = 0;
    printf("PLease input your number: ");
    scanf("%d", &n);

    to_n(n);
    printf("\n");

    return 0;
}


