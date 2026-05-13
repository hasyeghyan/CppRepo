#include<stdio.h>

int main(){
    int a = 0, b =0, c = 0;

    printf("Please input first number: ");
    scanf("%d", &a);

    printf("Please input second number: ");
    scanf("%d", &b);

    printf("Please input third number: ");
    scanf("%d", &c);

    if (a > b) {
       if (a > c ){
           if(b > c)
              printf ("Numbers in increasing order: %d %d %d\n", c, b, a);
	   else 
              printf ("Numbers in increasing order: %d %d %d\n", b, c, a);
       }
       else 
            printf ("Numbers in increasing order: %d %d %d\n", b, a, c);
    }
      else {
            if (b > c) {
                 if(a > c)
                    printf ("Numbers in increasing order: %d %d %d\n", c, a, b );
                 else
                    printf ("Numbers in increasing order: %d %d %d\n", a, c, b);
            }
                else 
                  printf ("Numbers in increasing order: %d %d %d\n", a, b, c);
    }

  return 0;
}
