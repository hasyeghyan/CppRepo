#include <stdio.h>

#define MAX_QUESTIONS 5
#define MAX_TEXT_LEN 100
#define MAX_OPTION_LEN 50

extern void playQuiz(int totalQuestions);

int main(){
    printf("Quiz Menu: \n");
    printf("1) Play Quiz\n");
    printf("2) Exit\n");
    printf("Enter choice: ");
    
    int choice = 0;
    scanf("%d", &choice);

    while(1){
          if(choice == 1){
             playQuiz(MAX_QUESTIONS);
	     break;
         }

	  if(choice == 2){
	    return 0;
	  }

	  if(choice < 1 || choice > 2){
	    printf("Invalid choice, input again: ");
	    scanf("%d", &choice); 
	  }
   }
    
   
   return 0;
}
