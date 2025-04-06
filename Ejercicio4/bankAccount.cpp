#include "bankAccount.hpp"
#include <iostream>

void Account::deposit(double amount){
    if (amount<=0){throw invalid_argument("El monto a depositar es inválido");}
    this->balance += amount;
}

savingsAccount::savingsAccount(string _accountOwner, double _balance) {
if (_balance < 0){throw invalid_argument("El monto es inválido");}
    this->balance = _balance;
    this->accountOwner = _accountOwner;
    this->shows = 0;
};

void savingsAccount::draw(double amount, Account &savings){
    if (amount > this->balance){
        throw invalid_argument("No se puede retirar mas dinero del disponible en la caja de ahorro");
    }
    this->balance -= amount;
}

void savingsAccount::showInfo(){
    this->shows += 1; 
    if (shows > 2){  
        this->balance -= 20; 
    }
    cout<<"====== CAJA DE AHORRO ======"<<endl<<"Balance: "<<this->balance<<endl<<"Titular: "<<this->accountOwner<<endl;
}

currentAccount::currentAccount(string _accountOwner, double _balance){
    if (_balance < 0){throw invalid_argument("El monto es inválido");}
    this->balance = _balance;
    this->accountOwner = _accountOwner;
    this->shows = 0;
}
void currentAccount::draw(double amount, Account &savings){
    if (amount > this->balance){
        savingsAccount* sa = dynamic_cast<savingsAccount*>(&savings);
        if (!sa){throw invalid_argument("La dirección no corresponde a una caja de ahorro");}
        if (sa->accountOwner != this->accountOwner){throw invalid_argument("El titular de la caja de ahorro no coincide con el de la cuenta corriente");}
        if ((amount - this->balance) < sa->balance){
            sa->balance -= (amount - this->balance);
            this->balance = 0;
            return;
        }
        throw invalid_argument("La cuenta no posee dinero suficiente para la extracción");
    }
    this->balance -= amount;
}
void currentAccount::showInfo(){
    cout<<"====== CCUENTA CORRIENTE ======"<<endl<<"Balance: "<<this->balance<<endl<<"Titular: "<<this->accountOwner<<endl;
}