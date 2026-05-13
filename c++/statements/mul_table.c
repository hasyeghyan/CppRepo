#include<stdio.h>

int main(){
    unsigned int x  = 0;
    scanf("%u", &x);
  
    unsigned  int res = x;  
    unsigned int j = 0;
    for (int i = 0; i < 10; i++){
        res *= j;
	printf("%u * %u  =  %u\n", x, j, res);
	j++;
	res = x;
    }

    

    return 0;
}

