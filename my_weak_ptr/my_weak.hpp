#ifndef MY_WEAK_HPP
#define MY_WEAK_HPP

#include <iostream>
#include <vector>
#include <string>
#include "sh.hpp"

template <typename T>
class CB {
    T* data;
    size_t strongcount;
    size_t weakcount;
    public:
        CB() : data{nullptr}, strongcount{1}, weakcount{1} {}
        
        size_t get_strong() const noexcept{return strongcount;} 
        size_t get_weak() const noexcept{return weakcount;} 
        
        void increment() noexcept{++strongcount;}   
        void add_weak() noexcept { ++weakcount; }

        void release_weak();
        void release_count();
        
        void destroy_data();
        void destroy_self();
};

template <typename T>
void CB<T>::release_count() {
    if(--strongcount == 0){
        destroy_data();
        release_weak();
    }
}

template <typename T>
void CB<T>::release_weak() {
    if(--weakcount == 0){
        destroy_self();
    }
}

template <typename T>
void CB<T>::destroy_data() {
    if(data) delete data;
}

template <typename T>
void CB<T>::destroy_self() {
    delete this;
}

template <typename T>
class sh_ptr;


template <typename T>
class my_weak {
    T* ptr;
    CB<T>* control;
    
    public:
       my_weak() noexcept : ptr{nullptr}, control{nullptr} {}
       my_weak(const my_weak& oth) noexcept;
       my_weak(const sh_ptr<T>& oth) noexcept;
       my_weak(my_weak&& oth) noexcept;
       ~my_weak();
        
       my_weak& operator=( const my_weak& oth ) noexcept;
       my_weak& operator=( const sh_ptr<T>& oth ) noexcept;
       my_weak& operator=(my_weak&& oth) noexcept;

       T* getd() const noexcept { return ptr; }
       CB<T>* getc() const noexcept { return control; }
  
       void reset() noexcept;
       
       void swap(my_weak& r) noexcept;
       template <typename U>
       friend void swap( my_weak<U>& lhs, my_weak<U>& rhs ) noexcept;

       long use_count() const noexcept;

       bool expired() const noexcept;

       sh_ptr<T> lock() const noexcept;
};


template <typename T>
my_weak<T>::my_weak(const my_weak& oth) noexcept {
    ptr = oth.ptr;
    control = oth.control;
    if(control) control->add_weak();
}

template <typename T>
my_weak<T>::my_weak( const sh_ptr<T>& oth ) noexcept {
    ptr = oth.get();
    control = oth._get();
    if(control) control->add_weak();  
}

template <typename T>
my_weak<T>::my_weak( my_weak&& oth ) noexcept {
    ptr = oth.ptr;
    oth.ptr = nullptr;
    control = oth.control;
    oth.control = nullptr;
}

template <typename T>
my_weak<T>::~my_weak() {
   if(control) control->release_weak();
}

template <typename T>
my_weak<T>& my_weak<T>::operator=( const my_weak<T>& oth ) noexcept {
    if(this != &oth) {
       reset();
       ptr = oth.ptr;
       control = oth.control;
       if(control) control->add_weak();
    }
    return *this;
}

template <typename T>
my_weak<T>& my_weak<T>::operator=( const sh_ptr<T>& oth ) noexcept {
    if(this->ptr != oth.data){
        reset();
        ptr = oth.get();
        control = oth._get();
        if(control) control->add_weak(); 
    }
    return *this;
}

template <typename T>
my_weak<T>& my_weak<T>::operator=(my_weak&& oth) noexcept {
    if(this != &oth){
      ptr = oth.ptr;
      oth.ptr = nullptr;
      control = oth.control;
      oth.control = nullptr;
    }
    return *this;
}

template <typename T>
void my_weak<T>::reset() noexcept {
    if(control) control->release_weak();
    ptr = nullptr;
    control = nullptr;
}

template <typename T>
void my_weak<T>::swap(my_weak& r) noexcept {
    T* tmp = ptr;
    CB<T>* tmp1 = control;

    ptr = r.ptr;
    control = r.control;

    r.ptr = tmp;
    r.control = tmp1;
}

template <typename T>
long my_weak<T>::use_count() const noexcept {
    if(control) return control->get_strong();
    else return 0;
}

template <typename T>
bool my_weak<T>::expired() const noexcept {
    return use_count() == 0;
}

template <typename T>
sh_ptr<T> my_weak<T>::lock() const noexcept {
    if(!expired()){
        return sh_ptr<T>(*this);
    }
    return sh_ptr<T>();
}

template <typename T>
void swap( my_weak<T>& lhs, my_weak<T>& rhs ) noexcept {
    lhs.swap(rhs);
}

#endif