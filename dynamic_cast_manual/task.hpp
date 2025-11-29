#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>
#include <vector>


class Virtualizable {
    public:
        using Fnptr = void (Virtualizable::*)();
        void registerVirtual(const std::string& name, Fnptr fn);
        void callVirtual(const std::string& name);
        std::string getTypeid() {
            return _typeid;
        }
    protected:
        std::string _typeid;
        std::vector<std::string> names;
        std::vector<Fnptr> funcs;
        Virtualizable(const std::string& _type_id, const std::string& FuncName,const std::string& FuncName1, Fnptr virtFunc1,Fnptr virtFunc2) : _typeid{_type_id} {
            registerVirtual(FuncName, virtFunc1);
            registerVirtual(FuncName1, virtFunc2);
        } 
};

class Base : public Virtualizable {
    public:
        Base(const std::string& _type_id = getTypeName(), const std::string& FuncName = "foo",const std::string& FuncName1 = "bar", Fnptr fooptr = (Fnptr)&Base::foo, Fnptr fooptr1 = (Fnptr)&Base::bar) : Virtualizable(_type_id,FuncName,FuncName1,fooptr,fooptr1) {}   
        void foo() {std::cout << "Base foo" << std::endl;}
        void bar() {std::cout << "Base bar" << std::endl;}  
        static const char* getTypeName() {
            return "Base";
        }  
        
};

class Derived : public Base {
    public:

        Derived(const std::string& _type_id = getTypeName(), const std::string& FuncName = "foo", const std::string& FuncName1 = "bar",Fnptr virtFunc1 = (Fnptr)&Derived::foo,Fnptr virtFunc2 = (Fnptr)&Derived::bar) : Base(_type_id, FuncName,FuncName1 ,virtFunc1,virtFunc2) {}

        void foo() {std::cout << "Derived foo" << std::endl;}
        void bar() {std::cout << "Derived bar" << std::endl;}
        static const char* getTypeName() {
            return "Derived";
        }
};

template<typename T>
T* dynamicCast(Virtualizable* type){
    if(type->getTypeid() == T::getTypeName()){
      return (T*)type;
    }

    return nullptr;
}


#endif
