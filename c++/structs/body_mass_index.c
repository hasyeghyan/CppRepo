#include <stdio.h>

int main() {

   struct Person {
          float weight;
          float height;
   };

   struct Person p = {0,0};

   printf("Please input weight: ");
   scanf("%f",&p.weight);
   printf("PLease inout height: ");
   scanf("%f",&p.height);
   
   float mass = p.weight / (p.height * p.height);

   if(mass < 18.5) {
     printf("Underweight\n");
   }
   else if (mass <= 24.9){
           printf("Normal\n");
   }
   else {
        printf("Overweight\n");
   }
   return 0;
}

