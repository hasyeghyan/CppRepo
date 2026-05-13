#include <iostream>
void  sum(int &a, int &b, int &res){
     res =  a + b;
}    
int main(){
    int a  = 0;
    int b = 0;
    int res = 0;
    std::cout<< "Enter your values: ";
    std::cin >> a >> b;
    std:: cout << "Res before sum is: " << res << std::endl;
    sum(a, b, res);
    std::cout << "Res after sum is: " << res << std::endl;
    return 0;
}
