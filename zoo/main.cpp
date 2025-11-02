#include "zoo1.hpp"
#include "zoo2.hpp"

int main(){
    Lion* simba = new Lion("Simba",Kind::Lion,52);
    Tiger* tony = new Tiger("Tony",Kind::Tiger,12.2);
    Eagle* aquila = new Eagle("Aquila", Kind::Eagle,12.5,22.5);
    Snake* sly = new Snake("Sly", Kind::Snake);
    
    std::vector<Animal*> animals {simba, tony, aquila, sly};
    for(Animal* a : animals){
        a->PrintInfo();
    }
    return 0;
}