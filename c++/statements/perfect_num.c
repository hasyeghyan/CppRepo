#include <stdio.h>

int main(){
    
    int num  = 0;
    printf("Please input the number: ");
    scanf("%d", &num);
    
    int sum = 0;

    for (int i = 1; i <= num/2; ++i) {
         if(num % i == 0)
	    sum += i;
    }
        if (sum ==  num)
            printf("%d is perfect\n", num);
	else 
	    printf("%d is not perfect\n", num);


   return 0;
}
