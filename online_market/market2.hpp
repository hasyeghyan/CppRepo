#ifndef MARKET2_HPP
#define MARKET2_HPP

#include "market1.hpp"


class Product{
    public:
        enum class Size{Big, Medium, Small};
    protected:
        std::string name;
        std::string articul;
        double price;
        Size size;
        std::string producer;
    public:
        Product(std::string n = "Food", std::string  a = "12458796", double p = 15500,Size s = Size::Big, std::string pr = "Russia") : name{n}, articul{a}, price{p}, size{s}, producer{pr} {}
        std::string getname() const noexcept {return name;}
        std::string getarticul() const noexcept { return articul; }
        int getprice() const noexcept{ return price; }
        Size getsize() const noexcept { return size; }
        std::string getproducer()  const noexcept{ return producer; }
        virtual void print() const;
}; 

class Jewelry : public Product{
    public:
        enum class Metal{Gold, Silver, Biju};
    private:
        Metal metal;
    public:
        Jewelry(std::string n = "Necklace", std::string  a = "54758796", double p = 4000,Size s = Size::Medium, std::string pr = "Italy", Metal m = Metal::Biju) : Product(n,a,p,s,pr), metal{m} {}
        virtual void print() const override;
        Metal getmetal() const noexcept { return metal; }
};

class Food : public Product{
    private:
        bool fresh;
    public:
        Food(std::string n = "Fish", std::string  a = "54545796", double p = 3000,Size s = Size::Medium, std::string pr = "Armenia") : Product(n,a,p,s,pr) { fresh = false;}
        virtual void print() const  override;
        bool isfresh() const noexcept { return fresh; }
};

class Clothes : public Product{
    private:
        std::string fabric;
    public:
        Clothes(std::string n = "Jeans", std::string  a = "54758715", double p = 6500,Size s = Size::Small, std::string pr = "Spain", std::string f = "cotton") : Product(n,a,p,s,pr), fabric{f} {}
        virtual void print() const override;
        std::string getfabric() const noexcept { return fabric; }
};

#endif