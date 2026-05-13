#include <stdio.h>

int main() {

   union Currency {
	  float usd;
          float euro;
   };

   union Currency c = {0};
  
   c.usd = 100;
   c.euro = 200;
 
   printf("Usd is %f\n", c.usd);
   printf("Euro is %f\n", c.euro);

   return 0;
}

