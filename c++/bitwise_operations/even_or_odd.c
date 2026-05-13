#include<stdio.h>

int main(){
    int num = 0;
    scanf("%d", &num);

    int res =  num &  1;
    if(res == 0)
	    printf("%d is even\n", num);
    else 
	    printf("%d is odd\n", num);

   return 0;
}
