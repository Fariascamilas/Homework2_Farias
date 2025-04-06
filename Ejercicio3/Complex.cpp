#include "Number.hpp"
#include <iostream>

Complex::Complex(double _Re, double _Im) : Re(_Re),Im(_Im){}

Number* Complex::sum(Number &other){
    Complex* otherCo = dynamic_cast<Complex*>(&other);
    if (!otherCo){
        Real* otherNum = dynamic_cast<Real*>(&other);
        if(!otherNum){
            throw invalid_argument("Operación incompatible con tipo Complex");
        }
        double sum = otherNum->value + this->Re;
        return new Complex(sum,this->Im);
    }
    double sumRe = this->Re + otherCo->Re;
    double sumIm = this->Im + otherCo->Im;
    return new Complex(sumRe,sumIm);
}

Number* Complex::subtract(Number &other){
    Complex* otherCo = dynamic_cast<Complex*>(&other);
    if (!otherCo){
        Real* otherNum = dynamic_cast<Real*>(&other);
        if(!otherNum){
            throw invalid_argument("Operación incompatible con tipo Complex");
        }
        double subtract = otherNum->value - this->Re;
        return new Complex(subtract,this->Im);
    }
    double subtractRe = this->Re - otherCo->Re;
    double subtractIm = this->Im - otherCo->Im;
    return new Complex(subtractRe,subtractIm);
}

Number* Complex::multiply(Number &other){
    Complex* otherCo = dynamic_cast<Complex*>(&other);
    if (!otherCo){
        Real* otherNum = dynamic_cast<Real*>(&other);
        if(!otherNum){
            throw invalid_argument("Operación incompatible con tipo Complex");
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

Number* Complex::divide(Number &other){
    Complex* otherCo = dynamic_cast<Complex*>(&other);
    if (!otherCo){
        Real* otherNum = dynamic_cast<Real*>(&other);
        if(!otherNum){
            throw invalid_argument("Operación incompatible con tipo Complex");
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
string Complex::toString(){
    return (to_string(this->Re) + " + " + to_string(this->Im) + "i");
}