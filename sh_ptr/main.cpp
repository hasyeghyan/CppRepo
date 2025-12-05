#include "sh.hpp"

int main() {
    sh_ptr<int> p1(new int(10));
    std::cout << p1 << " " << p1.use_count() << "\n";

    sh_ptr<int> p2 = p1;
    std::cout << p1 << " " << p2 << " " << p1.use_count() << "\n";

    sh_ptr<int> p3 = std::move(p2);
    std::cout << p2 << " " << p3 << " " << p3.use_count() << "\n";

    p1.reset(new int(20));
    std::cout << p1 << " " << p1.use_count() << "\n";

    p3.reset();
    std::cout << p3 << " " << p3.use_count() << "\n";

    p1.swap(p3);
    std::cout << p1 << " " << p3 << "\n";

    std::cout << (p1.unique() ? "yes" : "no") << " " << (p3.unique() ? "yes" : "no") << "\n";

    return 0;
}
