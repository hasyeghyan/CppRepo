#include<stdio.h>

int main(){
    int score = 0;
    scanf("%d", &score);
    
    if (score >= 0 && score <= 100){
    int passd = (score >= 50);
    if(passd){

       printf("%d is enough\n", score);
    }
    
}


    return 0;
}

