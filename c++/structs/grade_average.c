#include <stdio.h>

int main() {
    
   struct Student {
          float mathGrade;
	  float physicsGrade;
	  float chemistryGrade;
   };
   
   struct Student  s = {0,0,0};

   printf("Please input mathGrade: ");
   scanf("%f",&s.mathGrade);
   printf("PLease input physicsGrade: ");
   scanf("%f",&s.physicsGrade);
   printf("PLease input chemistryGrade: ");
   scanf("%f",&s.chemistryGrade);

   float average = (s.mathGrade + s.physicsGrade + s.chemistryGrade) / 3;
   printf("Average is %f\n", average);

   return 0;
}
