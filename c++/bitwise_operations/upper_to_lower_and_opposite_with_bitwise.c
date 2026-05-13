#include<stdio.h>

int main(){
    char num = 0;
    scanf("%c", &num);

    if ((num & 32) == 0){
       num |= (1 << 5);
       printf("%c\n", num);
    }
     else {
           num &=  ~(1 << 5);
           printf("%c\n", num);
    }


    
    return 0;
}

