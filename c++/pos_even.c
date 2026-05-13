#include<stdio.h>

int main(){
    int num = 0;
    scanf("%d", &num);

    int is_positive_and_even = (num > 0 && ((num % 2) == 0));
    if(is_positive_and_even){

       printf("%d is positive and even\n", num);
    }




    return 0;
}

