#include "bank.hpp"


int main() {
    Bank myBank;

    std::string card0 = myBank.CreateChecking();
    std::string card1 = myBank.CreateChecking();
    std::string card2 = myBank.CreateSavings();
    std::string card3 = myBank.CreateSavings();

    try {
        std::cout << "Initial account info:\n";
        myBank[card0].display();
        myBank[card1].display();
        myBank[card2].display();
        myBank[card3].display();

        std::cout << "\nDepositing money...\n";
        myBank[card0].deposit(5000);  
        myBank[card2].deposit(10000);

        std::cout << "\nWithdrawing money...\n";
        myBank[card1].withdraw(2000);
        myBank[card3].withdraw(5000); 

        std::cout << "\nTransferring money...\n";
        myBank.transfer(card0, card2, 2000);

        std::cout << "\nUpdating savings accounts...\n";
        dynamic_cast<SavingsAccount&>(myBank[card2]).update();
        dynamic_cast<SavingsAccount&>(myBank[card3]).update();

        std::cout << "\nFinal account info:\n";
        myBank[card0].display();
        myBank[card1].display();
        myBank[card2].display();
        myBank[card3].display();

    } catch (const NegativeAmmount& e) {
        std::cout << "Error: " << e.what() << '\n';
    } catch (const InsufficientFunds& e) {
        std::cout << "Error: " << e.what() << '\n';
    } catch (const AccountNotFound& e) {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
