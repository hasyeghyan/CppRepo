#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <vector>
#include <string>

enum class Kind {Vehicle, Car, Airplane, Hyundai, Mazda, Airbus, Boeing};

class Vehicle {
    protected:
        std::string name;
        int power;
        double speed;
        Kind _kind;
    public:
        Vehicle(const std::string& n,int p, double s, Kind k = Kind::Vehicle):name{n}, power{p}, speed{s}, _kind{k} { std::cout << "ctor: " << name << std::endl; }
        void move() const { std::cout << "Vehicle is moving" << std::endl; }
        void PrintInfo() const;
};

class Car : public Vehicle {
      protected:
            std::string brand;
      public:
            Car(const std::string& n,int p, double s, Kind k, const std::string& b): Vehicle(n,p,s,k), brand{b} {}
            void drive() const { std:: cout << "We drive car." << std::endl; }
            void Print() const { std::cout << "This is car" << std::endl; }
};

class Airplane : public Vehicle {
      protected:
            double wingspan;
      public: 
        Airplane(const std::string& n,int p, double s, Kind k, double w1): Vehicle(n,p,s,k), wingspan{w1} {} 
        void Fly() const {std::cout << "Airplane is flying." << std::endl; }
        void Print() const { std::cout << "This is airplane" << std::endl; }
};

class Hyundai final: public Car {
    private:
            bool driverAttentionWarning;
    public:
        Hyundai(const std::string& n,int p, double s, Kind k, const std::string& b): Car(n,p,s,k,b), driverAttentionWarning(true) {} 
        void Hyundai_drive() const {std::cout << "We are driving Hyundai." << std::endl;} 
        void Print() const { std::cout << "This is Hyundai" << std::endl; }
};

class Mazda final : public Car {
    private:
        bool parkingAssist;
    public:
        Mazda(const std::string& n,int p, double s, Kind k, const std::string& b): Car(n,p,s,k,b),parkingAssist(false) {}
        void Mazda_drive() const {std::cout << "We are driving Mazda." << std::endl; }
        void Print() const { std::cout << "This is Mazda" << std::endl; }
};

class Airbus final : public Airplane {
        private:
            bool sideStickActive;
        public:
            Airbus(const std::string& n,int p, double s, Kind k, double w1) : Airplane(n,p,s,k,w1),sideStickActive{true} {}
            void Airbus_fly() const {std::cout << "Airbus is flying" << std::endl; }
            void Print() const { std::cout << "This is Airbus" << std::endl; }            
};

class Boeing final : public Airplane {
      private:
            bool electronicFlightBag;
      
     public:
           Boeing(const std::string& n,int p, double s, Kind k, double w1) : Airplane(n,p,s,k,w1),electronicFlightBag{false} {}
           void Boeing_fly() const {std::cout << "Boeing is flying" << std::endl; }
           void Print() const { std::cout << "This is Boeing" << std::endl; }
};

#endif