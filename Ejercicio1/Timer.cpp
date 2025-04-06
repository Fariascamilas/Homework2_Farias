#include "Timer.hpp"
#include <iomanip>

/**
 * @brief Verifica que la hora sea válida (1-12).
 * @param hours Hora a verificar
 * @return true si es válida, false en caso contrario
 */
bool checkHours(int hours){
    if(hours<1 || hours>12){
        return 0;
    }
    return 1;
}

/**
 * @brief Verifica que los minutos sean válidos (0-59).
 * @param minutes Minutos a verificar
 * @return true si son válidos, false en caso contrario
 */
bool checkMinutes(int minutes){
    if(minutes<0 || minutes>59){
        return 0;
    }
    return 1;
}

/**
 * @brief Verifica que los segundos sean válidos (0-59).
 * @param seconds Segundos a verificar
 * @return true si son válidos, false en caso contrario
 */
bool checkSeconds(int seconds){
    if(seconds<0 || seconds>59){
        return 0;
    }
    return 1;
}

Timer::Timer(): hours(0), minutes(0), seconds(0), isPm(false) {}

Timer::Timer(int _hours, int _minutes, int _seconds, bool _isPm): hours(_hours), minutes(_minutes), seconds(_seconds), isPm(_isPm){
    try{
        if(!checkHours(_hours)){
            throw invalid_argument("La hora ingresada es invalida");
        }
        if(!checkMinutes(_minutes)){
            throw invalid_argument("Los minutos ingresados son invalidos");
        }
        if(!checkSeconds(_seconds)){
            throw invalid_argument("Los segundos ingresados son invalidos");
        }
    } catch(const exception &e){
        cerr<<"Error al inicializar Timer: "<<e.what()<<endl;
        throw; 
    }
}

void Timer::getHours() const {
    cout<<setfill('0')<<setw(2)<<hours<<"h "<<endl;
}

void Timer::getMinutes() const {
    cout<<setfill('0')<<setw(2)<<minutes<<"m "<<endl;
}

void Timer::getSeconds() const {
    cout<<setfill('0')<<setw(2)<<seconds<<"s "<<endl;
}

void Timer::getMeridian() const {
    switch(isPm){
        case 0:
            cout<<"a.m."<<endl;
            break;
        default:
            cout<<"p.m."<<endl;
    }
}

void Timer::getTime() const {
    cout<<setfill('0')<<setw(2)<<hours<<"h "<<setfill('0')<<setw(2)<<minutes<<"m "<<setfill('0')<<setw(2)<<seconds<<"s ";
    this->getMeridian();
}

void Timer::getTime24H() const {
    switch(isPm){
        case 0:
            cout<<setfill('0')<<setw(2)<<hours<<"h "<<setfill('0')<<setw(2)<<minutes<<"m "<<setfill('0')<<setw(2)<<seconds<<"s"<<endl;
            break;
        default:
            cout<<setfill('0')<<setw(2)<<(12+hours)<<"h "<<setfill('0')<<setw(2)<<minutes<<"m "<<setfill('0')<<setw(2)<<seconds<<"s"<<endl;
    }
}

void Timer::setHours(int newhour){
    if(!checkHours(newhour)){
            throw invalid_argument("La hora ingresada es invalida");
    }
    this->hours = newhour;
}

void Timer::setMinutes(int newminutes){
    if(!checkMinutes(newminutes)){
        throw invalid_argument("Los minutos ingresados son invalidos");
    }
    this->minutes = newminutes;
}

void Timer::setSeconds(int newseconds){
    if(!checkMinutes(newseconds)){
        throw invalid_argument("Los segundos ingresados son invalidos");
    }
    this->seconds = newseconds;
}

void Timer::setMeridian(bool ispm){
    this->isPm = ispm; // No chequeo nunca si es valido ya que cualquier numero != 0 sera true; false caso contrario
}

void Timer::setTime(int newhours, int _minutes, int _seconds){
    setHours(newhours);
    setMinutes(_minutes);
    setSeconds(_seconds);
}