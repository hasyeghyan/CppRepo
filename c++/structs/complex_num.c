#include <stdio.h>


int main() {
    
   struct Complex {
          float real;
	  float imag;
   };
   
   struct Complex c1 = {0,0};
   struct Complex c2 = {0,0};

   printf("Please input first number's real part: ");
   scanf("%f",&c1.real);
   printf("PLease input first number's imaginary part: ");
   scanf("%f",&c1.imag);
   
   printf("Please input second number's real part: ");
   scanf("%f",&c2.real);
   printf("PLease input second number's imaginary part: ");
   scanf("%f",&c2.imag);

   float real_sum = c1.real + c2.real;
   float imag_sum = c1.imag + c2.imag;

   float temp1 = (c1.real * c2.real) - (c1.imag * c2.imag);
   float temp2 = (c1.real * c2.imag) + (c1.imag * c2.real);

   printf("The sum is: ");
   printf("%f", real_sum);
   printf("%c", '+');
   printf("%f", imag_sum);
   printf("%c\n", 'i');

   printf("The product is %f %c %f%c\n", temp1, '+', temp2,'i');



   return 0;
}
