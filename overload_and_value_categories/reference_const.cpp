//This one works, because const reference bind only to const objects, and non const to non consts
#include <iostream>

void print(int& x){
     std::cout << x << ' ';
}

void print(const int& x){
     std::cout << x << ' ';
}
int main(){
    int x = 10;
    const int y = 20;
    print(x);
    print(y);
    return 0;
}

