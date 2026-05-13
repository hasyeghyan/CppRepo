#include<stdio.h>

int main(){
    int age  =0;
    scanf("%d", &age);
    
    int can_vote = (age >= 18);
    if(can_vote){
       
       printf("You are able to vote\n");
    }


    else{
           printf("You are unable to vote\n");
    }

    return 0;
}
