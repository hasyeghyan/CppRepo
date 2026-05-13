#include <stdio.h>

int main(){
    int a = 1;
   
    char *p = (char*)&a;
    
    if (*p == 1)
         printf("The system is little endian\n");
    else 
	  printf("The system is big endian\n");
   





    return 0;
}

