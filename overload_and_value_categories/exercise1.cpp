#include <iostream>
int main() {
    int a = 5;
    a = 10;
    //10 = a;
    a + 1 = a;
    std::cout << "a = " << a << std::endl;
    return 0;
}
//A - will work normally and print a = 10
//B - will give this error  lvalue required as left operand of assignment, because 10 is rvalue and we cant write it as left operand of assignment
//C - will give the same error as in case B, because a + 1 is also rvalue
//D - So in the left side of assignment can be only lvalue,but neither a + 1, nor 10 are lvalues,They must have addreses for assigning,while rvalues dont have.

