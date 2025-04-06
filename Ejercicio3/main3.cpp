#include "Number.hpp"
#include <iostream>

int main() {
    try {
        // Pruebas con class Integer
        Integer a(5);
        Integer b(3);

        Number* intSum = a.sum(b);
        Number* intSub = a.subtract(b);
        Number* intMult = a.multiply(b);
        Number* intDiv = a.divide(b);
        cout<<"Integer Sum: "<<intSum->toString()<<endl;
        cout<<"Integer Subtract: "<<intSub->toString()<<endl;
        cout<<"Integer Multiply: "<<intMult->toString()<<endl;
        cout<<"Integer Divide: "<<intDiv->toString()<<endl;

        // Pruebas con class Real
        Real r1(4.5);
        Real r2(2.0);

        Number* realSum = r1.sum(r2);
        Number* realSub = r1.subtract(r2);
        Number* realMult = r1.multiply(r2);
        Number* realDiv = r1.divide(r2);
        cout<<"Real Sum: "<<realSum->toString()<<endl;
        cout<<"Real Subtract: "<<realSub->toString()<<endl;
        cout<<"Real Multiply: "<<realMult->toString()<<endl;
        cout<<"Real Divide: "<<realDiv->toString()<<endl;

        // Pruebas con class Complex
        Complex c1(3.0, 2.0);
        Complex c2(1.0, 4.0);

        Number* compSum = c1.sum(c2);
        Number* compSub = c1.subtract(c2);
        Number* compMult = c1.multiply(c2);
        Number* compDiv = c1.divide(c2);
        cout<<"Complex Sum: "<<compSum->toString()<<endl;
        cout<<"Complex Subtract: "<<compSub->toString()<<endl;
        cout<<"Complex Multiply: "<<compMult->toString()<<endl;
        cout<<"Complex Divide: "<<compDiv->toString()<<endl;

        // Pruebas de operaciones entre Complex y Real
        Real r3(2.0);
        Number* compSumReal = c1.sum(r3);
        Number* compMultReal = c1.multiply(r3);
        Number* compDivReal = c1.divide(r3);
        cout<<"Complex + Real: "<<compSumReal->toString()<<endl;
        cout<<"Complex * Real: "<<compMultReal->toString()<<endl;
        cout<<"Complex / Real: "<<compDivReal->toString()<<endl;

        // Liberar memoria dinámica
        delete intSum;
        delete intSub;
        delete intMult;
        delete intDiv;
        delete realSum;
        delete realSub;
        delete realMult;
        delete realDiv;
        delete compSum;
        delete compSub;
        delete compMult;
        delete compDiv;
        delete compSumReal;
        delete compMultReal;
        delete compDivReal;
    }
    catch(const exception& ex) {
        cout<<"Error: "<<ex.what()<<endl;
    }
    return 0;
}