#include <stdio.h>

int main(){
    int n = 0;
    printf("Please input your number: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
	    if(i == 0 || i == (n - 1)){ 
	       printf("%c", '*');
	       continue;
	    }
	    else if (j==0 || j == (n - 1)) {
	             printf("%c", '*');
	    }
	    else 
		    printf(" ");
	}
        printf("\n");
    }

   return 0;
}
