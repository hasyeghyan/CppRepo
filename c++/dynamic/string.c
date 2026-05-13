#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void array(){
     char str[100];
     printf("Please input your string: ");
    
     fgets(str, sizeof(str), stdin);
     str[strcspn(str, "\n")] = '\0';
     
     int n = strlen(str);	
     char *p = (char *)malloc(n + 1);
     if(p == NULL){
       printf("Error: ");
     }
     strcpy(p,str);
     for(int i = 0; i < n; ++i){
        printf("%c", p[i]);
     }
     printf("\n");
     printf("%d\n", n);
     free(p);
}

int main(){
   array();
   return 0;
}

