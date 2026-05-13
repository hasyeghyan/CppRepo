#include<stdio.h>

int main(){
    int num  = 0;
    scanf("%d", &num);
    int opposite = 0;
    int temp = num;

    while (temp != 0){
        opposite = opposite * 10 +  temp % 10;
        temp /= 10;
     }
     
    if (num == opposite)
        printf("%d is polindrome\n", num);
    else 
        printf("%d is not  polindrome\n", num);
    


    return 0;
}


