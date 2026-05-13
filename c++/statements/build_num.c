#include <stdio.h>

int main(){
     
    int digit1 = 0;
    int digit2 = 0;
    int digit3 = 0;

    printf("Please input first digit: ");
    scanf("%d", &digit1);

    printf("Please input second digit: ");
    scanf("%d", &digit2);

    printf("Please input third digit: ");
    scanf("%d", &digit3);

    int res = digit1;
    res = res * 10 + digit2; 
    res =  res * 10 + digit3;

    printf ("Your result is: %d\n", res);



   return 0;
}
