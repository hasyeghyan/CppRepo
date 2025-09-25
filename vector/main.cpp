#include <iostream>
#include "vector.hpp"

int main(){
    MyVector v;
    myvector_init(&v, 10);
    std::cout << "Yout vector size is: " << myvector_size(&v) << std::endl;
    std::cout << "Yout vector capacity is: " << myvector_capacity(&v) << std::endl;
    myvector_destroy(&v);

    myvector_init(&v, 2, 7);
    std::cout << "Yout vector size is: " << myvector_size(&v) << std::endl;
    std::cout << "Yout vector capacity is: " << myvector_capacity(&v) << std::endl;
    myvector_print(&v);

    myvector_push_back(&v, 10);
    myvector_push_back(&v, 20);
    myvector_push_back(&v, 30);
    myvector_push_back(&v, 40);
    myvector_push_back(&v, 50);

    std::cout << "Yout vector size is: " << myvector_size(&v) << std::endl;
    std::cout << "Yout vector capacity is: " << myvector_capacity(&v) << std::endl;
    myvector_print(&v);
    
    myvector_pop_back(&v);
    myvector_print(&v);
    
    myvector_insert(&v, 1, 15);
    myvector_print(&v);

    myvector_erase(&v, 2);
    myvector_print(&v);

    myvector_clear(&v);
    myvector_destroy(&v);
    return 0;
}
