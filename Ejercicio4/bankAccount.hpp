#pragma once
#include <string>
using namespace std;

class Account{
protected:
    double balance;
    string accountOwner;
    int shows;
public:
    virtual void deposit(double amount);
    virtual void draw(double amount, Account &savings) = 0;
    virtual void showInfo() = 0; 
    virtual ~Account() = default;
};

class savingsAccount : public Account{
    friend class currentAccount;
public:
    savingsAccount(string _accountOwner, double _balance = 0);
    void draw(double amount, Account &savings) override;
    void showInfo() override;
};

class currentAccount : public Account{
public:
    currentAccount(string _accountOwner, double _balance = 0);
    void draw(double amount, Account &savings) override;
    void showInfo() override;
};