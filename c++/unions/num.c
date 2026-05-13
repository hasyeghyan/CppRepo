#include <stdio.h>

int main() {

   union Number {
	  int intValue;
          float floatValue;
   };

   union Number n = {0};
  
   n.floatValue = 23;

   printf("intvalue is %f\n", n.floatValue);
   printf("floatValue is %d\n", n.intValue);

   return 0;
}

