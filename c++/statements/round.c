#include <stdio.h>

int main(){
    
    int num = 0;
    printf("Please input your number: ");
    scanf("%d", &num);
    
    int temp = num;
    int last_digit = num % 10;
    int res = num / 10;

    if (last_digit >= 5)
	num = (++res) * 10; 

    else 
        num = res * 10;
        
    printf("Rounded num is %d\n", num);

   return 0;
}
