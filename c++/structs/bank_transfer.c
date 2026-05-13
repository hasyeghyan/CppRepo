#include <stdio.h>

int main() {
    
   struct Account {
          float balance;
	  int ownerId;
   };
   
   struct Account a1 = {0,0};
   struct Account a2 = {0,0};

   printf("Please input first account's balance: ");
   scanf("%f",&a1.balance);
   printf("PLease input first account's ownerld: ");
   scanf("%d",&a1.ownerId);
   
   printf("Please input second account's balance: ");
   scanf("%f",&a2.balance);
   printf("PLease input second account's ownerld: ");
   scanf("%d",&a2.ownerId);

   printf("First accoutn's balance before transfer: %f\n" ,a1.balance);
   printf("Second accoutn's balance before transfer: %f\n" ,a2.balance);

   int temp = a1.balance * 20 / 100;
   a1.balance -= temp;
   a2.balance += temp;

   printf("First accoutn's balance after transfer: %f\n" ,a1.balance);
   printf("Second accoutn's balance after transfer: %f\n" ,a2.balance);



   return 0;
}
