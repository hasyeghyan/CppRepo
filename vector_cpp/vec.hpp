#ifndef VECINT_HPP
#define VECINT_HPP
#include <iostream>
class VecInt{
    private:
            int* data;
            size_t size;
            size_t capacity;
    public:
            VecInt();
            VecInt(size_t a, int b);
            VecInt(std::initializer_list<int> init);
            ~VecInt();
            VecInt(const VecInt&);
            VecInt& operator=(const VecInt&);
            VecInt(VecInt&&);
            VecInt& operator=(VecInt&&);
            bool operator==(const VecInt&)const;
            bool operator!=(const VecInt&)const;
            int& operator[](int index);
            VecInt& operator+=(const  VecInt&);
            VecInt& operator-=(const  VecInt&);
            VecInt& operator*=(const  VecInt&);
            VecInt& operator/=(const  VecInt&);
            friend VecInt operator+(VecInt,const VecInt&);
            friend VecInt operator-(VecInt,const VecInt&);
            friend VecInt operator*(VecInt, const VecInt&);
            friend VecInt operator/(VecInt,const VecInt&);
            friend std::ostream& operator<<(std::ostream& os, const VecInt& r);
            friend std::istream& operator>>(std::istream& c, VecInt& r);   
            friend bool operator<(const VecInt&,const VecInt&);
            friend bool operator<=(const VecInt&,const VecInt&);
            friend bool operator>(const VecInt&,const VecInt&);
            friend bool operator>=(const VecInt&,const VecInt&);
            size_t vecint_size() const{
                return size;
            }
            size_t vecint_capacity()const{
                 return capacity; 
            }
            void push_back(int val);
            void pop_back();
            void insert(size_t index, int val);
};
#endif