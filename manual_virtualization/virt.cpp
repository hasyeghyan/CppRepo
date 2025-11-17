#include "virt.hpp"

void Virtualizable::registerVirtual(const std::string& name, Fnptr fn){
    names.push_back(name);
    funcs.push_back(fn);
}

void Virtualizable::callVirtual(const std::string& name){
    for(int i{}; i < names.size(); ++i){
        if(names[i] == name){
            (this->*funcs[i])();
            return;
        }
    }
    std::cout << name << " not found" << std::endl;
}
