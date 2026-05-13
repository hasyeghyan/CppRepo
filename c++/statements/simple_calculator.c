#include<stdio.h>

int main(){
    int a = 0, b = 0;
    char c = 0;
    char quit = 0;
    do {
    scanf("%d", &a);
    scanf("%d", &b);
    scanf(" %c", &c);
    scanf(" %c", &quit);
    }while (quit != 'q'); 
  
    
    switch(c){
            case '+': {
                    int sum = a + b;
                    printf("%d\n", sum);
                    break;
                    }
            case '-': {
                    int dif = a - b;
                    printf("%d\n", dif);
                    break;
                     }
            case '*': {
                     int product = a * b;
                     printf("%d\n", product);
                     break;
                     }
            default: {
                     int quot = a / b;
                     printf("%d\n", quot);
  		     }
 
    }

    return 0;
}

