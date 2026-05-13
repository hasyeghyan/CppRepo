#include <stdio.h>

int main(){

   const int size = 7;
   char arr[size] ={};
   int check[26] = {};

   printf("Please input your array: ");
   for(int i = 0; i < size; i++){
       scanf(" %c", &arr[i]);
   }

   
   for(int i = 0; i < size; i++){
       if(!check[arr[i] - 97]){
	  check[arr[i] - 97] = 1;
          
       }
       else{
	  printf("First repeating character is %c\n", arr[i]);
	  return 0;
       }
           
   }
	 printf("No repeting charcters\n");



   return 0;
}

