#include <stdio.h>

int main(){
    int x = 10;
    char c = 'a';
    float f = 3.14;

    int *ptr1 = &x;
    char *ptr2 = &c;
    float *ptr3 = &f;

    printf("%p\n", ptr1);
    printf("%p\n", ptr2);
    printf("%p\n", ptr3);
    
	
	return 0;
}
