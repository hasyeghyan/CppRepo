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

class IFly{
    public:
        virtual void fly() const = 0;
};

class ISwim{
    public:
        virtual void swim() const = 0;
};

class IWalk{
    public:
        virtual void walk() const = 0;
};

class IVoice{
    public:
        virtual void make_sound() const  = 0;
};

class IFeedable{
    public:
        virtual void feed() = 0;
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
           virtual void Print() const = 0;
           Kind KindOf() const { return _kind; }
           int Id() const { return id; }
           void takeID() { id = ++Counter::_id; }
};

class Mammal : public Animal{
    protected:
            bool warmBlooded;
    public:
            Mammal(const std::string& n, Kind k):Animal(n,k), warmBlooded{true}{}
            virtual void Print() const override { std::cout << "This is mammal" << std::endl; }          
};

class Bird : public Animal{
    protected:
            double wingSpan;
    public:
           Bird(const std::string& n, Kind k,double w = 20.0): Animal(n,k), wingSpan{w} {}
           virtual void Print() const override { std::cout << "This is bird" << std::endl; }          

};

class Reptile : public Animal{
    protected:
            bool coldBlooded;
    public:
            Reptile(const std::string& n, Kind k):Animal(n,k), coldBlooded{true} {}
            virtual void Print() const override { std::cout << "This is reptile" << std::endl; }               
};

#endif