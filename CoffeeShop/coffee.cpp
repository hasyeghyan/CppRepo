#include "coffee.hpp"

void Drink::display() const{
        std::cout << "Drink's name is " << name << ", price is " << price << ", volume is ";
        switch(volume){
            case Size::Small: std::cout << "small";
                               break;            
            case Size::Medium: std::cout << "medium";
                                break;
            case Size::Big: std::cout << "big";
        }
         std::cout << std::endl;
}

void Barista::prepareOrder(Order* order){
        if(!order){
          std::cout << "Invalid order.";
          std::exit(1);
        }
        order->calculateTotalPrice();
        std::cout << "Total price of order is " << order->getTotalPrice() << std::endl;
        order->markPrepared();
        std::cout << "Order is ready." << std::endl;
        order->displayOrder();
}

Order::Order(): orderId{0},totalPrice{0.0},isPrepared(false),isPaid(false){}

void Order::removeDrink(int index){
     if(index < 0 || index >= drinks.size()){
        std::cout << "Invalid index.";
        std::exit(1);
     }
     drinks.erase(drinks.begin() + index); 
}

void Order::calculateTotalPrice(){
        totalPrice = 0.0;
        for(int i{}; i < drinks.size(); ++i){
            totalPrice += drinks[i].getPrice();
        }
}

void Order::displayOrder() const{
     std::cout << "OrderId is " << orderId << ", totalPrice is " << totalPrice << "drinks are ";
      for(int i{}; i < drinks.size(); ++i){
          drinks[i].display();
       }
       if(isPrepared) std::cout << ", Order is prepared. ";
       else std::cout << ", Order is not yet prepared. ";
       if(isPaid) std::cout << "Order is paid. ";
       else std::cout << "Order is not paid. ";
       std::cout << std::endl;
}
 void Customer::payOrder(){
        if(currentOrder && !currentOrder-> getIsPaid()){
           currentOrder-> markPaid();
        }
 }

void Customer::display() const{
        std::cout << "Customer's name is "  << name << ", balance is " << balance << "order is " ;
        viewOrder();
        std::cout << std::endl;
}

void CoffeeShop::removeDrink(const std::string& drinkName){
        bool flag = false;
        for(int i{}; i < menu.size(); ++i){
           if(menu[i] -> getName() == drinkName){
                delete menu[i];
                menu.erase(menu.begin() + i);
                flag = true;
                --i;
           }
        }
        if(!flag)
          std::cout << "No such drink in menu to remove." << std::endl;
        return;
}

void CoffeeShop::showMenu() const{
        std::cout << "Menu is ";
        for(int i{}; i < menu.size(); ++i){
           menu[i]->display();
        }
}

void CoffeeShop::fireBarista(Barista* barista){
        bool flag = false;
        for(int i{}; i < baristas.size(); ++i){
           if(baristas[i]->getName() == barista->getName()){
              delete[] baristas[i];
              baristas.erase(baristas.begin() + i);
              --i;
              flag = true;
           }
        }
        if(!flag){
                std::cout << "No such barista to remove." << std::endl;
        }
        return;
}

void CoffeeShop::showBaristas() const{
     std::cout << "Baristas are ";
     for(int i{}; i < baristas.size(); ++i){
        std::cout << baristas[i]-> getName() << ",";
     } 
     std::cout << std::endl;
}

void CoffeeShop::serveNextCustomer(){
        if(queue.size() == 0){
                std::cout << "No customer to serve." << std::endl;
                return;
        }
        Customer* c = queue.front();
        if(c->getCurrentOrder())
          baristas[0]->prepareOrder(c->getCurrentOrder());
        c->payOrder();
        queue.erase(queue.begin());
}

void CoffeeShop::showQueue() const{
      std::cout << "Customers are ";
      for(int i{}; i < queue.size(); ++i){
        std::cout <<  queue[i]-> getName() << ",";
     } 
     std::cout << std::endl;  
}
void CoffeeShop::constructMenu(){
        Drink* Latte = new Drink("Latte", Drink::Size::Big, 1200);
        Drink* Capuchino = new Drink("Capuchino", Drink::Size::Small, 1300);
        Drink* Americano = new Drink("Americano", Drink::Size::Medium, 1000);
        menu.push_back(Latte);
        menu.push_back(Capuchino);
        menu.push_back(Americano);
}

void CoffeeShop::displayShopInfo() const{
        std::cout << "Name is " << shopName << " ";
        showBaristas();
        showQueue();
        showMenu();
}

