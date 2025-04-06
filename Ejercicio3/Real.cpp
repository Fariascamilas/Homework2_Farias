#include "Number.hpp"
#include <iostream>

/**
 * @brief Constructor que asigna valor real.
 * @param val Valor doble a almacenar.
 */
Real::Real(double val) : value(val){}

/**
 * @brief Suma el valor de este Real con otro Number (Real o Integer).
 * @param other Referencia a un Number.
 * @throws invalid_argument Si el tipo de Number no es compatible.
 * @return Puntero a un nuevo Real con la suma.
 */
Number* Real::sum(Number &other){
    Real* otherRe = dynamic_cast<Real*>(&other);
    if (!otherRe){
        Integer* otherInt = dynamic_cast<Integer*> (&other);
        if (!otherInt){
            throw invalid_argument("Operación incompatible con tipo Real");
        }
        double sum = this->value + otherInt->value;
        return new Real(sum);
    }
    double sum = this->value + otherRe->value;
    return new Real(sum);
}

/**
 * @brief Resta el valor de este Real con otro Number (Real o Integer).
 * @param other Referencia a un Number.
 * @throws invalid_argument Si el tipo de Number no es compatible.
 * @return Puntero a un nuevo Real con la resta.
 */
Number* Real::subtract(Number &other){
    Real* otherRe = dynamic_cast<Real*>(&other);
    if (!otherRe){
        Integer* otherInt = dynamic_cast<Integer*> (&other);
        if (!otherInt){
            throw invalid_argument("Operación incompatible con tipo Real");
        }
        double subtract = this->value - otherInt->value;
        return new Real(subtract);
    }
    double subtract = this->value - otherRe->value;
    return new Real(subtract);
}

/**
 * @brief Multiplica el valor de este Real con otro Number (Real o Integer).
 * @param other Referencia a un Number.
 * @throws invalid_argument Si el tipo de Number no es compatible.
 * @return Puntero a un nuevo Real con el producto.
 */
Number* Real::multiply(Number &other){
    Real* otherRe = dynamic_cast<Real*>(&other);
    if (!otherRe){
        Integer* otherInt = dynamic_cast<Integer*> (&other);
        if (!otherInt){
            throw invalid_argument("Operación incompatible con tipo Real");
        }
        double mult = otherInt->value * this->value;
        return new Real(mult);
    }
    double mult = otherRe->value * this->value;
    return new Real(mult);
}


/**
 * @brief Divide el valor de este Real entre otro Number (Real o Integer).
 * @param other Referencia a un Number.
 * @throws invalid_argument Si el tipo de Number no es compatible.
 * @throws runtime_error Si se intenta dividir por cero.
 * @return Puntero a un nuevo Real con el cociente.
 */
Number* Real::divide(Number &other){
    Real* otherRe = dynamic_cast<Real*>(&other);
    if (!otherRe){
        Integer* otherInt = dynamic_cast<Integer*> (&other);
        if (!otherInt){
            throw invalid_argument("Operación incompatible con tipo Real");
        }
        if (otherInt->value == 0){
            throw runtime_error("Intento de dividir por cero");
        }
        double div = this->value / otherInt->value;
        return new Real(div);
    }
    if (otherRe->value == 0){
        throw runtime_error("Intento de dividir por cero");
    }
    double div = this->value / otherRe->value;
    return new Real(div);
}

/**
 * @brief Convierte el valor real a una cadena.
 * @return Cadena con el valor de este Real.
 */
string Real::toString(){
    return to_string(this->value);
}