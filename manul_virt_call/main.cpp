#include "man.hpp"

int main() {
    Derived obj;
    void*** vptr= (void***)&obj;

    using Fn = void(*)(void*);

    Fn f1 = (Fn)(*vptr)[0];
    Fn f2 = (Fn)(*vptr)[1];
    f1(&obj);
    f2(&obj);

    return 0;
}
