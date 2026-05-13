#include <stdio.h>

int main() {

   union Value {
	  int intValue;
          float floatValue;
   };

   union Value v = {0};
   printf("Input float: ");
   scanf("%f", &v.floatValue);
   
   printf("Integer is %d\n", v.intValue);

   return 0;
}

