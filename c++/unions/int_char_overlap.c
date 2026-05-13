#include <stdio.h>

int main(){

   union Flag {
          int number;
          char flag;
   };

   union Flag f = {0};
   f.number = 65;
   printf("First byte is %d\n", f.flag);

   return 0;
}

