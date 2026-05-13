#include <stdio.h>
#include "student.h"

int main() {
    const int n = 2;
    Student academy[n];
    for(int i = 0; i < n; ++i){
     
       addStudent(&academy[i]);
       inputMonthlyExams(&academy[i]);
       calculateTotal(&academy[i]);
       check(&academy[i]); 
    }
    for(int i = 0; i < n; ++i){
       PrintStudentReport(&academy[i]);
    }

    float a = 10;
    float b = 20;
    int res = minScoreForThirdMonth(a,b);
    if(res != -1)
       printf("Minimum score to pass is %d\n", res);
    else {
       printf("Invalid input\n");

    }

    passedStudents(academy, n);

    return 0;
}
