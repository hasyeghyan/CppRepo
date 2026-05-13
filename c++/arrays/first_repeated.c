#include <stdio.h>

int main(){
    
   const int size = 7;
   char arr[size] ={};
   
   printf("Please input your array: ");
   for(int i = 0; i < size; i++){
       scanf(" %c", &arr[i]);
       if (arr[i] < 'a' || arr[i] > 'z')
	   return 0;
   }
   
   int current_index = 0;
   int index = size - 1;
   
   for(int i = 0; i < size; i++){
       for(int j = i + 1; j < size ; j++){
          if(arr[i] == arr[j]){
	     current_index  = j;
	     break;
	  }
      }
   
	  if (current_index && current_index < index)
	     index = current_index;
     
  }
   
   if (!current_index)
       printf("No repeating characters\n");
   else
       printf("First repeating character is %c\n", arr[index]);

   return 0;
}
