#include <iostream>

int main(){
   int arr[3] = {1,2,3};
   int &r = arr[0];
   std::cout << "Array before change is: ";
   for(int i = 0; i < 3; ++i){
      std::cout << arr[i] << " "; 
   }
   std::cout << std::endl;
   r = 5;
   std::cout << "Array after change is: ";
   for(int i = 0; i < 3; ++i){
      std::cout << arr[i] << " ";
   }
   std::cout << std::endl;
  return 0;
}
