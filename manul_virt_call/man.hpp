#ifndef MAN_HPP
#define MAN_HPP

#include <vector>
#include <string>
#include <iostream>

class Base {
    public:
        virtual void foo() {std::cout << "Base foo" << std::endl;}
        virtual void bar() {std::cout << "Base bar" << std::endl;}

        
};

class Derived : public Base {
    public:
        virtual void foo() override {std::cout << "Derived foo" << std::endl;}
        virtual void bar() override {std::cout << "Derived bar"<< std::endl;}
};

#endif