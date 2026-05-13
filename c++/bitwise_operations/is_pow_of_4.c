#include<stdio.h>

int main(){
    int num = 0;
    scanf("%d", &num);

    int a = 1;
    int i = 0;
    for( i = 0; i < 32; i += 2) {
        if( num == a ){
           printf("%d is pow of 4\n", num);
           break;
    }
        a <<= 2;
 }

    if (i == 32)
            printf("%d is not pow of 4\n", num);


    return 0;
}
  
