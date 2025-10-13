#include "vec.hpp"

VecInt::VecInt(): data(nullptr), size(0), capacity(0){}
VecInt::VecInt(size_t a, int b = 0):data(new int [a]),size(a),capacity(a){
      for(int i{}; i < size; ++i){
        data[i] = b;
      }
} 
VecInt::VecInt(std::initializer_list<int> init):data(new int [init.size()]),size(0),capacity(init.size()){
      for(int val : init){
        data[size++] = val;
      }
}
VecInt::~VecInt(){
    delete[] data;
}
VecInt::VecInt(const VecInt& oth): data(new int[oth.capacity]), size(oth.size), capacity(oth.capacity){
    for(int i{}; i < size; ++i){
        data[i] = oth.data[i];
    }
}
VecInt& VecInt::operator=(const VecInt& oth){
    if(this != &oth){
        size = oth.size;
        capacity = oth.capacity;
        delete[] data;
        data = new int[capacity];
        for(int i{}; i < size; ++i){
        data[i] = oth.data[i];
        }
    }
    return *this;
}
VecInt::VecInt(VecInt&& oth): data(oth.data),size(oth.size), capacity(oth.capacity){
    oth.data = nullptr;
    oth.size = oth.capacity = 0;
}
VecInt& VecInt::operator=(VecInt&& oth){
        if(this != &oth){
          size = oth.size;
          capacity = oth.capacity;
          delete[] data;
          data = oth.data;
          oth.data = nullptr;
          oth.size = oth.capacity = 0;
        }
        return *this;
}
bool VecInt::operator==(const VecInt& oth)const{
     if(size != oth.size){
        return false;
     }
     for(int i{}; i < size; ++i){
        if(data[i] != oth.data[i])
           return false;
     }
     return true;
}
bool VecInt::operator!=(const VecInt& oth)const{
    return !(*this == oth);
}
int& VecInt::operator[](int index){
    if(index >= size){
        std::cout << "Index is invlaid.";
        std::exit(1);
    }
    return data[index];
}
VecInt& VecInt::operator+=(const  VecInt& oth){
    int min = size < oth.size ? size : oth.size;
    for(int i{}; i < min; ++i){
        data[i] += oth.data[i];
    }
    return *this;
}
VecInt& VecInt::operator-=(const  VecInt& oth){
    int min = size < oth.size ? size : oth.size;
    for(int i{}; i < min; ++i){
        data[i] -= oth.data[i];
    }
    return *this;
}
VecInt& VecInt::operator*=(const  VecInt& oth){
    int min = size < oth.size ? size : oth.size;
    for(int i{}; i < min; ++i){
        data[i] *= oth.data[i];
    }
    return *this;
}
VecInt& VecInt::operator/=(const  VecInt& oth){
    int min = size < oth.size ? size : oth.size;
    for(int i{}; i < min; ++i){
        if(oth.data[i] == 0){
            std::cout << "Cant divide by 0.";
            std::exit(1);
        }
        data[i] /= oth.data[i];
    }
    return *this;
}
VecInt operator+(VecInt c,const VecInt& oth){
       c += oth;
       return c;
}
VecInt operator-(VecInt c,const VecInt& oth){
       c -= oth;
       return c;
}
VecInt operator*(VecInt c, const VecInt& oth){
       c *= oth;
       return c;
}
VecInt operator/(VecInt c,const VecInt& oth){
       c /= oth;
       return c;
}
std::ostream& operator<<(std::ostream& os, const VecInt& r){
       os << "Vector is: ";
       for(int i{}; i < r.size; ++i){
           os << r.data[i] << " ";
       }
       return os;
}
std::istream& operator>>(std::istream& c, VecInt& r){
        int n;
        c >> n;
        r.size = r.capacity = n;
        delete[] r.data;
        r.data = new int[n];
        for (size_t i = 0; i < n; ++i)
            c >> r.data[i];
        return c;
}
bool operator<(const VecInt& c,const VecInt& oth){
    int min = c.size < oth.size ? c.size : oth.size;
    for(int i{}; i < min; ++i){
        if(c.data[i] >= oth.data[i]){
            return false;
        }
    }
    return true;
}
bool operator<=(const VecInt& c,const VecInt& oth){
     return !(oth < c);
}
bool operator>(const VecInt& c,const VecInt& oth){
    return oth < c;
}
bool operator>=(const VecInt& c,const VecInt& oth) {
    return !(c < oth);
}
void VecInt::push_back(int val){
    if(size == capacity){
        int n_capacity = capacity ? capacity * 2 : 1;
        int *n_data = new int[n_capacity];
        for(int i{}; i < size; ++i){
            n_data[i] = data[i];
        }
        delete[] data;
        data = n_data;
        capacity = n_capacity;
    }
    data[size++] = val;
}
void VecInt::pop_back(){
     if(size == 0){
        std::cout << "Vector is empty."<< std:: endl;
        return;
     }
    --size;
}
void VecInt::insert(size_t index, int val){
    if(index > size){
        std::cout << "Index is invlaid.";
        return;
    }
    if(size == capacity){
        int n_capacity = capacity ? capacity * 2 : 1;
        int *n_data = new int[n_capacity];
        for(int i{}; i < size; ++i){
            n_data[i] = data[i];
        }
        delete[] data;
        data = n_data;
        capacity = n_capacity;
    }
    for(int i = size; i > index; --i){
        data[i] = data[i-1];
    }
    data[index] = val;
    ++size;

}
