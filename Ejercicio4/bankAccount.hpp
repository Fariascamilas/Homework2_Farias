#pragma once
#include <string>
using namespace std;

class Account{
protected:
    double balance;
    string accountOwner;
    int shows;

    virtual void deposit(double amount);
    virtual void draw(double amount) = 0;
    virtual void showInfo() = 0; 
    virtual ~Account() = default;
};

class savingsAccount : public Account{
private:
    savingsAccount(double _balance = 0, string _accountOwner);
    void draw(double amount) override;
    void showInfo() override;
};

class currentAccount : public Account{
protected:
    currentAccount(double _balance = 0, string _accountOwner);
    void draw(double amount) override;
    void showInfo() override;
};