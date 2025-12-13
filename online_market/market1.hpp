#ifndef MARKET1_HPP
#define MARKET1_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include "market2.hpp"

class InefficientFunds : public std::runtime_error{
    private:
        std::string message;
    public :
        InefficientFunds(const std::string& m) : std::runtime_error{m}, message{m} {}
        const char* what() const noexcept override{ return message.c_str();}
};

class InvalidAddress : public std::runtime_error{
   private:
        std::string message;
    public :
        InvalidAddress(const std::string& m) : std::runtime_error{m}, message{m} {}
        const char* what() const noexcept override { return message.c_str();}
};

class Order;

class Customer{
    private:
        std::string name;
        double money;
        std::unique_ptr<Order> order;
        std::string address; 
    public:
        Customer() noexcept = default;
        Customer(const std::string& n, double m, const std::string& a);
        std::string getname() const noexcept{return name;}
        double getmoney() const noexcept{return money;}
        const std::unique_ptr<Order>& getorder() const noexcept{return order;}
        std::string getaddress() const noexcept{return address;}
        void print() const;
        void seeorder();
        void makeorder(std::unique_ptr<Order> o);
        void payorder(const std::string& a = "Mamikonyants street");
};

class Order{
    private:
        int id;
        bool received;
        bool paid;
        std::vector<Product> products; 
        double orderprice;
    public:
        Order() noexcept;
        Order(int i, const Product& p);
        int getid()const noexcept{return id;}
        bool IsReceived()const noexcept{return received;}
        std::vector<Product> getorders() const noexcept{return products;}
        double getorderprice() const noexcept{return orderprice;} 
        void print() const; 
        double calculate();
        void add_product() { products.push_back(Jewelry("Earrings","12121345", 12000, Product::Size::Small,"Italy")); }
        void remove_product() { products.pop_back(); }
        void makereceived(){received = true;}
        void makepaid(){ paid = true; }
};

class Market{
    private:
        std::vector<std::unique_ptr<Product>> products;
        std::vector<std::unique_ptr<Customer>> customers;
        std::string name;
    public:
        Market() noexcept = default;
        Market(std::unique_ptr<Product> p, std::unique_ptr<Customer> c, const std::string& n);
        void print() const;
        const std::vector<std::unique_ptr<Product>>& getproducts() const noexcept { return products; }
        const std::vector<std::unique_ptr<Customer>>& getcustomers() const noexcept { return customers; }
        std::string getname() const noexcept { return name; }
        void add_product();
        void remove_product(const std::string& a);
        void serve_customers();
};



#endif