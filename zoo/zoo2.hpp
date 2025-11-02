#ifndef ZOO2_HPP
#define ZOO2_HPP
#include "zoo1.hpp"

class Lion final : public Mammal {
        private:
            int roarPower;
        public:
            Lion(const std::string& n, Kind k, int r = 50): Mammal(n,k),roarPower{r} {}
            void Roar() const {std::cout << "Lion roars with power " << roarPower << std::endl; } 
            void Print() const { std::cout << "This is lion" << std::endl; }          
    
};

class Tiger final : public Mammal {
        private:
            double jumpHeight;
        public:
            Tiger(const std::string& n, Kind k,double j = 20.5): Mammal(n,k),jumpHeight{j} {}
            void Jump() const { std::cout << "Tiger jumps with height" << jumpHeight << std::endl; }   
            void Print() const { std::cout << "This is tiger" << std::endl; }          
        
};

class Elephant final : public Mammal {
        private:
            double trunkLength;
        public:
            Elephant(const std::string& n, Kind k,double t = 12.5):Mammal(n,k), trunkLength{t} {}
            void UseTrunk() const {std::cout << "Elephant's trank length is" << trunkLength << std::endl; } 
            void Print() const { std::cout << "This is elephant" << std::endl; }          
     
};

class Eagle final : public Bird {
        private:
            double visionRange;
        public:
            Eagle(const std::string& n, Kind k,double w,double v = 20):Bird(n,k,w) , visionRange{v} {}
            void Soar() const {std::cout << "Eagle soares with vision range" << visionRange << std::endl;} 
            void Print() const { std::cout << "This is eagle" << std::endl; }              
};

class Parrot final : public Bird {
        private:
            std::vector<std::string> vocabulary;
        public:
            Parrot(const std::string& n, Kind k,double w);
            void Speak() const;
            void Print() const { std::cout << "This is parrot" << std::endl; }          
      
};

class Snake final : public Reptile {
        private:
            bool poisonous;
        public:
            Snake(const std::string& n, Kind k): Reptile(n,k),poisonous{1} {}
            void Hiss() const {std::cout << "Snake is doing hssss" <<std::endl;} 
            void Print() const { std::cout << "This is snake" << std::endl; }          
     
};

class Crocodile final : public Reptile {
        private:
            int biteForce;
        public:
            Crocodile(const std::string& n, Kind k,int b = 10): Reptile(n,k),biteForce{b} {}
            void Snap() const{ std::cout << "Crocodile snaps" << std::endl;}
            void Print() const { std::cout << "This is crocodile" << std::endl; }          
      
};

#endif