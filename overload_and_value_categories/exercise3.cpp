#include <iostream>

int main() {
    int arr[3] = {1,2,3};
    arr[0] = 10;          // valid
    std::cout << arr[0] << std::endl;

    //(arr[0] + 1) = 5;  // uncomment and test
    *(arr + 0) = 6;    // uncomment and test

    return 0;
}
/* A - Works normally,prints 10
   B - This doenst compile, because arr[0] + 1 is temporary value,so it isnt lvalue,so we cant assign to it
   C - This compiles.*(arr + 0) is the same as arr[0]  so it works like second line,it changes first elements value to 6
   D - arr[0] and *(arr + 0) are the same,they are both the first element of array.Array ocupies memeory,so its first element ocupies memory so these are lvalues.arr[0] + 1 doesnt ocupy 
   memory,it is just temporary value,so it isnt lvalue.
*/ 
