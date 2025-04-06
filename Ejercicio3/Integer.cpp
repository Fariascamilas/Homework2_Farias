#include "Number.hpp"
#include <iostream>
/**
 * @brief Constructor que asigna valor entero.
 * @param val Valor entero a almacenar.
 */
Integer::Integer(int val) : value(val) {};

/**
 * @brief Suma el valor de este Integer con otro Number convertido a Integer.
 * @param other Referencia a un Number que se espera sea Integer.
 * @throws invalid_argument Si el tipo de Number no es Integer.
 * @return Puntero a un nuevo Integer con la suma.
 */
Number* Integer::sum(Number &other){
    Integer* otherInt = dynamic_cast<Integer*>(&other);
    if (!otherInt){
        throw invalid_argument("Operación incompatible con tipo Integer");
    }
    int sum = this->value + otherInt->value;
    return new Integer(sum);
}

/**
 * @brief Resta el valor de este Integer con otro Number convertido a Integer.
 * @param other Referencia a un Number que se espera sea Integer.
 * @throws invalid_argument Si el tipo de Number no es Integer.
 * @return Puntero a un nuevo Integer con la resta.
 */
Number* Integer::subtract(Number &other){
    Integer* otherInt = dynamic_cast<Integer*>(&other);
    if (!otherInt){
        throw invalid_argument("Operación incompatible con tipo Integer");
    }
    int subtract = this->value - otherInt->value;
    return new Integer(subtract);
}

/**
 * @brief Multiplica el valor de este Integer con otro Number convertido a Integer.
 * @param other Referencia a un Number que se espera sea Integer.
 * @throws invalid_argument Si el tipo de Number no es Integer.
 * @return Puntero a un nuevo Integer con el producto.
 */
Number* Integer::multiply(Number &other){
    Integer* otherInt = dynamic_cast<Integer*>(&other);
    if (!otherInt){
        throw invalid_argument("Operación incompatible con tipo Integer");
    }
    int mult = otherInt->value * this->value;
    return new Integer(mult);
}
/**
 * @brief Divide el valor de este Integer entre otro Number convertido a Integer.
 * @param other Referencia a un Number que se espera sea Integer.
 * @throws invalid_argument Si el tipo de Number no es Integer.
 * @throws runtime_error Si se intenta dividir por cero.
 * @return Puntero a un nuevo Integer con el cociente.
 */
Number* Integer::divide(Number &other){
    Integer* otherInt = dynamic_cast<Integer*>(&other);
    if (!otherInt){
        throw invalid_argument("Operación incompatible con tipo Integer");
    }
    if (otherInt->value == 0){
        throw runtime_error("Intento de dividir por cero");
    }
    int div = this->value / otherInt->value;
    return new Integer(div);
}

/**
 * @brief Convierte el valor entero a cadena.
 * @return Cadena con el valor de este Integer.
 */
string Integer::toString(){
    return to_string(this->value);
}