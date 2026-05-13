#include <stdio.h>
#define PI 3.14

int main() {

   struct Circle {
          float radius;
   };

   struct Circle c = {0};

   printf("Please input radius: ");
   scanf("%f",&c.radius);

   printf("Circle's circumferenceis %f\n", 2 * PI * c.radius);
   printf("Circle's area is %f\n", PI * c.radius * c.radius);
   return 0;
}

