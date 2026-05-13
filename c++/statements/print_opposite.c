#include<stdio.h>

int main(){
    int num = 0;
    scanf("%d", &num);
    
    if (num > 12){    
     while (num != 0){
        printf("%d", num % 10);
	num /= 10;
     }
     printf("\n");
   }
   
   else {
       printf("%d is invalid\n", num);
   }

    return 0;
}


