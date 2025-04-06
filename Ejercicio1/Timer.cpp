#include "Timer.hpp"
#include <iomanip>

bool checkHours(int hours){
    if(hours<1 || hours>12){
        return 0;
    }
    return 1;
}

bool checkMinutes(int minutes){
    if(minutes<0 || minutes>59){
        return 0;
    }
    return 1;
}

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

void Timer::getTime24H() const { // ERROR! ERA SOLO LA HORA
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

/*int main(){

    // Pruebas: inicializaciones variadas
    Timer prueba1(1);
    prueba1.getTime();
    Timer prueba2(1,2);
    prueba2.getTime();
    Timer prueba3(1,2,3);
    prueba3.getTime();
    Timer prueba4(8,2,3,true);
    prueba4.getTime();
    prueba4.getTime24H();

    // Modificaciones por casos
    Timer myTimer;

    myTimer.getHours();
    myTimer.getMinutes();
    myTimer.getSeconds();
    myTimer.getMeridian();
    myTimer.getTime();
    myTimer.getTime24H();

    // Caso 1: parametros válidos (02h 22m 22s p.m.)
    myTimer.setHours(2);
    myTimer.setMinutes(22);
    myTimer.setSeconds(22);
    myTimer.setMeridian(1);

    // Caso 2: hora inválida (22h 22m 22s p.m.)
    myTimer.setHours(22);
    myTimer.setMinutes(22);
    myTimer.setSeconds(22);
    myTimer.setMeridian(1);
    
    // Caso 3: segundos inválidos (22h 22m 88s p.m.)
    myTimer.setHours(2);
    myTimer.setMinutes(22);
    myTimer.setSeconds(88);
    myTimer.setMeridian(1);

    // Caso 3: segundos inválidos (22h 22m 88s p.m.)
    myTimer.setHours(2);
    myTimer.setMinutes(22);
    myTimer.setSeconds(88);
    myTimer.setMeridian(1);

    return 0;
}*/