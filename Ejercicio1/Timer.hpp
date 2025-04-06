#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
 * @class Timer
 * @brief Representa un reloj de 12 horas con indicador AM/PM.
 */
class Timer{
private:
    int hours;   ///< Horas (1-12)
    int minutes; ///< Minutos (0-59)
    int seconds; ///< Segundos (0-59)
    bool isPm;   ///< true si es PM, false si es AM
public:
    /**
     * @brief Constructor por defecto. Inicializa el tiempo en 00:00:00 AM.
     */
    Timer();

    /**
     * @brief Constructor que inicializa el Timer con valores específicos.
     * @param _hours Valor de hora (1-12)
     * @param _minutes Valor de minutos (0-59)
     * @param _seconds Valor de segundos (0-59)
     * @param _isPm true para PM, false para AM
     */
    Timer(int _hours, int _minutes = 0, int _seconds = 0, bool _isPm = false);

    /**
     * @brief Imprime la hora (HH).
     */
    void getHours() const; // Getters
    
    /**
     * @brief Imprime los minutos (MM).
     */
    void getMinutes() const;
    
    /**
     * @brief Imprime los segundos (SS).
     */
    void getSeconds() const;
    
    /**
     * @brief Imprime “a.m.” o “p.m.” según el valor de isPm.
     */
    void getMeridian() const;
    
    /**
     * @brief Imprime la hora en formato de 12h (HH MM SS am/pm).
     */
    void getTime() const; // Con am y pm
    
    /**
     * @brief Imprime la hora en formato de 24h (00-23 HH MM SS).
     */
    void getTime24H() const; // Sin am y pm
    
    /**
     * @brief Asigna la hora, validando el rango (1-12).
     * @param newhours Nueva hora a asignar
     */
    void setHours(int newhours); // Setters

    /**
     * @brief Asigna los minutos, validando el rango (0-59).
     * @param newminutes Nuevos minutos a asignar
     */
    void setMinutes(int newminutes);
    
    /**
     * @brief Asigna los segundos, validando el rango (0-59).
     * @param newseconds Nuevos segundos a asignar
     */
    void setSeconds(int newseconds);
    
    /**
     * @brief Asigna AM o PM.
     * @param ispm true para PM, false para AM
     */
    void setMeridian(bool ispm);
    
    /**
     * @brief Asigna un nuevo tiempo (HH, MM, SS) sin indicar AM o PM.
     * @param newhours Hora (1-12)
     * @param _minutes Minutos (0-59)
     * @param _seconds Segundos (0-59)
     */
    void setTime(int newhours, int _minutes, int _seconds);
};

// Notas
/*El uso de const al final de un método miembro indica que la función no modificará la instancia del objeto (no cambiará sus atributos). Esto es útil para garantizar que los métodos de acceso (getters) o cualquier función que solo consulte el estado del objeto no alteren sus datos. Además, permite que estos métodos sean llamados sobre objetos constantes.*/