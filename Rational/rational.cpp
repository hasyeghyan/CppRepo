#include "rational.hpp"
#include <numeric>  
#include <cstdlib>  

Rational& reduce(Rational& r){
        int g = std::gcd(std::abs(r.num), std::abs(r.denum));
        r.num /= g;
        r.denum /= g;
        return r;
}
Rational::Rational()noexcept: num{0}, denum{1} {}
Rational::Rational(int _num): num{_num}, denum{1} {}
Rational::Rational(int _num,int _denum): num{_num}, denum{_denum}{
        if(denum == 0){
            std::cout << "Denumerator cannot be 0";
            std::exit(1);
        }  
        if(denum < 0){
            num = -num;
            denum = -denum;
        }
        reduce(*this);
}
Rational::Rational(const Rational& other):num{other.num}, denum{other.denum}{}
Rational::Rational(Rational&& other)noexcept:num{other.num}, denum{other.denum}{
           other.num = 0;
           other.denum = 1;
}
Rational& Rational::operator=(const Rational& other){
          if(this != &other){
            num = other.num;
            denum = other.denum;
          }
          return *this;
}
Rational& Rational::operator=(Rational&& other)noexcept{
        if(this != &other){
           num = other.num;
           denum = other.denum;
        }
        other.num = 0;
        other.denum = 1;
        return *this;
}
Rational Rational::operator+() const{
        return *this;         
}
Rational Rational::operator-() const{
         return Rational(-num,denum);
}
Rational& Rational::operator++(){
          num += denum; 
          return reduce(*this);
}
Rational Rational::operator++(int x){
         Rational temp = *this;
         ++(*this);
         return temp;  
}
Rational& Rational::operator--(){
          num -= denum;
          return reduce(*this);
}
Rational Rational::operator--(int x){
         Rational temp = *this;
         --(*this);
         return temp;
}
bool Rational::operator!()const{
        return !num;
}
Rational& Rational::operator+=(const Rational& other){
        num = num * other.denum + other.num * denum;
        denum *= other.denum;
        return reduce(*this );  
}
Rational& Rational::operator-=(const Rational& other){
        num = num * other.denum - denum * other.num;
        denum *= other.denum;
        return reduce(*this); 
}
Rational& Rational::operator*=(const Rational& other){
	num *= other.num;
	denum *= other.denum;
	return reduce(*this);
}
Rational& Rational::operator/=(const Rational& other){
	num *= other.denum;
	denum *= other.num;
	return reduce(*this);
}
Rational operator+(Rational c,const Rational& r){
        c += r;
        return c;
}
Rational operator-(Rational c,const Rational& r){
        c -= r;
        return c;
}
Rational operator*(Rational c,const Rational& r){
        c *= r;
        return c;        
}
Rational operator/(Rational c,const Rational& r){
        c /= r;
        return c;
}
bool operator==(const Rational& c,const Rational& r){
        return ((c.num == r.num) && (c.denum == r.denum));
}
bool operator!=(const Rational& c,const Rational& r){
        return !(c == r);
}
bool operator<(const Rational& c,const Rational& r){
        return (c.num * r.denum) < (c.denum * r.num);
}
bool operator<=(const Rational& c,const Rational& r){
        return (c.num * r.denum) <= (c.denum * r.num);

}
bool operator>(const Rational& c,const Rational& r){
        return (c.num * r.denum) > (c.denum * r.num);
}
bool operator>=(const Rational& c,const Rational& r){
        return (c.num * r.denum) >= (c.denum * r.num);
}
std::ostream& operator<<(std::ostream& os, const Rational& r){
        os << "Numerator is " << r.num << ", denumerator is " << r.denum << std::endl;
        return os; 
}
std::istream& operator>>(std::istream& c, Rational& r){
        std::cout << "Please input numerator and denumerator: ";
        c >> r.num >> r.denum;
        return c;
} 
Rational::operator double()const{
        return double(num) / double(denum);
}