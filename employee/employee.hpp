#include <iostream>
#include <vector>
#include <string>

enum class Role{QA, Designer,DevOps,SoftwareEngineer, SecuritySpecialist,PM};

class Employee;


class Counter {
    private:
        inline static int _id;
        friend Employee;
};

class Employee {
    protected:
        std::string name;
        int id;
        int years;
        int projects;
        Role role;
    public:
        Employee(std::string n, int y, int p, Role r = Role::QA) : name{n}, years{y}, projects{p}, role{r} {takeId();}
        std::string get_name() const {return name;}
        void takeId() { id += Counter::_id;}
        virtual int calcualate_salary() { return 0;}
        virtual void Print() const {}
        virtual ~Employee() {std::cout << " Employee destructor called" << std::endl;}
};

class Intern : public Employee {
    private:
        Employee* mentor;
    public:
        Intern(std::string n, int y, int p, Role r = Role::PM) : Employee(n,y,p,r),  mentor{new Employee("Karen", 10, 170)} {}
        virtual int calcualate_salary() override { std::cout << "Salary is 120K" << std::endl; return 120000;}
        virtual void Print() const override;
        virtual ~Intern() { delete mentor; std::cout << "Intern destructor called" << std::endl;}

};

class Junior : public Employee {
    private:
        Employee* teamLead;
    public:
        Junior(std::string n, int y, int p, Role r = Role::SecuritySpecialist) : Employee(n,y,p,r),  teamLead{new Employee("Gayane", 15, 200, Role::PM)} {}
        virtual int calcualate_salary() override {  return projects*2000; }
        virtual void Print() const override;
        virtual ~Junior() { delete teamLead; std::cout << "Junior destructor called" << std::endl;}

};

class Middle : public Employee {
    private:
        Employee* teamLead;
    public:
        Middle(std::string n, int y, int p, Role r = Role::SecuritySpecialist) : Employee(n,y,p,r),  teamLead{new Employee("Arman", 17, 210, Role::SecuritySpecialist)} {}
        virtual int calcualate_salary() override { return projects * 1000 + years * 30000; }
        virtual void Print() const override;
        virtual ~Middle() {delete teamLead; std::cout << "Middle destructor called" << std::endl;}
};

class Senior : public Employee {
    private:
        std::vector <Employee*> subordinates;
    public:
        Senior(std::string n, int y, int p, Role r = Role::SecuritySpecialist);
        virtual int calcualate_salary() override { return projects * 1000 + years * 20000 + subordinates.size() * 1000; }
        virtual void Print() const override;
        virtual ~Senior();
};

class Department : public Employee {
    private:
        std::vector <Employee*> employees;
    public:
        Department(std::string n, int y, int p, Role r = Role::SecuritySpecialist);
        virtual void Print() const override;
        virtual ~Department();
        void add_employee(Employee* e) { employees.push_back(e); }  
        void total_payroll() const;
};

