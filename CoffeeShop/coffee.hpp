#ifndef COFFEE_HPP
#define COFFEE_HPP

#include <iostream>
#include <string>
#include <vector>

class Drink {
public:
    enum class Size { Small, Medium, Big };
private:
    std::string name;
    Size volume;
    double price;
public:
    Drink() = default;
    Drink(const std::string& _name, Size _volume, double _price): name(_name), volume(_volume), price(_price){}
    std::string getName() const{return name;}
    Size getVolume() const{return volume;}
    double getPrice() const{return price;}
    void setName(const std::string& newName){name = newName;}
    void setVolume(Size newVolume){volume = newVolume;}
    void setPrice(double newPrice){price = newPrice;}
    void display() const;
};


class Order {
private:
    int orderId;
    std::vector<Drink> drinks;
    double totalPrice;
    bool isPrepared;
    bool isPaid;

public:
    Order();
    Order(int id): orderId{id} {}
    int getOrderId() const{ return orderId; }
    double getTotalPrice() const{ return totalPrice; }
    bool getIsPrepared() const{ return isPrepared; }
    bool getIsPaid() const{ return isPaid; }
    void addDrink(const Drink& drink){ drinks.push_back(drink); }
    void removeDrink(int index);
    void calculateTotalPrice();
    void markPrepared(){ isPrepared = true;}
    void markPaid(){ isPaid = true;}
    void displayOrder() const;
};

class Barista {
private:
    std::string name;

public:
    Barista() = default;
    Barista(const std::string& _name): name(_name){}
    std::string getName() const{return name;}
    void setName(const std::string& newName){name = newName;}
    void prepareOrder(Order* order);
    void greetCustomer() const{std::cout << "Hello, may I take your order?" << std::endl;}
};

class Customer {
private:
    std::string name;
    double balance;
    Order* currentOrder; 

public:
    Customer() = default;
    Customer(const std::string& _name, double _balance): name(_name), balance(_balance){}
    std::string getName() const{ return name;}
    double getBalance() const{ return balance;}
    Order* getCurrentOrder() const { return currentOrder;}
    void setBalance(double newBalance){ balance = newBalance;}
    void placeOrder(Order* order){currentOrder = order;}
    void payOrder();
    void viewOrder() const{ currentOrder->displayOrder();}
    void display() const;
};

class CoffeeShop {
private:
    std::string shopName;
    std::vector<Drink*> menu;
    std::vector<Barista*> baristas; 
    std::vector<Customer*> queue; 
public:
    CoffeeShop() = default;
    CoffeeShop(const std::string& name): shopName{name}{}
    std::string getName() const{ return shopName;}
    void setName(const std::string& newName){ shopName = newName;}
    void addDrink(Drink* drink){ menu.push_back(drink);}
    void removeDrink(const std::string& drinkName);
    void showMenu() const;
    void hireBarista(Barista* barista){baristas.push_back(barista);}
    void fireBarista(Barista* barista);
    void showBaristas() const;
    void addCustomerToQueue(Customer* customer){ queue.push_back(customer);}
    void serveNextCustomer();
    void showQueue() const;
    void constructMenu();
    void displayShopInfo() const;
};

#endif