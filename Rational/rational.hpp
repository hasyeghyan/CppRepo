#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>

class Rational{
      private:  
             int num;
             int denum;
	  public:
            friend Rational& reduce(Rational& r);
             Rational()noexcept;
             ~Rational()=default;
             Rational(int _num);
             Rational(int _num,int _denum);
             Rational(const Rational&);
             Rational(Rational&&) noexcept;
             Rational& operator=(const Rational&);
             Rational& operator=(Rational&&)noexcept;
             Rational operator+()const;
             Rational operator-()const;
             Rational& operator++();
             Rational operator++(int);
             Rational& operator--();
             Rational operator--(int);
             bool operator!()const;
             Rational& operator+=(const Rational&);
             Rational& operator-=(const Rational&);
             Rational& operator*=(const Rational&);
             Rational& operator/=(const Rational&);
             int numerator()const noexcept{
                 return num;
             }
             int denumerator()const noexcept{
                 return denum;
             }
             friend std::ostream& operator<<(std::ostream& os, const Rational& r);
             friend std::istream& operator>>(std::istream& c, Rational& r);   
             explicit operator double()const;
             friend Rational operator+(Rational,const Rational&);
             friend Rational operator-(Rational,const Rational&);
             friend Rational operator*(Rational,const Rational&);
             friend Rational operator/(Rational,const Rational&);
             friend bool operator==(const Rational&,const Rational&);
             friend bool operator!=(const Rational&,const Rational&);
             friend bool operator<(const Rational&,const Rational&);
             friend bool operator<=(const Rational&,const Rational&);
             friend bool operator>(const Rational&,const Rational&);
             friend bool operator>=(const Rational&,const Rational&);
};

#endif

