#include <iostream>

void print(int a){
     std::cout << a << ' ';
}

void print(std::string s){
     std::cout << s;
     std::cout << std::endl;
}

void print(int arr[], int size){
     for(int i = 0; i < size; ++i){
        std::cout << arr[i] << ' ';
     }
     std::cout << std::endl;
}


int main(){
    int a = 10;
    const int size = 5;
    int arr[size] = {1,2,3,4,5};
    std::string s = "I am Picsart student";
    print(a);
    print(s);
    print(arr,size);
    return 0;
}


