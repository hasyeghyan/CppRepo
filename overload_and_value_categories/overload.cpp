#include <iostream>

void print(int a){
     std::cout << a << ' ';
}

void print(double a){
     std::cout << a << ' ';
}

void print(float a){
     std::cout << a << ' ';
}

void print(bool a){
     std::cout << a << ' ';
}

int main(){
    int a = 10;
    double b = 5.4;
    float f = 5.2;
    bool flag = false;
    char c = '+';
    print(a);
    print(b);
    print(c);
    print(f);
    print(flag);
    return 0;
}


