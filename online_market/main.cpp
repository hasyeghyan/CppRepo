#include "market1.hpp"
#include "market2.hpp"



int main() {
    try {
        std::unique_ptr<Product> p1 = std::make_unique<Food>(
            "Fish", "11122233", 3000, Product::Size::Medium, "Armenia"
        );

        std::unique_ptr<Customer> c1 = std::make_unique<Customer>(
            "Hasmik", 20000, "Azatutyan street"
        );

        Market m(std::move(p1), std::move(c1), "Online Market");

        m.print();
        m.serve_customers();
    }
    catch (const InefficientFunds& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const InvalidAddress& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
