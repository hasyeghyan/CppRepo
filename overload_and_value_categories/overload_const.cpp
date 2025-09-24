//This is error because compiler doesnt look at const
#include <iostream>

void print(int x){
     std::cout << x << ' ';
}

void print(const int x){
     std::cout << x << ' ';
}
int main(){
    int x = 10;
    const int y = 20;
    print(x);
    print(y);    
    return 0;
}
