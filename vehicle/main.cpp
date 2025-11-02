#include "vehicle.hpp"

int main(){
    Hyundai* h = new Hyundai("Hyundai", 100, 20.5, Kind::Hyundai, "japanese");
    Mazda* m = new Mazda("Mazda", 150, 35.4, Kind::Mazda, "japanese");
    Airbus* a = new Airbus("Airbus", 145, 60.5, Kind::Airbus, 12.5);
    Boeing* b = new Boeing("Boeing", 160, 15.5, Kind::Boeing, 56.5);

    std::vector<Vehicle*> vehicles {h, m, a, b};
    for(Vehicle* v : vehicles){
        v->PrintInfo();
    }

    return 0;
}