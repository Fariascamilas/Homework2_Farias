# include "Timer.h"

Timer::Timer(int _hours, int _minutes, int _seconds, char _lapse) : hours(_hours), minutes(_minutes), seconds(_seconds), lapse(_lapse) {
    try{
        if (_hours<0){
            throw invalid_argument("La hora no puede ser negativa");
        }
        if (_minutes<0){
            throw invalid_argument("Los minutos no pueden ser negativos");
        }
        if (_seconds<0){
            throw invalid_argument("Los segundos no pueden ser negativos");
        }

        if (_hours>11 && _lapse == 'p'){
            throw invalid_argument("La hora no puede ser mayor a 11 cuando el período es p.m.");
        }
        if (_hours>12 && _lapse == 'a'){
            throw invalid_argument("La hora no puede ser mayor a 12 cuando el período es a.m.");
        }

        if (_minutes>59){
            throw invalid_argument("Los minutos no pueden ser mas de 59");
        }
        if (_seconds>59){
            throw invalid_argument("Los segundos no pueden ser de 59");
        }
    } catch(const exception &e){
        cerr<<"Error al construir Timer: "<<e.what()<<endl;
        throw; // Porque la construccion falló
    }
}