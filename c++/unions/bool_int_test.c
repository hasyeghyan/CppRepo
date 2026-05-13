#include <stdio.h>

int main(){
    
   union Flag {
          int number;
	  char flag;
   };
   
   union Flag f = {0};
   f.number = 65;
   printf("ASCII is %c\n", f.flag);   
   	
   return 0;
}

