#include <stdio.h>

int main() {
    
   struct Rectangle{
          int length;
	  int width;
   };
   
   struct Rectangle r = {0,0};

   printf("Please input length: ");
   scanf("%d",&r.length);
   printf("PLease inout width: ");
   scanf("%d",&r.width);

   printf("Rectangle's area is %d\n", r.width * r.length);
   printf("Rectangles perimeter is %d\n", 2 * (r.width + r.length));
   return 0;
}
