#include <iostream>
#include <limits>
#include <cmath>

double _round(double res){
    if(res - std::floor(res) == 0) {
        std::cout << (long long)(res);
        return res;
    }
    std::cout << res;
    return res;
}


double safe_add(double x, double y){
    if(x > std::numeric_limits<double>::max() - y){
        throw std::overflow_error("overflow");
    }
    std::cout << "Addition result is ";
    _round(x+y);
    std::cout << std::endl;
    return x + y;
    
}

double safe_sub(double x, double y){
    if(x < std::numeric_limits<double>::min() + y){
        throw std::underflow_error("underflow");
    }
    std::cout << "Sub result is ";
    _round(x - y);
    std::cout << std::endl;
    return x - y;
}

double safe_mul(double x, double y){
    if(y == 0) return 0;
    if(x > std::numeric_limits<double>::max() / y){
        throw std::overflow_error("overflow");
    }
    std::cout << "Multiplication result is ";
    _round(x * y);
    std::cout << std::endl;
    return x * y;
}

double safe_divide(double x, double y){
    if(y == 0) throw std::domain_error("Cant divide by 0");
    if(x < std::numeric_limits<double>::min() * y){
        throw std::overflow_error("overflow");
    }
    std::cout << "Division result is ";
    _round(x / y);
    std::cout << std::endl;
    return x / y;
}

double safe_log(double base, double y){
    if(base <= 0 || base == 1 || y <= 0) throw std::domain_error("Logarithm base error");
    std::cout << "Log result is ";
    _round(std::log(y) / std::log(base));
    std::cout << std::endl;
    return std::log(y) / std::log(base);
}

double safe_sqrt(double x){
    if(x < 0) throw std::domain_error("Number under sqrt cant be negative");
    std::cout << "Sqrt result is ";
    _round(std::sqrt(x));
    std::cout << std::endl; 
    return std::sqrt(x);
}

double safe_pow(double x, double y){
    if(x == 1) {
        _round(1);
        return 1;
    }
    if(x == 0 && y < 0) throw std::domain_error("Illegal");
    if(x < 0 && y - std::floor(y) != 0) throw std::domain_error("Illegal");
    
   double lx = std::log(x);
   double maxLog = std::log(std::numeric_limits<double>::max());
   double minLog = std::log(std::numeric_limits<double>::min());

   if (x > 1) {
      if (y > maxLog / lx) throw std::overflow_error("Overflow");
      if (y < minLog / lx) throw std::underflow_error("Underflow");  
  } 
  else if (x > 0 && x < 1) {
    if (y < maxLog / lx) throw std::overflow_error("Overflow");   
    if (y > minLog / lx) throw std::underflow_error("Underflow"); 
  }

    std::cout << "Pow result is ";
     _round(std::pow(x,y));
     std::cout << std::endl;    
     return std::pow(x,y);
}

int main() {
    double x  = 0.0;
    double y = 0.0;
    char c = '\0';

    while(true){
        std::cout << "Enter first number:";
        std::cin >> x;
        std::cout << "Enter second number:";
        std::cin >> y;
        std::cout << "Enter opertaion: q to quit:";
        std::cin >> c;
        if(c == 'q') break;
        try {
            switch(c){
                case '+': safe_add(x,y); break;
                case '-': safe_sub(x,y); break;
                case '*': safe_mul(x,y); break;
                case '/': safe_divide(x,y); break;
                case 'l': safe_log(x,y); break;
                case 's': safe_sqrt(x); break;
                case '^': safe_pow(x,y); break;
            }
        }catch(const std::overflow_error& e){std::cout << "Overflow error caught" << std::endl;}
         catch(const std::underflow_error& e){std::cout << "Undererflow error caught" << std::endl;}
         catch(const std::domain_error& e){std::cout << "Domain error caught" << std::endl;}
    }
    return 0;
}