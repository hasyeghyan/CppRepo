#include <iostream>

int main(){
   int x  = 0;
   std::cout << "Please input x: ";
   std::cin >> x;
   int y = x;
   int &r = x;
   std::cout << "Values of x,y and r before chnaging: " << x <<" "<< y <<" "<< r << std::endl;
   y = 4;
   r = 18;
   std::cout << "Values of x,y and r after changing: " << x <<" "<< y <<" "<< r << std::endl;
   return 0;
}
