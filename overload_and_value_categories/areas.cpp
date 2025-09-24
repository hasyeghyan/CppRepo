#include <iostream>
#define PI  3.14
double area(double radius){
        return PI * radius * radius;
}

int  area(int width, int height){
     return width * height;
}

double  area(double base, double height){
        return base * (height / 2);
}

int main(){
    double r = 0;
    int w = 0;
    int h = 0;
    double b = 0;
    double h1 = 0;
    std::cout << "Input radius,width,height,base, double height: ";
    std::cin >> r >> w >> h >> b >> h1;
    std::cout << "Circle area is: " << area(r) << ' ' << "Rectangle area is:" << area(w,h) << ' ' << "Triangle area is: " << area(b,h1) << std::endl;
    return 0;
}
