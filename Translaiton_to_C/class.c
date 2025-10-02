#include <stdio.h>
#include <string.h>
#define size 8
#include <stdbool.h>

typedef struct {
        char name[size];
        int age;
        double height;

}Person;

void P_ctor(Person* const this){
        strncpy(this -> name, "Unknown", size - 1);
        this->name[size - 1] = '\0';
        this -> age = 0;
        this -> height = 0.0;
}

void P_par_ctor(Person* const this, char* n, int a ,double h ){
        strncpy(this -> name , n , size - 1);
	this->name[size - 1] = '\0';
        this ->age = a;
        this -> height = h;
}

const char* getName(const Person* const this){
        return this -> name;
}

int getAge(const Person* const this){
        return this -> age;
}
double getHeight(const Person* const this){
        return this -> height;

}
void setName(Person* this, const char* n){
        strncpy(this -> name ,n, size - 1);
	this->name[size- 1] = '\0';
}
void setAge(Person* const this, int a){
        this -> age = a;

}
void setHeight(Person* const this , double h){
        this ->height = h;
}

void printinfo(const Person* const this){
     printf("Name: %s",this->name);
     printf(", Age: %d", this->age);
     printf(", Height: %lf\n", this->height);
}

void printInfo(const Person* const this, bool showHeight){
     printf("Name: %s",this->name);
     printf(", Age: %d", this->age);
     if(showHeight)
       printf(", Height: %lf", this->height);
     printf("\n");
}

int main(){
    Person p;
    P_par_ctor(&p,"Bob", 19,1.75);
    printinfo(&p);
    printInfo(&p,true);
    setAge(&p,20);
    printf("Updated age: %d", getAge(&p));
    return 0;
}






