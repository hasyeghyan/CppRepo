#include <stdio.h>

int is_prime(int num){
    int flag = 0;
    if (num <= 1)
       return flag;
    for (int i = 2; i < num; i++){
	     if (num % i == 0)
                 return flag;
	}
        flag = 1;
        return flag;
}

int main(){
   int num = 0;
   printf("PLease input your number: ");
   scanf("%d", &num);
   
   if(is_prime(num))
      printf("%d is prime\n",num);
   else 
      printf("%d is not prime\n", num);

   return 0;
}

