#include "Number.hpp"
#include <iostream>

Real::Real(double val) : value(val){}

Number* Real::sum(Number &other){
    Real* otherRe = dynamic_cast<Real*>(&other);
    if (!otherRe){
        throw invalid_argument("Operación incompatible con tipo Real");
    }
    double sum = otherRe->value + this->value;
    return new Real(sum);
}
Number* Real::subtract(Number &other){
    Real* otherRe = dynamic_cast<Real*>(&other);
    if (!otherRe){
        throw invalid_argument("Operación incompatible con tipo Real");
    }
    double subtract = otherRe->value - this->value;
    return new Real(subtract);
}
Number* Real::multiply(Number &other){
    Real* otherRe = dynamic_cast<Real*>(&other);
    if (!otherRe){
        throw invalid_argument("Operación incompatible con tipo Real");
    }
    double mult = otherRe->value * this->value;
    return new Real(mult);
}
Number* Real::divide(Number &other){
    Real* otherRe = dynamic_cast<Real*>(&other);
    if (!otherRe){
        throw invalid_argument("Operación incompatible con tipo Real");
    }
    if (otherRe->value == 0){
        throw runtime_error("Intento de dividir por cero");
    }
    double div = otherRe->value / this->value;
    return new Real(div);
}
string Real::toString(){
    return to_string(this->value);
}