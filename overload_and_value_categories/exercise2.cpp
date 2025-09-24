#include <iostream>

int main() {
    int a = 1;
    ++a = 10;     // line 1
    std::cout << "after ++a = 10 -> a = " << a << std::endl;
    a = 1;
    //a++ = 10;   // line 2 (uncomment)
    // cout << "after a++ = 10 -> a = " << a << endl;
    (a += 1) = 7; 
    std::cout << a << std::endl;
    return 0;
}
//A - This will work,because pre increment returns lvalue.This will increment a by 1,then assign 10 to a,so it will print after ++a = 10 -> a = 10
//B - This one gives this  error lvalue required as left operand of assignment>This happend becasue with post increment it creates tempororay value and saves a tot hat temporrary value. so 
//a++ isnt lvalue,so we cant assign to it
//C - This works the same as ++a = 7 would have worked, so this works normally, because a += 1 is lvalue,it increments a by 1, then assigns 7 to a

