#include<stdio.h>

int main(){
    float  x = 0;
    scanf("%f", &x);
    
    float y = 0;
    scanf("%f", &y);

    printf("%f\n", x * y + 21 * x / y -200);

    return 0;
}

