#include <stdio.h>

int main(){
    char ch1 = 0;
    printf("Please input first character: ");
    scanf("%c", &ch1);
  
    char ch2 = 0;
    printf("Please input second character: ");
    scanf(" %c", &ch2);

    short sh  = 0;
    printf("Please input third number: ");
    scanf(" %hd", &sh );

    int a  = 0;

    char  *p = (char*)&a;
    *p = ch1;
    *(p + 1) = ch2;
    *((short*)(p + 2)) = sh;



    printf("%c\n", *p);
    printf("%c\n", *(p + 1));
    printf("%hd\n",*((short *)(p + 2)));





    return 0;
}

