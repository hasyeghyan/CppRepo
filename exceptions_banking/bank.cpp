#include "bank.hpp"

BankAccount::BankAccount(BankAccount&& oth) noexcept: cardNumber{oth.cardNumber}, balance{oth.balance}, Name{oth.Name} {
    oth.cardNumber = "0";
    oth.balance = -1;
    oth.Name = "Unknown";
}

BankAccount& BankAccount::operator=(BankAccount&& oth) noexcept{
    if(this !=&oth){
        cardNumber = oth.cardNumber;
        balance = oth.balance;
        Name = oth.Name;
        oth.cardNumber = "0";
        oth.balance = -1;
        oth.Name = "Unknown";
    }
    return *this;
}

CheckingAccount::CheckingAccount(CheckingAccount&& oth) noexcept : BankAccount(std::move(oth)) {
    overdraft = oth.overdraft;
    oth.overdraft = -1; 
}

CheckingAccount& CheckingAccount::operator=(CheckingAccount&& oth) noexcept{
    if(this != &oth){
       this->BankAccount::operator=(std::move(oth));

       overdraft = oth.overdraft;
       oth.overdraft = -1;
    }
    return *this;
}

void CheckingAccount::display() const noexcept {
    std::cout << "Person's name is " << Name << " ,his/her cardNumber is" << cardNumber << " balance is" << balance 
    << " and overdraft is" << overdraft << std::endl;
}

void CheckingAccount::withdraw(double b) {
    if(b < 0) throw  NegativeAmmount("Cant withdraw neagtive amount");
    if(balance < b) throw InsufficientFunds("You dont ahve enough balance for withdrawing");
    if((balance - b) < -overdraft) throw InsufficientFunds("You can't pass overdraft amount");
    balance -= b;
}

void CheckingAccount::deposit(double b) {
    if(b < 0) throw  NegativeAmmount("Cant deposit neagtive amount");
    balance += b;
}

SavingsAccount::SavingsAccount(SavingsAccount&& oth) noexcept : BankAccount(std::move(oth)) {
    rate = oth.rate;
    oth.rate = -1; 
}

SavingsAccount& SavingsAccount::operator=(SavingsAccount&& oth) noexcept{
    if(this != &oth){
       this->BankAccount::operator=(std::move(oth));
       rate = oth.rate;
       oth.rate = -1;
    }
    return *this;
}

void SavingsAccount::display() const noexcept {
    std::cout << "Person's name is " << Name << " ,his/her cardNumber is" << cardNumber << " balance is" << balance 
    << " and rate is" << rate << std::endl;
}

void SavingsAccount::update() {
    balance += balance * rate/100;
}

void SavingsAccount::withdraw(double b) {
    if(b < 0) throw  NegativeAmmount("Cant withdraw neagtive amount");
    if(balance < b) throw InsufficientFunds("You dont ahve enough balance for withdrawing");
    balance -= b;
}

void SavingsAccount::deposit(double b) {
    if(b < 0) throw  NegativeAmmount("Cant deposit neagtive amount");
    balance += b;
}

Bank::~Bank() {
    for(BankAccount* ptr : bank){
       delete ptr;
    }
}

void Bank::transfer(const std::string& from,const std::string& to, double b){
    BankAccount* fromAccount = nullptr;
    BankAccount* toAccount = nullptr;

    for (BankAccount* ptr : bank) {
        if (ptr->getcardNumber() == from)
            fromAccount = ptr;
        if (ptr->getcardNumber() == to)
            toAccount = ptr;
    }

    if (!fromAccount)
        throw AccountNotFound("Source account not found");
    if (!toAccount)
        throw AccountNotFound("Destination account not found");

    fromAccount->withdraw(b);
    toAccount->deposit(b);
}

BankAccount& Bank::operator[](const std::string& c){
    for(BankAccount* ptr : bank){
        if(ptr->getcardNumber() == c){
            return *ptr;
        }
    }
    throw AccountNotFound("There is no account with that card number"); 
}

std::string Bank::generate_card(){
    long long  res = initial_cardnumber;
    std::string str;
    while(res){
        long long temp = res % 10000;
        res /= 10000;
        str += std::to_string(temp);
        str += '_';
    }
    if(!str.empty()) str.pop_back();
    ++initial_cardnumber;
    return str;
}
