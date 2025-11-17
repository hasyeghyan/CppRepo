#ifndef VIRT_HPP
#define VIRT_HPP

#include <iostream>
#include <string>
#include <vector>

class Virtualizable {
    public:
        using Fnptr = void (Virtualizable::*)();
        void registerVirtual(const std::string& name, Fnptr fn);
        void callVirtual(const std::string& name);
    protected:
        std::vector<std::string> names;
        std::vector<Fnptr> funcs;
};

class Base : public Virtualizable {
    public:
        Base(Fnptr fooptr = nullptr, Fnptr barptr = nullptr) : Virtualizable() {
            registerVirtual("foo", fooptr ? fooptr : static_cast<Fnptr>(&Base::foo));
            registerVirtual("bar", barptr ? barptr : static_cast<Fnptr>(&Base::bar));
        }   

    void foo() {std::cout << "Base foo" << std::endl;}
    void bar() {std::cout << "Base bar" << std::endl;}    
};

class Derived : public Base {
    public:
        Derived() : Base(static_cast<Fnptr>(&Derived::foo),static_cast<Fnptr>(&Derived::bar)){}
        void foo() {std::cout << "Derived foo" << std::endl;}
        void bar() {std::cout << "Derived bar" << std::endl;}
};


#endif