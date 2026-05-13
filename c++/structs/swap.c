#include <stdio.h>


int main() {
    
   struct Pair {
          int a;
	  int b;
   };
   
   struct Pair p1 = {0,0};
   struct Pair temp = {0,0};

   printf("Please input first number: ");
   scanf("%d",&p1.a);
   printf("PLease input second number: ");
   scanf("%d",&p1.b);
   
   temp = p1;
   p1.a = p1.b;
   p1.b = temp.a;

   printf("The swapped numbers are %d and %d\n", p1.a,p1.b);



   return 0;
}
