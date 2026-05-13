#include <stdio.h>
#include "functions.h"

int main() {

   union Measurement {
          int lenght;
          float weight;
   };

   union Measurement m = {0};
   
   printf("Choose which one to enter: weight or lenght: ");
   char temp[10] = {};
   scanf("%s", temp);

   while(1){
        if(strcmp(temp,"weight") == 0){
             printf("Input weight: ");
             scanf("%f", &m.weight);
             printf("Weight is %f\n", m.weight);
	     return 0;
          }
          else if (strcmp(temp, "lenght") == 0){
            printf("Input lenght: ");
	    scanf("%d", &m.lenght);
	    printf("Lenght is %d\n", m.lenght);
	    return 0;
         }  
       printf("Invalid input,try again:");
       scanf("%s", temp);
  }
   
}

