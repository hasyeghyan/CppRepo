#include "unique.hpp"


int main(){
    u_ptr<int> ptr1(new int(3));
    std::cout << "Data of ptr1 before release is " << ptr1;
    ptr1.release();
    std::cout << "Data of ptr1 after release is " << ptr1;
    ptr1.reset();

    u_ptr<int> ptr2(new int(7));
    std::cout << "Data of ptr2 is " << ptr2;
    u_ptr<int> ptr3(std::move(ptr2));
    std::cout << "Data of ptr3 before reset is " << ptr3;
    ptr3.reset();
    std::cout << "Data of ptr3 after reset is " << ptr3;

    if(ptr1 == ptr2)
    std::cout << "ptr1 and ptr2 are equal." << std::endl;

    if( ptr2 > ptr3)
    std::cout << "ptr2 is bigger then ptr3 " << std::endl;

    u_ptr<int> ptr4(new int(10));
    *ptr4 = 15;
    std::cout << "Data of ptr4 is " << ptr4 << std::endl;

    return 0;
}