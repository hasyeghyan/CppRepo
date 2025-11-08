#include "employee.hpp"

int main() {
    Employee* e1 = new Intern("Ani", 1, 5, Role::Designer);
    Employee* e2 = new Junior("Mariam", 3, 10, Role::SoftwareEngineer);
    Employee* e3 = new Middle("Levon", 5, 12, Role::DevOps);
    Employee* e4 = new Senior("Karen", 10, 20, Role::SecuritySpecialist);
    Employee* e5 = new Department("IT_Department", 15, 50, Role::PM);

    e1->Print();
    e2->Print();
    e3->Print();
    e4->Print();
    e5->Print();

    std::cout << e1->get_name() << " salary: " << e1->calcualate_salary() << std::endl;
    std::cout << e2->get_name() << " salary: " << e2->calcualate_salary() << std::endl;
    std::cout << e3->get_name() << " salary: " << e3->calcualate_salary() << std::endl;
    std::cout << e4->get_name() << " salary: " << e4->calcualate_salary() << std::endl;
    
    Department* dep = new Department("IT_Department2", 15, 50, Role::SoftwareEngineer);
    dep->add_employee(e1);
    dep->add_employee(e2);
    dep->add_employee(e3);
    dep->add_employee(e4);

    dep->Print();
    dep->total_payroll();

   

    return 0;
}
