#ifndef ZOO2_HPP
#define ZOO2_HPP
#include "zoo1.hpp"

class Lion final : public Mammal, public IWalk, public IVoice, public IFeedable {
        private:
            int roarPower;
        public:
            Lion(const std::string& n, Kind k, int r = 50): Mammal(n,k),roarPower{r} {}
            virtual void Print() const override { std::cout << "This is lion" << std::endl; }  
            virtual void walk() const override {std::cout << "Lion walks" << std::endl;}
            virtual void make_sound() const override {std::cout << "Lion roars with power " << roarPower << std::endl; } 
            virtual void feed() override;
            virtual ~Lion() {}
};

class Tiger final : public Mammal, public IWalk, public IVoice, public IFeedable {
        private:
            double jumpHeight;
        public:
            Tiger(const std::string& n, Kind k,double j = 20.5): Mammal(n,k),jumpHeight{j} {}
            void Jump() const { std::cout << "Tiger jumps with height" << jumpHeight << std::endl; }   
            virtual void Print() const override{ std::cout << "This is tiger" << std::endl; }          
            virtual void walk() const override {std::cout << "Tiger walks" << std::endl;}
            virtual void make_sound() const override {std::cout << "Tiger makes sound" << std::endl; } 
            virtual void feed() override;
            virtual ~Tiger() {}
};

class Elephant final : public Mammal,public IWalk, public IVoice, public IFeedable {
        private:
            double trunkLength;
        public:
            Elephant(const std::string& n, Kind k,double t = 12.5):Mammal(n,k), trunkLength{t} {}
            void UseTrunk() const {std::cout << "Elephant's trank length is" << trunkLength << std::endl; } 
            virtual void Print() const override{ std::cout << "This is elephant" << std::endl; }          
            virtual void walk() const override {std::cout << "Elephant walks" << std::endl;}
            virtual void make_sound() const override {std::cout << "Elephant makes sound" << std::endl; } 
            virtual void feed() override;
            virtual ~Elephant() {}
};

class Eagle final : public Bird,public IFly, public IWalk, public IVoice, public IFeedable {
        private:
            double visionRange;
        public:
            Eagle(const std::string& n, Kind k,double w,double v = 20):Bird(n,k,w) , visionRange{v} {}
            void Soar() const {std::cout << "Eagle soares with vision range" << visionRange << std::endl;} 
            virtual void Print() const override { std::cout << "This is eagle" << std::endl; } 
            virtual void fly() const {std::cout << "Eagle flies" << std::endl;}
            virtual void walk() const override {std::cout << "Eagle walks" << std::endl;}
            virtual void make_sound() const override {std::cout << "Eagle makes sound" << std::endl; } 
            virtual void feed() override;
            virtual ~Eagle() {}
};

class Parrot final : public Bird, public IFly, public IWalk, public IVoice, public IFeedable {
        private:
            std::vector<std::string> vocabulary;
        public:
            Parrot(const std::string& n, Kind k,double w);
            virtual void Print() const override { std::cout << "This is parrot" << std::endl; }          
            virtual void fly() const {std::cout << "Parrot flies";}
            virtual void walk() const override {std::cout << "Parrot walks" << std::endl;}
            virtual void make_sound() const override; 
            virtual void feed() override;
            virtual ~Parrot() {}
};

class Snake final : public Reptile, public IWalk, public IVoice, public IFeedable {
        private:
            bool poisonous;
        public:
            Snake(const std::string& n, Kind k): Reptile(n,k),poisonous{1} {}
            virtual void Print() const override { std::cout << "This is snake" << std::endl; }          
            virtual void walk() const override {std::cout << "Snake crawls" << std::endl;}
            virtual void make_sound() const override {std::cout << "Snake is doing hssss" <<std::endl;} 
            virtual void feed() override;
            virtual ~Snake() {}
};

class Crocodile final : public Reptile, public IWalk, public ISwim, public IVoice, public IFeedable {
        private:
            int biteForce;
        public:
            Crocodile(const std::string& n, Kind k,int b = 10): Reptile(n,k),biteForce{b} {}
            void Snap() const{ std::cout << "Crocodile snaps" << std::endl;}
            virtual void Print() const override { std::cout << "This is crocodile" << std::endl; }          
            virtual void walk() const override {std::cout << "Crocodile walks" << std::endl;}
            virtual void swim() const override {std::cout << "Crocodile swims" << std::endl;}
            virtual void make_sound() const override {std::cout << "Crocodile makes voice" <<std::endl;} 
            virtual void feed() override;
            virtual ~Crocodile() {}
};

#endif