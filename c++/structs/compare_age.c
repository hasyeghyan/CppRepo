#include <stdio.h>

int main() {

   struct Person {
          float height;
          int age;
   };

   struct Person p1 = {0,0};
   struct Person p2 = {0,0};

   printf("Please input first peson's height: ");
   scanf("%f",&p1.height);
   printf("PLease input first person's age: ");
   scanf("%d",&p1.age);

   printf("Please input second person's height: ");
   scanf("%f",&p2.height);
   printf("PLease input second person's age: ");
   scanf("%d",&p2.age);
  
   if (p1.age > p2.age){
      printf("First person is older\n");
   }
   else{
      printf("Second person is older\n");
   }



   return 0;
}

