#include "bankAccount.hpp"
#include <iostream>

int main(){
    cout<<"====== PRUEBAS: CUENTA DE BANCO ======"<<endl;
    cout<<endl<<"1. Se crea una cuenta bancaria para Juan García con $500"<<endl;

    savingsAccount ca_Juan("Juan García",500);
    currentAccount cc_Juan("Juan García",500);

    ca_Juan.showInfo();
    cc_Juan.showInfo();

    cout<<endl<<"2. Se depositan $100 en la cuenta corriente y $50 en la caja de ahorro"<<endl;    
    ca_Juan.deposit(50);
    cc_Juan.deposit(100);

    ca_Juan.showInfo();
    cc_Juan.showInfo();

    cout<<endl<<"3. Se extraen $30 de la caja de ahorro y el sistema debita $20 por mostrar más de dos veces la información (-$50)"<<endl;  
    ca_Juan.draw(30,ca_Juan);
    
    ca_Juan.showInfo();
    cc_Juan.showInfo();

    cout<<endl<<"4. Se extraen $100 de la cuenta corriente y el sistema debita $20 de la caja de ahorro por mostrar más de dos veces la información"<<endl; 
    cc_Juan.draw(100,ca_Juan);
    
    ca_Juan.showInfo();
    cc_Juan.showInfo();

    cout<<endl<<"5. Se extraen $550 de la cuenta corriente y el sistema toma dinero de la caja de ahorro porque no hay suficiente en la cuenta corriente y debita $20 de la caja de ahorro por mostrar más de dos veces la información (-$70 de la caja de ahorro)"<<endl; 
    cc_Juan.draw(550,ca_Juan);
    
    ca_Juan.showInfo();
    cc_Juan.showInfo();

    cout<<endl<<"6. Se extraen $500 de la cuenta corriente y el sistema intenta tomar dinero de la caja de ahorro pero no hay suficiente"<<endl; 
    
    cc_Juan.draw(550,ca_Juan);

    return 0;
}