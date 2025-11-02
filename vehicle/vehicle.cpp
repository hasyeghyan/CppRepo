#include "vehicle.hpp"

void Vehicle::PrintInfo() const {
    std::cout << "Name is " << name << " power is " << power << " speed is" << speed << ' ';
    switch(_kind){
            case Kind::Vehicle:
                    std::cout << "This is Vehicle";
                    break;
            case Kind::Car:
                (static_cast<const Car* const>(this))->Print();
                break;
            case Kind::Airplane:
                (static_cast<const Airplane* const>(this))->Print();
                break;
            case Kind::Hyundai:
                (static_cast<const Hyundai* const>(this))->Print();
                break;
            case Kind::Mazda:
                (static_cast<const Mazda* const>(this))->Print();
                break;
            case Kind::Airbus:
                (static_cast<const Airbus* const>(this))->Print();
                break;
            default:
                (static_cast<const Boeing* const>(this))->Print();
    }
}