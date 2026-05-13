#include <stdio.h>

int digits_sum(int num){
    int sum = 0;
    while(num){
          sum += num % 10;
	  num /=10;
    }
    return sum;
}

int main(){
   int num = 0;
   printf("PLease input your number: ");
   scanf("%d", &num);

   printf("%d's digits sum is %d\n",num, digits_sum(num));

   return 0;
}
