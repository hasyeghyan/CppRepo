#include<stdio.h>

int main(){
    int temp  =0;
    scanf("%d", &temp);

    int cold_temp = (temp < 15);
    if(cold_temp){

       printf("%d is cold\n", temp);
    }


    else{
           printf("%d is not cold\n", temp);
    }

    return 0;
}
