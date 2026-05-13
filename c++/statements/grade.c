#include<stdio.h>

int main(){
    int grade = 0;
    scanf("%d", &grade);

    if (grade >= 90 && grade <= 100)
	    printf("Grade is A\n");
    else if (grade >= 80 && grade <= 89)
            printf("Grade is B\n");
    else if (grade >= 70 && grade <= 79)
            printf("Grade is C\n");
    else if (grade >= 60 && grade <= 69)
            printf("Grade is D\n");
    else if (grade <= 60)
	    printf("Grade is E\n");

  return 0;
}
