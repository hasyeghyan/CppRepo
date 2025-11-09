#include "ecosystem.hpp"


int main() {
    std::vector<Entity*> ecosystem;
    std::vector<Serializable*> serializables;

    Animal* a = new Animal("Wolf", 100, "Idle");
    Drone* d = new Drone("Alpha", 50, "Idle");
    Robot* r = new Robot("Robo1", 200, "Idle");


    ecosystem.push_back(a);
    ecosystem.push_back(d);
    ecosystem.push_back(r);

    serializables.push_back(a);
    serializables.push_back(d);

    for (Entity* e : ecosystem) {
        e->act();
        e->move();
        std::cout << e->info() << std::endl;
    }

    for (Serializable* s : serializables) {
        std::cout << "Serialized: " << s->serialize() << std::endl;
    }

    for (Entity* e : ecosystem) {
        delete e;
    }

    return 0;
}
