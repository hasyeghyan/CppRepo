// my_show(5.0) call is ambigious
#include <iostream>

void my_show(int x){
     std::cout << x << std::endl;
}

void my_show(float x){
     std::cout << x << std::endl;
}

int main(){
    my_show(5);
    my_show(5.0);
    my_show(5.0f);
    return 0;
}

