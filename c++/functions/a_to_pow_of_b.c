#include <stdio.h>

int degree(int a, int b){
    int res = 1;
    for(int i = 1; i <= b; i++)
	res *= a;
        return res;
}

int main(){
   int a = 0;
   printf("PLease input your first number: ");
   scanf("%d", &a);
   
   int b = 0;
   printf("Please input your second number: ");
   scanf("%d", &b);

   printf("%d's pow of %d is %d\n", a, b, degree(a, b));

   return 0;
}
