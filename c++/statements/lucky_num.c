#include <stdio.h>

int main(){

    int num  = 0;
    printf("Please input your number: ");
    scanf("%d", &num);
    int flag = 1;   
    
    int temp = num;
    while (temp != 0){
          int digit = temp % 10;
          if (digit != 4 && digit != 7) {
		flag = 0;	
		break;
	  }	
              temp /= 10;
    } 
          if (flag)
             printf("%d is lucky number\n", num);
          else 
             printf("%d is not lucky number\n", num);


   return 0;
}
