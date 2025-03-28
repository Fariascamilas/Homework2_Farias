#include <iostream>
#include <string>
using namespace std;

class Timer{
private:
    int hours;
    int minutes;
    int seconds;
    char lapse; // puede ser 'a' o 'p' (por a.m. y p.m.)
public:
    Timer(int _hours = 0, int _minutes = 0, int _seconds = 0, char _lapse = 'a');

    void getHours() const; // Getters

    void getMinutes() const;
    
    void getSeconds() const;

    void getTime12() const; // Con am y pm

    void getTime24() const; // Sin am y pm

    void setHours(int _hours); // Setters

    void setMinutes(int _minutes);

    void setSeconds(int _seconds);

    void setTime(int _hours, int _minutes, int _seconds);
};

// Notas
/*El uso de const al final de un método miembro indica que la función no modificará la instancia del objeto (no cambiará sus atributos). Esto es útil para garantizar que los métodos de acceso (getters) o cualquier función que solo consulte el estado del objeto no alteren sus datos. Además, permite que estos métodos sean llamados sobre objetos constantes.*/