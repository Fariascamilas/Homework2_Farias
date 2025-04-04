#pragma once
#include <iostream>
#include <string>
using namespace std;

class Timer{
private:
    int hours;
    int minutes;
    int seconds;
    bool isPm; // Usar bool ocupa solo 1 byte
public:
    Timer();
    Timer(int _hours, int _minutes = 0, int _seconds = 0, bool _isPm = false);

    void getHours() const; // Getters

    void getMinutes() const;
    
    void getSeconds() const;
    
    void getMeridian() const;

    void getTime() const; // Con am y pm

    void getTime24H() const; // Sin am y pm

    void setHours(int newhours); // Setters

    void setMinutes(int newminutes);

    void setSeconds(int newseconds);

    void setMeridian(bool ispm);

    void setTime(int newhours, int _minutes, int _seconds);
};

// Notas
/*El uso de const al final de un método miembro indica que la función no modificará la instancia del objeto (no cambiará sus atributos). Esto es útil para garantizar que los métodos de acceso (getters) o cualquier función que solo consulte el estado del objeto no alteren sus datos. Además, permite que estos métodos sean llamados sobre objetos constantes.*/