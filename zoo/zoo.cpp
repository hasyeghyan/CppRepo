#include "zoo1.hpp"
#include "zoo2.hpp"

Animal::Animal(const std::string& n, Kind k) :name{n}, health{100},hunger{0},_kind{k} {
      std::cout << "Animal ctor: " << name << std::endl;
      takeID();
}

void Animal::Feed(){
     if(hunger){
        --hunger;
    }
    if(health != 100){
       ++health;
    } 
}

Parrot::Parrot(const std::string& n, Kind k,double w):Bird(n,k,w) {
    for(int i {}; i < vocabulary.size(); ++i){
        vocabulary[i] = "whu" + (i + 'a');
    }
}

void Parrot::Speak() const {
     std::cout << "Parrot speaks with voices ";
     for(int i{}; i < vocabulary.size(); ++i){
        std::cout << vocabulary[i];
     }
     std::cout << std::endl;
}

void Animal::PrintInfo() const {
     std::cout << "Animal's name is " << name << " health is " << health << " hunger is " << hunger << " id is " << id << ' ';
     switch(_kind){
        case Kind::Animal:
                std::cout << "This is animal" << std::endl;
                break;
        case Kind::Bird:
                (static_cast<const Bird* const>(this))->Print();
                break;
        case Kind::Mammal:
                (static_cast<const Mammal* const>(this))->Print();
                break;
        case Kind::Reptile:
                (static_cast<const Reptile* const>(this))->Print();
                break;
        case Kind::Lion:
                (static_cast<const Lion* const>(this))->Print();
                break;
        case Kind::Tiger:
                (static_cast<const Tiger* const>(this))->Print();
                break;
        case Kind::Elephant:
                (static_cast<const Elephant* const>(this))->Print();
                break;
        case Kind::Eagle:
                (static_cast<const Eagle* const>(this))->Print();
                break;
        case Kind::Parrot:
                (static_cast<const Parrot* const>(this))->Print();
                break;
        case Kind::Snake:
                (static_cast<const Snake* const>(this))->Print();
                break;
        deafult:
                (static_cast<const Crocodile* const>(this))->Print();
        } 
}
