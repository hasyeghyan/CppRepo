#include<stdio.h>

int main(){
    int num = 0;
    scanf("%d", &num);
    int sum  = 0;
    
    if (num > 0){
    while (num != 0){
        sum += num % 10;
        num /= 10;
     }  
}

    else {
        num = ~num +1;
	while (num != 0){
              sum += num % 10;
              num /= 10;
     }
}

    printf("Sum is %d\n", sum);
 

    return 0;
}

