#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

inline static long long initial_cardnumber = 3756489152643275;

class BankException : public std::runtime_error{
    std::string message;
    public:
        BankException(const std::string& m = "BankException") : runtime_error(m), message{m} {}
        virtual const char* what() const noexcept override {return message.c_str();}
};

class NegativeAmmount : public BankException {
    public:
       NegativeAmmount(const std::string& m = "NegativeAmmount") : BankException(m) {}
};

class InsufficientFunds : public BankException {
    public:
        InsufficientFunds(const std::string& m = "InsufficientFunds") : BankException(m) {}
};

class AccountNotFound : public BankException {
    public:
        AccountNotFound(const std::string& m = "AccountNotFound") : BankException(m) {}
};


class BankAccount {
    protected:
        std::string cardNumber;
        double balance;
        std::string Name;
    public:
        BankAccount(const std::string& c = "124512451245", double b = 15000, const std::string& n = "Unknown") : cardNumber{c}, balance{b}, Name{n} {}
        BankAccount(const BankAccount& oth) = delete;
        BankAccount& operator=(const BankAccount& oth) = delete;
        BankAccount(BankAccount&& oth) noexcept;
        BankAccount& operator=(BankAccount&& oth) noexcept;
        virtual ~BankAccount() = default;
        virtual void display() const noexcept = 0;
        double getBalance() const {return balance;}
        std::string getcardNumber() const {return cardNumber;}
        virtual void withdraw(double b) = 0;
        virtual void deposit(double b) = 0;
};

class CheckingAccount : public BankAccount {
    private:
        double overdraft;
    public:
        CheckingAccount(const std::string& c, double b, const std::string& n, double o): BankAccount(c,b,n), overdraft{o}{}
        CheckingAccount(const CheckingAccount& oth) = delete;
        CheckingAccount& operator=(const CheckingAccount& oth) = delete;
        CheckingAccount(CheckingAccount&& oth) noexcept;
        CheckingAccount& operator=(CheckingAccount&& oth) noexcept;
        virtual void display() const noexcept override;
        virtual void withdraw(double b) override;
        virtual void deposit(double b) override;
};

class SavingsAccount : public BankAccount {
    private:
        int rate;
    public:
        SavingsAccount(const std::string& c, double b, const std::string& n, double r): BankAccount(c,b,n), rate{r}{}
        SavingsAccount(const SavingsAccount& oth) = delete;
        SavingsAccount& operator=(const SavingsAccount& oth) = delete;
        SavingsAccount(SavingsAccount&& oth) noexcept;
        SavingsAccount& operator=(SavingsAccount&& oth) noexcept;
        virtual void display() const noexcept override;
        virtual void withdraw(double b) override;
        virtual void deposit(double b) override;
        void update();
};

class Bank {
    private:
        std::vector <BankAccount*> bank;
        int n = 0;
    public:
        Bank() = default;
        ~Bank();
        std::string generate_card();
        void transfer(const std::string& from,const std::string& to, double b);
        std::string CreateChecking() {std::string gn = generate_card(); bank.push_back(new CheckingAccount(gn, 150000, "Has" + std::to_string(n++), 10000)); return gn;}
        std::string CreateSavings() {std::string gn = generate_card();bank.push_back(new SavingsAccount(gn, 200000, "An" + std::to_string(n++), 25000)); return gn;}
        BankAccount& operator[](const std::string& c);
};

#endif