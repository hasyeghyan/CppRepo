#include<stdio.h>

int main(){
    int endpoint1 = 0;
    int endpoint2 = 0;
    int sum  = 0;

    scanf("%d", &endpoint1);
    scanf("%d", &endpoint2);
    
    for(int i = endpoint1; i <= endpoint2; i++){
        if (i % 2 == 0)
		sum += i;
     }

    printf("Sum is %d\n", sum);


    return 0;
}


