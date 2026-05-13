#include<stdio.h>

int main(){
    int a = 0, b =0, c = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a > b) {
       if (a > c){
          printf("%d is maximum\n", a);
       }
       else {
          printf("%d is maximum\n", c);
       }
    }
  
    else {
       if (b > c) {
          printf("%d is maximum\n", b);
       }
       else {
          printf("%d is maximum\n", c);
       }
   }

  return 0;
}
    
                                                                                                                                                                                               
