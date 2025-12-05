#ifndef UNIQUE_HPP
#define UNIQUE_HPP

#include <iostream>

template <typename T>
class u_ptr{
        T* data;
    public:
       u_ptr(T* ptr = nullptr) noexcept;
       u_ptr(const u_ptr& oth) = delete;
       u_ptr (u_ptr&& oth) noexcept;      
       ~u_ptr();
       u_ptr& operator=(const u_ptr& oth) = delete;
       u_ptr& operator=(u_ptr&& oth) noexcept;
       u_ptr& operator=( std::nullptr_t n) noexcept;
       T* release()noexcept;
       void reset(T* ptr = nullptr) noexcept;
       void swap(u_ptr& other ) noexcept;
       T* get() const noexcept;
       explicit operator bool() const noexcept;
       T& operator*()const noexcept;
       T* operator->()const noexcept;
       template <typename U>
       friend bool operator==(const u_ptr<U>& l,const u_ptr<U>& r);
       template <typename U>
       friend bool operator!=(const u_ptr<U>& l,const u_ptr<U>& r);
       template <typename U>
       friend bool operator<(const u_ptr<U>& l,const u_ptr<U>& r);
       template <typename U>
       friend bool operator<=(const u_ptr<U>& l,const u_ptr<U>& r);
       template <typename U>
       friend bool operator>(const u_ptr<U>& l,const u_ptr<U>& r);
       template <typename U>
       friend bool operator>=(const u_ptr<U>& l,const u_ptr<U>& r);
       template <typename U>
       friend std::ostream& operator<<(std::ostream& ost, const u_ptr<U>& oth);
};

template <typename T>
u_ptr<T>::u_ptr(T* ptr) noexcept{
    data = ptr;
}

template <typename T>
u_ptr<T>::u_ptr(u_ptr&& oth) noexcept{
    data = oth.data;
    oth.data = nullptr;
}     

template <typename T>
u_ptr<T>::~u_ptr(){
    reset();
}

template <typename T>
u_ptr<T>& u_ptr<T>::operator=(u_ptr&& oth) noexcept{
    if(this != &oth){
        delete data;
        data = oth.data;
        oth.data = nullptr;
    } 
    return *this;
}

template <typename T>
u_ptr<T>& u_ptr<T>::operator=( std::nullptr_t n) noexcept{
    reset();
    return *this;
}

template <typename T>
T* u_ptr<T>::release()noexcept{
    T* tmp = this->get();
    this->data = nullptr;
    return tmp; 
}

template <typename T>
void u_ptr<T>::reset(T* ptr) noexcept{
    delete data;
    data = ptr;
}

template <typename T>
void u_ptr<T>::swap(u_ptr& other ) noexcept{
   std::swap(this->data, other->data);
}

template <typename T>
T* u_ptr<T>::get() const noexcept{
    return data;
}

template <typename T>
u_ptr<T>::operator bool() const noexcept{
    return data != nullptr;
}

template <typename T>
T& u_ptr<T>::operator*()const noexcept{
    return *data;
}

template <typename T>
T* u_ptr<T>::operator->()const noexcept{
    return get();
}

template <typename T>
bool operator==(const u_ptr<T>& l,const u_ptr<T>& r){
    return l.get() == r.get();
}

template <typename T>
bool operator!=(const u_ptr<T>& l,const u_ptr<T>& r){
    return !(l == r);
}

template <typename T>
bool operator<(const u_ptr<T>& l,const u_ptr<T>& r){
    return l.get() < r.get();
}

template <typename T>
bool operator<=(const u_ptr<T>& l,const u_ptr<T>& r){
    return !(r < l);
}

template <typename T>
bool operator>(const u_ptr<T>& l,const u_ptr<T>& r){
    return r < l;
}

template <typename T>
bool operator>=(const u_ptr<T>& l,const u_ptr<T>& r){
    return !(l < r);
}
   
template <typename T>
std::ostream& operator<<(std::ostream& ost, const u_ptr<T>& oth){
    if(oth.get() == nullptr) {ost << "This is nullptr" << std::endl; return ost;}
    ost << *oth;
    return ost;
}


#endif