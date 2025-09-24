#include <iostream>


int getFive() {
    return 5;
}

int main() {
    int a;
    a = getFive();      // valid
    std::cout << "a = " << a << std::endl;

    getFive() = 7;   // uncomment and test
    return 0;
}
/* A - This will work normally and print a = 5
   B - This gives error,because function return value is temporary valu,it doesnt ocupy memeory,so it isnt lvalue,so we cant assign to it
   C - getFive() is just temporary int value in this case 5.So when we do a = getFive() it just copies 5 to a adn after this lien that temporrary object disappears.But in getFive() = 7 we 
   have assignement,so the left side must be lvalue,while temporary values are rvalues.  
*/
