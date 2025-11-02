#ifndef ZOO1_HPP
#define ZOO1_HPP

#include <iostream>
#include <vector>
#include <string>

enum class Kind{
     Animal,Mammal,Bird,Reptile,Lion,Tiger,Elephant,Eagle,Parrot,Snake,Crocodile
};

class Animal;

class Counter{
    inline static int _id;
    friend Animal;
};

class Animal{
    protected:
            std::string name;
            int health;
            int hunger;
            Kind _kind;
            int id;
    public:
           Animal(const std::string& n = "dog", Kind k = Kind::Animal);
           void PrintInfo() const;
           void Feed();
           Kind KindOf() const { return _kind; }
           int Id() const { return id; }
           void takeID() { id = ++Counter::_id; }
};

class Mammal : public Animal{
    protected:
            bool warmBlooded;
    public:
            Mammal(const std::string& n, Kind k):Animal(n,k), warmBlooded{true}{}
            void MakeSound() const { std::cout << "Mammal sound" << std::endl; }
            void Print() const { std::cout << "This is mammal" << std::endl; }          
};

class Bird : public Animal{
    protected:
            double wingSpan;
    public:
           Bird(const std::string& n, Kind k,double w = 20.0): Animal(n,k), wingSpan{w} {}
           void Fly() const { std::cout << "The bird is flying" << std::endl; }
           void Print() const { std::cout << "This is bird" << std::endl; }          

};

class Reptile : public Animal{
    protected:
            bool coldBlooded;
    public:
            Reptile(const std::string& n, Kind k):Animal(n,k), coldBlooded{true} {}
            void Sunbathe() const { std::cout << "Reptile warms itself in the sun" << std::endl; }
            void Print() const { std::cout << "This is reptile" << std::endl; }               
};

#endif