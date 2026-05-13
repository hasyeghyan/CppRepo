#include <stdio.h>

int main() {
    
   struct Point {
          float x;
	  float y;
   };
   
   struct Point p1 = {0,0};
   struct Point p2 = {0,0};

   printf("Please input first point's x: ");
   scanf("%f",&p1.x);
   printf("PLease input first point's y: ");
   scanf("%f",&p1.y);
   
   printf("Please input second point's x: ");
   scanf("%f",&p2.x);
   printf("PLease input second point's y: ");
   scanf("%f",&p2.y);

   float temp = (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
   int i = 1;
   while(temp >= i * i){
         ++i;
   }

   printf("The distance is: %d\n", i - 1);



   return 0;
}
