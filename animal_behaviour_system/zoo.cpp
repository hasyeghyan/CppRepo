#include "zoo1.hpp"
#include "zoo2.hpp"

Animal::Animal(const std::string& n, Kind k) :name{n}, health{100},hunger{0},_kind{k} {
      std::cout << "Animal ctor: " << name << std::endl;
      takeID();
}



Parrot::Parrot(const std::string& n, Kind k,double w):Bird(n,k,w) {
    for(int i {}; i < vocabulary.size(); ++i){
        vocabulary[i] = "whu" + (i + 'a');
    }
}

void Parrot::make_sound() const {
     std::cout << "Parrot speaks with voices ";
     for(int i{}; i < vocabulary.size(); ++i){
        std::cout << vocabulary[i];
     }
     std::cout << std::endl;
}

void Lion::feed () {
     if(hunger){
        --hunger;
    }
    if(health != 100){
       ++health;
    } 
    std::cout << "Lion ate" << std::endl;
}

void Tiger::feed () {
     if(hunger){
        --hunger;
    }
    if(health != 100){
       ++health;
    } 
    std::cout << "Tiger ate" << std::endl;
}

void Elephant::feed () {
     if(hunger){
        --hunger;
    }
    if(health != 100){
       ++health;
    } 
    std::cout << "Elephant ate" << std::endl;
}

void Eagle::feed () {
     if(hunger){
        --hunger;
    }
    if(health != 100){
       ++health;
    } 
    std::cout << "Eagle ate" << std::endl;
}

void Parrot::feed () {
     if(hunger){
        --hunger;
    }
    if(health != 100){
       ++health;
    } 
    std::cout << "Parrot ate" << std::endl;
}

void Snake::feed () {
     if(hunger){
        --hunger;
    }
    if(health != 100){
       ++health;
    } 
    std::cout << "Snake ate" << std::endl;
}

void Crocodile::feed () {
     if(hunger){
        --hunger;
    }
    if(health != 100){
       ++health;
    } 
    std::cout << "Crocodile ate" << std::endl;
}