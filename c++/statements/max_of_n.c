#include <stdio.h>

int main(){
    int num = 0;
    int max  = -1;

    while(1) {
	  printf("Input the number: ");
	  scanf("%d", &num);
	  if(num == -1){
	     if (max == -1)
                 return 0;	   
	     else {
		 printf("The maximum of numbers is %d\n", max) ;
	         return 0;
             }
	  }

	  max = num > max ? num : max;
   }  

   return 0;
}

