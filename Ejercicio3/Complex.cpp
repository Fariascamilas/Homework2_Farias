#include "Number.hpp"
#include <iostream>

/**
 * @brief Constructor que asigna valor a la parte real e imaginaria.
 * @param _Re Parte real.
 * @param _Im Parte imaginaria (por defecto 0).
 */
Complex::Complex(double _Re, double _Im) : Re(_Re),Im(_Im){}

/**
 * @brief Constructor que asigna valor a la parte real e imaginaria.
 * @param _Re Parte real.
 * @param _Im Parte imaginaria (por defecto 0).
 */
Number* Complex::sum(Number &other){
    Complex* otherCo = dynamic_cast<Complex*>(&other);
    if (!otherCo){
        Real* otherNum = dynamic_cast<Real*>(&other);
        if(!otherNum){
            Integer* otherInt = dynamic_cast<Integer*>(&other);
            if (!otherInt){
                throw invalid_argument("Operación incompatible con tipo Complex");
            }
            double sum = this->Re + otherInt->value;
            return new Complex(sum,this->Im);
        }
        double sum = this->Re + otherNum->value;
        return new Complex(sum,this->Im);
    }
    double sumRe = this->Re + otherCo->Re;
    double sumIm = this->Im + otherCo->Im;
    return new Complex(sumRe,sumIm);
}

/**
 * @brief Resta este Complex con otro Number (Complex, Real o Integer).
 * @param other Referencia a un Number.
 * @throws invalid_argument Si el Number no es compatible.
 * @return Puntero a un nuevo Complex con la resta.
 */
Number* Complex::subtract(Number &other){
    Complex* otherCo = dynamic_cast<Complex*>(&other);
    if (!otherCo){
        Real* otherNum = dynamic_cast<Real*>(&other);
        if(!otherNum){
            Integer* otherInt = dynamic_cast<Integer*>(&other);
            if (!otherInt){
                throw invalid_argument("Operación incompatible con tipo Complex");
            }     
            double subtract = this->Re - otherInt->value;
            return new Complex(subtract,this->Im);
        }
        double subtract = this->Re - otherNum->value;
        return new Complex(subtract,this->Im);
    }
    double subtractRe = this->Re - otherCo->Re;
    double subtractIm = this->Im - otherCo->Im;
    return new Complex(subtractRe,subtractIm);
}

/**
 * @brief Multiplica este Complex con otro Number (Complex, Real o Integer).
 * @param other Referencia a un Number.
 * @throws invalid_argument Si el Number no es compatible.
 * @return Puntero a un nuevo Complex con el producto.
 */
Number* Complex::multiply(Number &other){
    Complex* otherCo = dynamic_cast<Complex*>(&other);
    if (!otherCo){
        Real* otherNum = dynamic_cast<Real*>(&other);
        if(!otherNum){
            Integer* otherInt = dynamic_cast<Integer*>(&other);
            if (!otherInt){
                throw invalid_argument("Operación incompatible con tipo Complex");
            }
            return new Complex(this->Re * otherInt->value,this->Im * otherInt->value);
        }
        return new Complex(this->Re * otherNum->value,this->Im * otherNum->value);
    }
    double a = this->Re; 
    double b = this->Im; 

    double c = otherCo->Re; 
    double d = otherCo->Im;
    
    double multRe = (a*c - b*d);
    double multIm = (a*d + b*c);
    return new Complex(multRe,multIm);
}

/**
 * @brief Divide este Complex entre otro Number (Complex, Real o Integer).
 * @param other Referencia a un Number.
 * @throws invalid_argument Si el Number no es compatible.
 * @throws runtime_error Si se intenta dividir por cero.
 * @return Puntero a un nuevo Complex con el cociente.
 */
Number* Complex::divide(Number &other){
    Complex* otherCo = dynamic_cast<Complex*>(&other);
    if (!otherCo){
        Real* otherNum = dynamic_cast<Real*>(&other);
        if(!otherNum){
            Integer* otherInt = dynamic_cast<Integer*>(&other);
            if (!otherInt){
                throw invalid_argument("Operación incompatible con tipo Complex");
            }
            if(otherInt->value == 0){
                throw runtime_error("Intento de dividir por cero");
            }
            return new Complex(this->Re / otherInt->value, this->Im / otherInt->value);
        }
        if(otherNum->value == 0){
            throw runtime_error("Intento de dividir por cero");
        }
        return new Complex(this->Re / otherNum->value,this->Im / otherNum->value);
    }
    double a = this->Re; 
    double b = this->Im; 

    double c = otherCo->Re; 
    double d = otherCo->Im;
    if ((c*c + d*d) == 0){
        throw runtime_error("Intento de dividir por cero");
    }
    double divRe = (a*c + b*d)/(c*c + d*d);
    double divIm = (b*c - a*d)/(c*c + d*d);
    return new Complex(divRe,divIm);
}

/**
 * @brief Convierte este número complejo a una cadena "Re + Im i".
 * @return Cadena con la representación del número complejo.
 */
string Complex::toString(){
    return (to_string(this->Re) + " + " + to_string(this->Im) + "i");
}