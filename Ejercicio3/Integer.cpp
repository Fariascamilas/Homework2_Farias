#include "Number.hpp"
#include <iostream>

Integer::Integer(int val) : value(val) {};

Number* Integer::sum(Number &other){
    Integer* otherInt = dynamic_cast<Integer*>(&other);
    if (!otherInt){
        throw invalid_argument("Operación incompatible con tipo Integer");
    }
    int sum = otherInt->value + this->value;
    return new Integer(sum);
}
Number* Integer::subtract(Number &other){
    Integer* otherInt = dynamic_cast<Integer*>(&other);
    if (!otherInt){
        throw invalid_argument("Operación incompatible con tipo Integer");
    }
    int subtract = otherInt->value - this->value;
    return new Integer(subtract);
}
Number* Integer::multiply(Number &other){
    Integer* otherInt = dynamic_cast<Integer*>(&other);
    if (!otherInt){
        throw invalid_argument("Operación incompatible con tipo Integer");
    }
    int mult = otherInt->value * this->value;
    return new Integer(mult);
}
Number* Integer::divide(Number &other){
    Integer* otherInt = dynamic_cast<Integer*>(&other);
    if (!otherInt){
        throw invalid_argument("Operación incompatible con tipo Integer");
    }
    if (otherInt->value == 0){
        throw runtime_error("Intento de dividir por cero");
    }
    int div = otherInt->value / this->value;
    return new Integer(div);
}
string Integer::toString(){
    return to_string(this->value);
}