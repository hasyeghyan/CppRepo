#include "coffee.hpp"

int main() {
    CoffeeShop shop("MyCoffee");
    shop.constructMenu();
    Barista* Mike = new Barista("Mike");
    shop.hireBarista(Mike);
    Customer* John = new Customer("John", 20.0);
    Customer* Anna = new Customer("Anna", 15.0);
    shop.addCustomerToQueue(John);
    shop.addCustomerToQueue(Anna);
    Order* JohnOrder = new Order(1); 
    Drink latte("Latte", Drink::Size::Medium, 3.5);
    JohnOrder->addDrink(latte);
    John->placeOrder(JohnOrder);
    Order* AnnaOrder = new Order(2);
    Drink cappuccino("Cappuccino", Drink::Size::Medium, 4.0); 
    AnnaOrder->addDrink(cappuccino);
    Anna->placeOrder(AnnaOrder);
    shop.serveNextCustomer();
    shop.serveNextCustomer();
    shop.displayShopInfo();
    delete JohnOrder;
    delete AnnaOrder;
    delete John;
    delete Anna;
    delete Mike;
    return 0;
}
