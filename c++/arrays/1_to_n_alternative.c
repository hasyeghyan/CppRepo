#include <stdio.h>
#define n 5
int main(){

    int arr[n]= { 5, 0, 4, 2, 3};
    
    int sum1 = 0;
    int sum = 0;

    for (int i = 0; i <= n; i++ ) {
         if(i == n)
	    sum1 +=i;
         else {
            sum1 += i;
	    sum += arr[i];
	 }
    }


    int missing = sum1 - sum;
    printf("Missing number is %d\n", missing);





   return  0;
}

