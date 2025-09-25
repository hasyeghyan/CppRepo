#include <cstddef> 
#include <iostream>
#include "vector.hpp"

void myvector_init(MyVector* v, size_t capacity){
     v->size = 0;
     v->capacity = capacity;
     v->capacity = v->capacity == 0 ? 4 : v->capacity;
     v->data = new int[v->capacity];
}

void myvector_init(MyVector* v, size_t size, int val){
     v->size = size;
     v->capacity = size  == 0 ? 4 : size;
     v->data = new int[v->capacity];
     for(size_t i = 0; i < v->size; ++i){
        v->data[i] = val;
     }
}

void myvector_destroy(MyVector* v){
     v->size = 0;
     v->capacity = 0;
     delete[] v->data;
     v->data = nullptr;
}

void myvector_clear(MyVector* v){
     v->size  = 0;
}

size_t myvector_size(const MyVector* v){
       return v->size;
}

size_t myvector_capacity(const MyVector* v){
       return v->capacity;
}

void myvector_push_back(MyVector* v, int value){
     if(v->size == v->capacity){
       v->capacity *= 2;
       int* p = new int[v->capacity];
       for(size_t i = 0; i < v->size; ++i){
          p[i] = v->data[i]; 
       }
       delete[] v->data;
       v->data = p;
     }
      v->data[v->size] = value;
      v->size += 1;
}

void myvector_pop_back(MyVector* v){
     if(v->size == 0){
       std::cout << "Vector is empty";
     }
     --v->size;
}

void myvector_insert(MyVector* v, size_t index, int value){
     if(index > v->size){
       std::cout << "Invalid index";
       std::cout << std::endl;
       return;
     }
     if(v->size == v->capacity){
       v->capacity *= 2;
       int* p = new int[v->capacity];
       for(size_t i = 0; i < v->size; ++i){
          p[i] = v->data[i];
       }
       delete[] v->data;
       v->data = p;
     }
     if(index == v->size){
       myvector_push_back(v,value);
       return;
     }
     for(size_t i = v->size; i > index; --i){
        v->data[i] = v->data[i - 1];
     }
     v->data[index] = value;
     ++v->size;
}

void myvector_erase(MyVector* v, size_t index){
     if(index >= v->size){
       std::cout << "Invalid index";
       std::cout << std::endl;
       return;
     }
     for(size_t i = index; i < v->size - 1; ++i){
        v->data[i] = v->data[i + 1];
     }
     --v->size;
}

void myvector_print(const MyVector* v){
     std::cout << "Your vector is: ";
     for(size_t i = 0; i < v->size; ++i){
        std::cout << v->data[i] << ' ';
     }
     std::cout << std::endl;
}








