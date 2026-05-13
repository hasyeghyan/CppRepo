#include <stdio.h>

int main() {

   struct Temperature {
          float celsius;
	  float fahrenheit;
   };

   struct Temperature t = {0,0};

   printf("Please input clesius: ");
   scanf("%f",&t.celsius);
   
   t.fahrenheit = t.celsius * 9 /5 + 32;

   printf("Celsisu is %f\n", t.celsius);
   printf("Fahrenheit is  %f\n", t.fahrenheit);
   return 0;
}

