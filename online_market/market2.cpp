#include "market1.hpp"
#include "market2.hpp"

void Product::print() const {
    std::cout << "Name is" << name << ", articul is" << articul << ", price is" << price << ", size is" << ", producer is" 
    << producer << ", size is";
    switch(size){
        case Size::Big:
                std::cout << " big"; break;
        case Size::Medium:
                std::cout << " medium"; break;
        case Size::Small:
                std::cout << " small"; break;
    }
    std::cout << std::endl;
}

void Jewelry::print() const {
    std::cout << "Name is" << name << ", articul is" << articul << ", price is" << price << ", size is" << ", producer is" 
    << producer << ", size is";
    switch(size){
        case Size::Big:
                std::cout << " big"; break;
        case Size::Medium:
                std::cout << " medium"; break;
        case Size::Small:
                std::cout << " small"; break;
    }
    std::cout << "Metal is";
     switch(metal){
        case Metal::Gold:
                std::cout << " gold"; break;
        case Metal::Silver:
                std::cout << " silver"; break;
        case Metal::Biju:
                std::cout << " biju"; break;
    }
    std::cout << std::endl;
}

void Food::print() const {
    std::cout << "Name is" << name << ", articul is" << articul << ", price is" << price << ", size is" << ", producer is" 
    << producer << ", size is";
    switch(size){
        case Size::Big:
                std::cout << " big"; break;
        case Size::Medium:
                std::cout << " medium"; break;
        case Size::Small:
                std::cout << " small"; break;
    }
    if(isfresh()) std::cout << ", food is fresh";
    else std::cout << ", food is not fresh";
    std::cout << std::endl;
}

void Clothes::print() const{
    std::cout << "Name is" << name << ", articul is" << articul << ", price is" << price << ", size is" << ", producer is" 
    << producer << ", size is";
    switch(size){
        case Size::Big:
                std::cout << " big"; break;
        case Size::Medium:
                std::cout << " medium"; break;
        case Size::Small:
                std::cout << " small"; break;
    }
    std::cout << ", fabric is" << fabric << std::endl;
}