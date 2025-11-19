#include "zoo1.hpp"
#include "zoo2.hpp"

int main(){
    Lion* simba = new Lion("Simba",Kind::Lion,52);
    Tiger* tony = new Tiger("Tony",Kind::Tiger,12.2);
    Eagle* aquila = new Eagle("Aquila", Kind::Eagle,12.5,22.5);
    Snake* sly = new Snake("Sly", Kind::Snake);
    
    std::vector<Animal*> animals {simba, tony, aquila, sly};
    for(Animal* a : animals){
        if(IFly* ptr1 = dynamic_cast<IFly*> (a)) ptr1->fly();
        if(ISwim* ptr2 = dynamic_cast<ISwim*> (a)) ptr2->swim();
        if(IWalk* ptr3 = dynamic_cast<IWalk*> (a)) ptr3->walk();
        if(IVoice* ptr4 = dynamic_cast<IVoice*> (a)) ptr4->make_sound();
        if(IFeedable* ptr5 = dynamic_cast<IFeedable*> (a)) ptr5->feed();
    }
    return 0;
}

