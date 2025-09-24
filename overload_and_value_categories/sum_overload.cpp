// Works for first adn second calls with exact match,but for third call it doesnt know which one to choose, so this is error
#include <iostream>

int sum(int a, int b){
    return a + b;
}

double sum(double a, double b){
       return a + b;
}


int main(){
    std::cout << sum(3,4) << ' ' << sum(3.5,2.5) << ' ' <<  sum(3,2.5) << std::endl;
    return 0;
}

