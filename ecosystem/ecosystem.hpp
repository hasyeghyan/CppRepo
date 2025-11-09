#ifndef ECOSYSTEM_HPP
#define ECOSYSTEM_HPP

#include <string>
#include <vector>
#include <iostream>

class  Serializable {
    public:
        virtual std::string serialize() const = 0; 
};

class Entity {
    protected:
        std::string name;
        int energy;
    public:
        Entity(std::string n, int e) : name{n}, energy{e} {}
        virtual void act() = 0;
        virtual void move() = 0;
        virtual std::string info() const = 0;
        virtual ~Entity() { std::cout << "Entity destructer called." << std::endl; }
};

class Animal : public Entity, public Serializable {
    private:
        std::string status;
    public:
        Animal(std::string n, int e,std::string s) : Entity(n,e), status{s} {}
        virtual void act() override { std::cout << "Wolf hunts for food." << std::endl; }
        virtual void move() override { --energy; std::cout << "Animal moves" << std::endl; }
        virtual std::string info() const override { return "Animal " + name + " has " +  std::to_string(energy) + " energy "+ " and status is " + status; }
        std::string serialize() const override {
            return "{ \"type\": \"Animal\", \"name\": \"" + name + 
               "\", \"energy\": " + std::to_string(energy) + 
               ", \"status\": \"" + status + "\" }";
        }
        virtual ~Animal() {std::cout << "Animal destructer called." << std::endl; }
};

class Drone : public Entity, public Serializable {
    private:
        std::string status;
    public:
        Drone (std::string n, int e, std::string s) : Entity(n,e), status{s} {}
        virtual void act() override { std::cout << "Drone scans the area." << std::endl; }
        virtual void move() override { energy -= 5; }
        virtual std::string info() const override { return "Drone " + name + " has " +  std::to_string(energy) + " energy " + " and status is " + status; }
        std::string serialize() const override {
            return "{ \"type\": \"Drone\", \"name\": \"" + name + 
               "\", \"energy\": " + std::to_string(energy) + 
               ", \"status\": \"" + status + "\" }";
        }
        virtual ~Drone() {std::cout << "Drone destructer called." << std::endl; }
};

class Robot : public Entity {
    private:
        std::string status;
    public:
        Robot (std::string n, int e, std::string s): Entity(n,e), status{s} {}
        virtual void act() override { std::cout << "Robot optimizes logistics" << std::endl; }
        virtual void move() override { energy -= 10; }
        virtual std::string info() const override { return "Robot " + name + " has " +  std::to_string(energy) + " energy " + " and status is " + status; }
        virtual ~Robot() {std::cout << "Robot destructer called." << std::endl; }
};




#endif