#include "virt.hpp"

int main() {
    Derived derivedobj;
    Base* ptr = &derivedobj;
    ptr->callVirtual("has");
    return 0;
}