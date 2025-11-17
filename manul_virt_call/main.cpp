#include "man.hpp"

int main() {
    Derived d;

    using F = void(*)(void*);

   
    void** vptr = *(void***)&d;

  
    F f0 = (F)vptr[0];
    F f1 = (F)vptr[1];

  
    f0(&d);  
    f1(&d);  

    return 0;
}
