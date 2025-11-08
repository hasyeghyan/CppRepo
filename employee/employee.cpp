#include "employee.hpp"

void Intern::Print() const {
        std::cout << "Name is" << name << ", years are" << years <<
        ", projects are" << projects << ", role is";
        switch(role){
            case Role::QA:
                   std::cout << "QA"; break;
            case Role::Designer:
                    std::cout << "Designer"; break;
            case Role::DevOps:
                    std::cout << "DevOPs"; break;
            case Role::SoftwareEngineer:
                    std::cout << "SoftwareEngineer"; break;
            case Role::SecuritySpecialist:
                    std::cout << "SecuritySpecalist"; break;
            default:
                    std::cout << "PM";
        }
        std::cout << ", mentor's name is" << mentor->get_name();
        std::cout << std::endl;
}

void Junior::Print() const {
     std::cout << "Name is" << name << ", years are" << years <<
        ", projects are" << projects << ", role is";
        switch(role){
            case Role::QA:
                   std::cout << "QA"; break;
            case Role::Designer:
                    std::cout << "Designer"; break;
            case Role::DevOps:
                    std::cout << "DevOPs"; break;
            case Role::SoftwareEngineer:
                    std::cout << "SoftwareEngineer"; break;
            case Role::SecuritySpecialist:
                    std::cout << "SecuritySpecalist"; break;
            default:
                    std::cout << "PM";
        }
        std::cout << ", tem lead's name is" << teamLead->get_name();
        std::cout << std::endl;
}

void Middle::Print() const {
     std::cout << "Name is" << name << ", years are" << years <<
        ", projects are" << projects << ", role is";
        switch(role){
            case Role::QA:
                   std::cout << "QA"; break;
            case Role::Designer:
                    std::cout << "Designer"; break;
            case Role::DevOps:
                    std::cout << "DevOPs"; break;
            case Role::SoftwareEngineer:
                    std::cout << "SoftwareEngineer"; break;
            case Role::SecuritySpecialist:
                    std::cout << "SecuritySpecalist"; break;
            default:
                    std::cout << "PM";
        }
        std::cout << ", tem lead's name is" << teamLead->get_name();
        std::cout << std::endl;
}

Senior::Senior(std::string n, int y, int p, Role r) : Employee(n,y,p,r) {
    for(int i{}; i < subordinates.size(); ++i){
        subordinates[i] = new Employee("An" + (i + 'a'), i*10, i*100, Role::Designer);
    }
}

void Senior::Print() const {
     std::cout << "Name is" << name << ", years are" << years <<
        ", projects are" << projects << ", role is";
        switch(role){
            case Role::QA:
                   std::cout << "QA"; break;
            case Role::Designer:
                    std::cout << "Designer"; break;
            case Role::DevOps:
                    std::cout << "DevOPs"; break;
            case Role::SoftwareEngineer:
                    std::cout << "SoftwareEngineer"; break;
            case Role::SecuritySpecialist:
                    std::cout << "SecuritySpecalist"; break;
            default:
                    std::cout << "PM";
        }
        std::cout << "Subordinates names are: ";
        for(int i{}; i < subordinates.size(); ++i){
            std::cout << subordinates[i]->get_name() << ' ';
        }
        std::cout << std::endl;
}

Senior::~Senior() {     
    for(int i{}; i < subordinates.size(); ++i){
       delete subordinates[i];
    }
    std::cout << "Senior destrcutor called" << std::endl;
}

Department::Department(std::string n, int y, int p, Role r) : Employee(n,y,p,r) {
    for(int i{}; i < employees.size(); ++i){
        employees[i] = new Employee("En" + (i + 'a'), i*10, i*100, Role::DevOps);
    }
}

Department::~Department() {     
    for(int i{}; i < employees.size(); ++i){
       delete employees[i];
    }
    std::cout << "Department destrcutor called" << std::endl;
}

void Department::Print() const {
     std::cout << "Name is" << name << ", years are" << years <<
        ", projects are" << projects << ", role is";
        switch(role){
            case Role::QA:
                   std::cout << "QA"; break;
            case Role::Designer:
                    std::cout << "Designer"; break;
            case Role::DevOps:
                    std::cout << "DevOPs"; break;
            case Role::SoftwareEngineer:
                    std::cout << "SoftwareEngineer"; break;
            case Role::SecuritySpecialist:
                    std::cout << "SecuritySpecalist"; break;
            default:
                    std::cout << "PM";
        }
        std::cout << "EMployees names are: ";
        for(int i{}; i < employees.size(); ++i){
            std::cout << employees[i]->get_name() << ' ';
        }
        std::cout << std::endl;
}

void Department::total_payroll() const {
    int sum = 0;
    for(int i{}; i < employees.size(); ++i){
       sum += employees[i]->calcualate_salary();
    }
    std::cout << "Total payroll is" << sum << std::endl;
}

