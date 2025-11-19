#include "task.hpp"

int main() {
    // Derived derivedobj;
    // Base* ptr = &derivedobj;
    // ptr->callVirtual("foo");
    Virtualizable* v = new Base; // this prints cast is not done,if we do Virtualizable* v = new Derived; then it prints cast is done
    if(Derived* d = dynamicCast<Derived>(v)) {
      std::cout << "Cast is done" << std::endl;
    }
    else { std::cout << "Cast is  not done" << std::endl; }
    return 0;
}

