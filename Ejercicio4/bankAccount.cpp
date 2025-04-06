#include "bankAccount.hpp"
#include <iostream>

void Account::deposit(double amount){
    if (amount<=0){throw invalid_argument("El monto a depositar es inválido");}
    this->balance += amount;
}

savingsAccount::savingsAccount(double _balance, string _accountOwner) {
if (_balance < 0){throw invalid_argument("El monto es inválido");}
    this->balance = _balance;
    this->accountOwner = _accountOwner;
    this->shows = 0;
};

void savingsAccount::draw(double amount){
    if (amount > this->balance){
        throw invalid_argument("No se puede retirar mas dinero del disponible en la caja de ahorro");
    }
    this->balance -= amount;
}

void savingsAccount::showInfo(){
    this->shows += 1; 
    if (shows > 2){ // mas de dos veces, o sea a la tercera
        this->balance -= 20; // ES UN IGUAL A 3 O UN MAYOR A DOS?? VER SI SOLO SE DESCUENTA UNA VEZ O SIEMPRE LUEGO DE LA 2DA.
    }
    cout<<"====== CAJA DE AHORRO ======"<<endl<<"Balance: "<<this->balance<<endl<<"Titular: "<<this->accountOwner<<endl;
}

currentAccount::currentAccount(double _balance = 0, string _accountOwner){
    if (_balance < 0){throw invalid_argument("El monto es inválido");}
    this->balance = _balance;
    this->accountOwner = _accountOwner;
    this->shows = 0;
}
void currentAccount::draw(double amount){
    if (amount > this->balance){
        int balanceCajaAhorro = 123123;
        if ((amount - this->balance) < balanceCajaAhorro){
            balanceCajaAhorro -= amount - this->balance;
            this->balance = 0;
        }
        throw invalid_argument("La cuenta no posee dinero suficiente para la extracción");
    }
}
void currentAccount::showInfo(){
    cout<<"====== CCUENTA CORRIENTE ======"<<endl<<"Balance: "<<this->balance<<endl<<"Titular: "<<this->accountOwner<<endl;
}