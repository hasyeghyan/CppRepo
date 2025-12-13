#include "market1.hpp"
#include "market2.hpp"

Customer::Customer(const std::string& n = "Hasmik", double m = 20000, const std::string& a = "Azatutyan street") :
    name{n}, money{m}, address{a},order{new Order(20, Product())} {}


void Customer::print() const {
    std::cout << "Customer's name is" << name << ", he/she has " << money << "money" << ", address is" << address;
    order.get()->print();
    std::cout << std::endl;
}

void Customer::seeorder(){
    order.get()->print();
}

void Customer::makeorder(std::unique_ptr<Order> o){
    order = std::move(o);
}

void Customer::payorder(const std::string& a){
    if(order.get()->IsReceived()){
        if(a == address){
          double sum = 0.0;
          sum += order.get()->calculate();
          if(money < sum) throw InefficientFunds("You don't have enough money to pay.");
          else {
          money -= sum;
          order.get()->makepaid();    
         }    
        }
        else throw InvalidAddress("The order is on wrong address");
    }
    else std::cout << "Order hasn't arrived yet." << std::endl;
}

Order::Order() noexcept {
    id = 0;
    received = false;
    paid = false;
    orderprice = 0;
}

Order::Order(int i, const Product& p) : id{i}{
    products.push_back(p);
    received = false;
    paid = false;
}

void Order::print() const {
    std::cout << "Id is" << id << ", orderprice is" << orderprice;
    if(received) std::cout << ", product received";
    else std::cout << ", product  not received";
    if(paid) std::cout << ", order is paid";
    else std::cout << ", order is not paid";
    for(int i{}; i < products.size(); ++i){
        products[i].print();
    }
}

double Order::calculate() {
    orderprice = 0;
    for(int i{}; i < products.size(); ++i){
        orderprice += products[i].getprice();
    }
    return orderprice;
}

Market::Market(std::unique_ptr<Product> p, std::unique_ptr<Customer> c, const std::string& n) : name{n} {
    products.push_back(std::move(p));
    customers.push_back(std::move(c));
}

void Market::add_product(){
   std::unique_ptr<Product> p {new Food()};
   products.push_back(std::move(p));
}

void Market::remove_product(const std::string& a){
    for(int i{}; i < products.size(); ++i){
        if(products[i].get()->getarticul() == a){
            products.erase(products.begin() + i);
            --i;
        }
    }
}

void Market::serve_customers(){
    for(int i{}; i < customers.size(); ++i){
        customers[i].get()->makeorder(std::move(std::unique_ptr<Order> (new Order)));
        customers[i].get()->payorder();
    }
    
}
