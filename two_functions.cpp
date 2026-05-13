#include <iostream>
int add(int a, int b){
   return a + b;
}
double add(double a, double b){
    return a + b;
}
int main(){
    int a  = 0;
    int b = 0;
    double x = 0;
    double y = 0;
    std::cout << "Enter your integer values: ";
    std::cin >> a >> b;
    std::cout << "Enter your double values: ";
    std::cin >> x >> y;
    int sum1 = add(a,b);
    double sum2 = add(x,y);
    std::cout<< "Integer sum is: " << sum1 << " Double sum is: " << sum2 << std::endl;

    return 0;
}
