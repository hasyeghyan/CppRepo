#include<stdio.h>

int main(){
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    
    int total = a + b + c;
    float average = total / 3;

    printf("%d\n", total);
    printf("%f\n", average);

    return 0;
}

