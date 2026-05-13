#include <stdio.h>
#define n 5
int main(){

    int arr[n]= { 1, 5, 4, 2, 3};

    int arr1[n+1] = {};

    for (int i = 0; i <= n; i++ ) {
         arr1[arr[i]] = 1;
    }
     
    int a = 0;
    for(int i = 0; i <= n; i++){
        if(arr1[i] == 0)
           a = i;
    }

    printf("Missing number is %d\n", a);





   return  0;
}
   
