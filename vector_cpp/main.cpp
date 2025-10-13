 #include "vec.hpp"
#include <iostream>

int main() {
    VecInt a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    VecInt b{4, 5, 6};
    std::cout << "Vector a: " << a << "\n";
    std::cout << "Vector b: " << b << "\n";

   

    a += b;
    std::cout << "a += b -> " << a << "\n";

    a.insert(1, 99);
    std::cout << "After insert 99 at index 1: " << a << "\n";

   

    a.pop_back();
    std::cout << "After pop_back: " << a << "\n";

    std::cout << "a == b? " << (a == b) << "\n";
    std::cout << "a != b? " << (a != b) << "\n";

    VecInt d;
    std::cout << "Enter vector size followed by elements: ";
    std::cin >> d;
    std::cout << "You entered: " << d << "\n";

    std::cout << "Comparisons:\n";
    std::cout << "a < b? " << (a < b) << "\n";
    std::cout << "a <= b? " << (a <= b) << "\n";
    std::cout << "a > b? " << (a > b) << "\n";
    std::cout << "a >= b? " << (a >= b) << "\n";

    return 0;
}
