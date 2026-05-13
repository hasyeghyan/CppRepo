#include<stdio.h>
#include<string.h>

int main(){
    char username[100];
    scanf("%s", username);

    int is_admin = (strcmp(username, "admin") == 0);
    if(is_admin){

       printf("%s is admin\n", username);
    }




    return 0;
}
