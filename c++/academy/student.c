#include <stdio.h>
#include "student.h"
#include <string.h>

void addStudent(Student *s) {
     printf("Please input name: ");
     scanf(" %[^\n]", s->name);


     
     printf("Please input id: ");
     scanf("%d", &s->id);
     
     printf("Please input language track: ");
     int track = 0;
     scanf("%d", &track);
     while(1) {
          switch(track){
                  case CPP: 
                    s->language = CPP;
                    break;
                  case WEB:
                    s->language = WEB;
                    break;
                  case AI:
                    s->language = AI;
                    break;
                  case DevHack:
                    s->language = DevHack;
                    break;
                  default:
                    printf("Invalid input try again: ");
                    scanf("%d", &track);
		    continue;
         }
	 break;
     }
     printf("Please input phase: ");
     int ph = 0;
     scanf("%d", &ph);
     while(1) {
	  if(ph >= 0 && ph <= 2)
            break;
	  else {
	     printf("Invalid input try again: ");
             scanf("%d", &ph);
	  }
     }
     switch(ph){
                  case COMPUTER_SCIENCE:
                    s->phase = COMPUTER_SCIENCE;
                    break;
		  case CORE_LANGUAGE:
                    s->phase = CORE_LANGUAGE;
                    break;
                  case SPECIALITIES:
                    s->phase = SPECIALITIES;
                    break;
     }
     
}

void inputMonthlyExams(Student *s){
     printf("Please input exam scores: ");
     for(int i = 0; i < size1; ++i){
         scanf("%d",&s->monthExams[i]); 
	 while(1){
	      if(s->monthExams[i] > 100 || s->monthExams[i] <= 0){
		printf("Invalid input try again: ");
	        scanf("%d",&s->monthExams[i]);
              }
	      else {
		   if(i != size1 - 1)
	              printf("Input next score: ");
		    break;
	      }
	 }
     } 
     printf("\n");    
}

void calculateTotal(Student *s){
     s->totalScore = s->monthExams[0] * 0.1 + s->monthExams[1] * 0.1 + s->monthExams[2] * 0.8;
}

void check(Student *s){
     if(s->totalScore >= 80)
        s->passed = 1;
     else
        s->passed = 0;
} 

void PrintStudentReport(Student *s){
     printf("Name is ");
     puts(s->name);

     printf("Id is %d\n", s->id);

     printf("Language is ");
     switch(s->language){
                  case CPP:
                    printf("CPP\n");
                    break;
                  case WEB:
                    printf("WEB\n");
                    break;
                  case AI:
                    printf("AI\n");
                    break;
                  case DevHack:
                    printf("DevHack\n");
                    break;
     }

     printf("Phase is ");
     switch(s->phase){
                  case COMPUTER_SCIENCE:
                    printf("COMPUTER_SCIENCE\n");
                    break;
                  case CORE_LANGUAGE:
                    printf("CORE_LANGUAGE\n");
                    break;
                  case SPECIALITIES:
                    printf("SPECIALITIES\n");
                    break;
     }
     
     printf("Exam scores are ");
     for(int i = 0; i < size1; ++i){
        printf("%d ", s->monthExams[i]);
     }
     printf("\n");

     printf("Total score is %f\n", s->totalScore);
     if(s->passed){
       printf("Student passed\n");
     }
     else 
       printf("Student failed\n");
     printf("\n");
}

int minScoreForThirdMonth(int month1, int month2){
    if((month1 > 100 ||  month1 < 0) || (month2 > 100 || month2 < 0))
       return -1;
    else{
       float a = month1 * 10 / 100;
       float b = month1 * 10 / 100;
       return (80 - (a + b)) * 100 / 80;
    }
}

void passedStudents(Student academy[], int size2){
     printf("Passed students are:\n");
     int flag = 0;
     for(int i = 0; i < size2; ++i){
        if(academy[i].passed){
	  puts(academy[i].name);
	  flag = 1;
	}
     }
     if(!flag)
       printf("All failed\n");
}
