#include <iostream>

int main(){
  int x = 0;
  std::cout << "Please input x: ";
  std::cin >> x;
  int &a = x;
  int &b = x;
  a = 10;
  std::cout << "b is: " << b << std::endl;
  return 0;
}
