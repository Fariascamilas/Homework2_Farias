#include "Number.hpp"
#include <iostream>

int main() {
    // --- Entero ---
    Number* int1 = new Integer(3);
    Number* int2 = new Integer(5);
    Number* intSum = int1->sum(*int2);
    Number* intSub = int1->subtract(*int2);
    Number* intMult = int1->multiply(*int2);
    Number* intDiv = int1->divide(*int2);
    cout << int1->toString() << " + " << int2->toString() << " = " << intSum->toString() << endl;
    cout << int1->toString() << " - " << int2->toString() << " = " << intSub->toString() << endl;
    cout << int1->toString() << " * " << int2->toString() << " = " << intMult->toString() << endl;
    cout << int1->toString() << " / " << int2->toString() << " = " << intDiv->toString() << endl << endl;

    // --- Real ---
    Number* real1 = new Real(3.14);
    Number* real2 = new Real(2.5);
    Number* realSum = real1->sum(*real2);
    Number* realSub = real1->subtract(*real2);
    Number* realMult = real1->multiply(*real2);
    Number* realDiv = real1->divide(*real2);
    cout << real1->toString() << " + " << real2->toString() << " = " << realSum->toString() << endl;
    cout << real1->toString() << " - " << real2->toString() << " = " << realSub->toString() << endl;
    cout << real1->toString() << " * " << real2->toString() << " = " << realMult->toString() << endl;
    cout << real1->toString() << " / " << real2->toString() << " = " << realDiv->toString() << endl << endl;

    // --- Complejo ---
    Number* comp1 = new Complex(2, 3);
    Number* comp2 = new Complex(1, -1);
    Number* compSum = comp1->sum(*comp2);
    Number* compSub = comp1->subtract(*comp2);
    Number* compMult = comp1->multiply(*comp2);
    Number* compDiv = comp1->divide(*comp2);
    cout << "(" << comp1->toString() << ")" << " + " << "(" << comp2->toString() << ")" << " = " << "(" << compSum->toString() << ")" << endl;
    cout << "(" << comp1->toString() << ")" << " - " << "(" << comp2->toString() << ")" << " = " << "(" << compSub->toString() << ")" << endl;
    cout << "(" << comp1->toString() << ")" << " * " << "(" << comp2->toString() << ")" << " = " << "(" << compMult->toString() << ")" << endl;
    cout << "(" << comp1->toString() << ")" << " / " << "(" << comp2->toString() << ")" << " = " << "(" << compDiv->toString() << ")" << endl << endl;

    // --- Real + Entero ---
    Number* realIntSum = real1->sum(*int1);
    Number* realIntSub = real1->subtract(*int1);
    Number* realIntMult = real1->multiply(*int1);
    Number* realIntDiv = real1->divide(*int1);
    cout << real1->toString() << " + " << int1->toString() << " = " << realIntSum->toString() << endl;
    cout << real1->toString() << " - " << int1->toString() << " = " << realIntSub->toString() << endl;
    cout << real1->toString() << " * " << int1->toString() << " = " << realIntMult->toString() << endl;
    cout << real1->toString() << " / " << int1->toString() << " = " << realIntDiv->toString() << endl << endl;

    // --- Complejo + Entero ---
    Number* compIntSum = comp1->sum(*int1);
    Number* compIntSub = comp1->subtract(*int1);
    Number* compIntMult = comp1->multiply(*int1);
    Number* compIntDiv = comp1->divide(*int1);
    cout << "(" << comp1->toString() << ")" << " + " << int1->toString() << " = " << "(" << compIntSum->toString() << ")" << endl;
    cout << "(" << comp1->toString() << ")" << " - " << int1->toString() << " = " << "(" << compIntSub->toString() << ")" << endl;
    cout << "(" << comp1->toString() << ")" << " * " << int1->toString() << " = " << "(" << compIntMult->toString() << ")" << endl;
    cout << "(" << comp1->toString() << ")" << " / " << int1->toString() << " = " << "(" << compIntDiv->toString() << ")" << endl << endl;

    // --- Complejo + Real ---
    Number* compRealSum = comp1->sum(*real1);
    Number* compRealSub = comp1->subtract(*real1);
    Number* compRealMult = comp1->multiply(*real1);
    Number* compRealDiv = comp1->divide(*real1);
    cout << "(" << comp1->toString() << ")" << " + " << real1->toString() << " = " << "(" << compRealSum->toString() << ")" << endl;
    cout << "(" << comp1->toString() << ")" << " - " << real1->toString() << " = " << "(" << compRealSub->toString() << ")" << endl;
    cout << "(" << comp1->toString() << ")" << " * " << real1->toString() << " = " << "(" << compRealMult->toString() << ")" << endl;
    cout << "(" << comp1->toString() << ")" << " / " << real1->toString() << " = " << "(" << compRealDiv->toString() << ")" << endl << endl;

    // Liberar memoria
    delete int1; delete int2; delete intSum; delete intSub; delete intMult; delete intDiv;
    delete real1; delete real2; delete realSum; delete realSub; delete realMult; delete realDiv;
    delete comp1; delete comp2; delete compSum; delete compSub; delete compMult; delete compDiv;
    delete realIntSum; delete realIntSub; delete realIntMult; delete realIntDiv;
    delete compIntSum; delete compIntSub; delete compIntMult; delete compIntDiv;
    delete compRealSum; delete compRealSub; delete compRealMult; delete compRealDiv;

    return 0;
}