#include <stdio.h>

#define MAX_QUESTIONS 5
#define MAX_TEXT_LEN 100
#define MAX_OPTION_LEN 50

extern char questions[][MAX_TEXT_LEN];
extern char optionsA[][MAX_OPTION_LEN];
extern char optionsB[][MAX_OPTION_LEN];
extern char optionsC[][MAX_OPTION_LEN];
extern char optionsD[][MAX_OPTION_LEN];
extern char correctAnswers[];

int correct = 0;
int wrong = 0;

int getCorrect(){
    return ++correct;
}

int getWrong(){
    return ++wrong;
}

void playQuiz(int totalQuestions){
     for(int i = 0; i < MAX_QUESTIONS; ++i){
         printf("%s\n", questions[i]);
	 printf("A) %s\n", optionsA[i]);
	 printf("B) %s\n", optionsB[i]);
	 printf("C) %s\n", optionsC[i]);
         printf("D) %s\n", optionsD[i]);
         
	 printf("Your answer: ");
	 char answer = 0;
	 scanf(" %c", &answer);
	 while(1){
	       if(!((answer >= 'A' && answer <= 'D') || (answer >= 'a' && answer <= 'd'))){
                  printf("Your answer is invalid, input another option: ");
                  scanf(" %c", &answer);
	          continue;	  
               }

	       if((answer == correctAnswers[i]) || (answer == correctAnswers[i] + 32)){
                  printf("Correct! \n");
                  getCorrect();
                  break;		  
	       }

	       else {
	          printf("Wrong! Correct answer: %c\n", correctAnswers[i]);
		  getWrong();
		  break;
	       }
	 }
	 printf("\n");
     }
     
     if(getCorrect()  > 2){
        printf("%d correct answers. \n", getCorrect() - 2);
     }
     else 
        printf("%d correct answer. \n", getCorrect() - 2);

     if(getWrong()  > 2){
        printf("%d wrong answers. \n", getWrong() - 2);
     }
     else
        printf("%d wrong answer. \n", getWrong() - 2);
}
