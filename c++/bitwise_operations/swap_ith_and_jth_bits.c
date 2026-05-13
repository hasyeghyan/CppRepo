#include<stdio.h>

int main(){
    int num = 0;
    int i = 0;
    int j = 0;
    scanf("%d", &num);
    scanf("%d%d", &i, &j);
    
    int ith_bit = num & (1 << i);
    int jth_bit = num & (1 << j);
     
    if (ith_bit == 0)
	    num = num & ~(1 << j);
    else  
            num = num | (1 << j);

    if (jth_bit == 0)
            num = num & ~(1 << i);
    else
            num = num | (1 << i);

    
    printf("%d\n", num);


   return 0;
}
    
