#include<stdio.h>

int main(){
    int num = 0;
    scanf("%d", &num);
      
    int is_even = ((num % 2) == 0); 
    if(is_even){
       
       printf("%d is even\n", num);
    }

 

    return 0;
}

