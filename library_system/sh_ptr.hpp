#ifndef SH_PTR_HPP
#define SH_PTR_HPP

#include <iostream>

class CB{
    size_t strongcount;
    public:
        CB() : strongcount{0} {}
        size_t gets() const noexcept{return strongcount;} 
        void increment() noexcept{++strongcount;}   
        void decrement() noexcept{--strongcount;}         
};


template <typename T>
class sh_ptr{
    T* data; 
    CB* cb;
    public:
        sh_ptr(T* ptr = nullptr) noexcept;
        sh_ptr(const sh_ptr& oth) noexcept;
        sh_ptr(sh_ptr&& oth) noexcept;
        ~sh_ptr();
        sh_ptr& operator=(const sh_ptr& oth) noexcept;
        sh_ptr& operator=(sh_ptr&& oth) noexcept;
        void reset() noexcept;
        void reset(T* ptr) noexcept;
        void swap(sh_ptr& ptr) noexcept;
        T* get() const noexcept;
        T& operator*() const noexcept;
        T* operator->() const noexcept;
        long use_count() const noexcept;
        bool unique() const noexcept;
        explicit operator bool() const noexcept;
        template <typename U>
        friend bool operator==(const sh_ptr<U>& l,const sh_ptr<U>& r);
        template <typename U>
        friend bool operator!=(const sh_ptr<U>& l,const sh_ptr<U>& r);
        template <typename U>
        friend bool operator<(const sh_ptr<U>& l,const sh_ptr<U>& r);
        template <typename U>
        friend bool operator<=(const sh_ptr<U>& l,const sh_ptr<U>& r);
        template <typename U>
        friend bool operator>(const sh_ptr<U>& l,const sh_ptr<U>& r);
        template <typename U>
        friend bool operator>=(const sh_ptr<U>& l,const sh_ptr<U>& r);
        template <typename U>
        friend std::ostream& operator<<(std::ostream& ost, const sh_ptr<U>& oth);
};

template <typename T>
sh_ptr<T>::sh_ptr(T* ptr) noexcept{
    data = ptr;
    if(ptr){
        cb = new CB();
        cb->increment(); 
    }
    else{
       cb = nullptr;
    }
}

template <typename T>
sh_ptr<T>::sh_ptr(const sh_ptr& oth) noexcept{
    data = oth.data;
    cb = oth.cb;
    if(cb) cb->increment();
}  

template <typename T>
sh_ptr<T>::sh_ptr(sh_ptr&& oth) noexcept{
    data = oth.data;
    oth.data = nullptr;
    cb = oth.cb;
    oth.cb = nullptr;
}     

template <typename T>
sh_ptr<T>::~sh_ptr(){
   reset();
}

template <typename T>
sh_ptr<T>& sh_ptr<T>::operator=(const sh_ptr& oth) noexcept{
    if(this != &oth){
      reset();
      data = oth.data;
      cb = oth.cb;
      if(cb) cb->increment();
    } 
    return *this;
}


template <typename T>
sh_ptr<T>& sh_ptr<T>::operator=(sh_ptr&& oth) noexcept{
    if(this != &oth){
        reset();
        data = oth.data;
        cb = oth.cb;
        oth.data = nullptr;
        oth.cb = nullptr;
    } 
    return *this;
}

template <typename T>
void sh_ptr<T>::reset() noexcept{
    if(cb){
        cb->decrement();
        if(cb->gets() == 0){
            delete data;
            data = nullptr;
            delete cb;
            cb = nullptr;
        }
    }
    else {
        delete data;
        data = nullptr;
    }
}

template <typename T>
void sh_ptr<T>::reset(T* ptr) noexcept{
    reset();
    data = ptr;
    if(ptr){
        cb = new CB();
        cb->increment(); 
    }
    else {
        cb = nullptr;
    }
}

template <typename T>
void sh_ptr<T>::swap(sh_ptr& other ) noexcept{
   std::swap(this->data, other.data);
   std::swap(this->cb,other.cb);
}

template <typename T>
T* sh_ptr<T>::get() const noexcept{
    return data;
}

template <typename T>
T& sh_ptr<T>::operator*()const noexcept{
    return *data;
}

template <typename T>
T* sh_ptr<T>::operator->()const noexcept{
    return get();
}

template <typename T>
long sh_ptr<T>::use_count() const noexcept{
    if(cb)
       return cb->gets();
    else return 0;
}

template <typename T>
bool sh_ptr<T>::unique() const noexcept{
    if(cb)
      return cb->gets() == 1;
    else {
        return 0;
    }
}

template <typename T>
sh_ptr<T>::operator bool() const noexcept{
    return data != nullptr;
}

template <typename T>
bool operator==(const sh_ptr<T>& l,const sh_ptr<T>& r){
    return l.get() == r.get();
}

template <typename T>
bool operator!=(const sh_ptr<T>& l,const sh_ptr<T>& r){
    return !(l == r);
}

template <typename T>
bool operator<(const sh_ptr<T>& l,const sh_ptr<T>& r){
    return l.get() < r.get();
}

template <typename T>
bool operator<=(const sh_ptr<T>& l,const sh_ptr<T>& r){
    return !(r < l);
}

template <typename T>
bool operator>(const sh_ptr<T>& l,const sh_ptr<T>& r){
    return r < l;
}

template <typename T>
bool operator>=(const sh_ptr<T>& l,const sh_ptr<T>& r){
    return !(l < r);
}
   
template <typename T>
std::ostream& operator<<(std::ostream& ost, const sh_ptr<T>& oth){
    if(oth.get() == nullptr) {ost << "Data is nullptr" << std::endl;}
    else {ost << *oth;}
    if(oth.cb == nullptr) {ost << "CB is nullptr" << std::endl;}
    else {ost << oth.cb->gets();}
    return ost;
}

#endif