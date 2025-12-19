#include "my_weak.hpp"
#include "sh.hpp"


int main() {
    sh_ptr<std::string> sp1(new std::string("Hello"));
    std::cout << "sp1 use_count: " << sp1.use_count() << "\n";

    my_weak<std::string> wp1 = sp1;
    std::cout << "wp1 use_count: " << wp1.use_count() << "\n";

    sh_ptr<std::string> sp2 = wp1.lock();
    std::cout << "After lock sp2 use_count: " << sp2.use_count() << "\n";

    sp1.reset();
    std::cout << "After sp1.reset(), wp1 expired? " << wp1.expired() << "\n";
    std::cout << "sp2 use_count: " << sp2.use_count() << "\n";

    sp2.reset();
    std::cout << "After sp2.reset(), wp1 expired? " << wp1.expired() << "\n";

    return 0;
}
