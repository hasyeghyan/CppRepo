#include<stdio.h>

int main(){
    unsigned int x  = 0;
    scanf("%u", &x);
    unsigned int y = 0;
    scanf("%u", &y);
 
    unsigned  int res = 1;
    for (int i = 0; i < y; i++){
        res *= x;
    }
    
     printf("%u\n", res);

    return 0;
}


