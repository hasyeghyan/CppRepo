#include<stdio.h>

int main(){
    unsigned int num  = 0;
    scanf("%u", &num);
   
    int i = 0;
    for ( i = 2; i <= num/2 ; i++){
        if (num % i == 0 ){
	   printf("%u is not prime\n", num);
	   break;
	}
    }
    if (i == num/2 + 1)
       printf("%u is prime\n", num);
    


    return 0;
}


