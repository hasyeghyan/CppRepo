#include <stdio.h>

int main(){

   int num1 = 0;
   int num2 = 0;

   printf("Please input first number: ");
   scanf("%d", &num1);

   printf("Please input second number: ");
   scanf("%d", &num2);

   int flag = 0;
   int min = num1 < num2 ? num1 : num2;
   int gcd = 0;
   
   for(int i = 2; i <= min; ++i){
      if ((num1 % i == 0) && (num2 % i == 0)){
            gcd = i;      
      }
   }

    if(gcd)
       printf("%d's and %d's greatest common divisor is %d  \n",num1, num2, gcd);
    else
       printf("%d and %d are coprime \n", num1, num2);

   return 0;
}
