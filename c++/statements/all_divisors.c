#include <stdio.h>

int main(){
    int num = 0;
    printf("Input your number: ");
    scanf("%d", &num);
    
    printf("%d's all divisiors are: ", num);
    for(int i = 1; i <=  num/2; i++){
       if (num % i == 0)
          printf("%d ", i);
       }
          printf("%d\n", num);


   return 0;
}
