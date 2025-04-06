#pragma once
#include <string>
#include <memory>
using namespace std;

/**
 * @brief Interfaz para un número.
 */
class Number{
public:
    /**
     * @brief Suma el número actual con otro Number.
     * @param other Referencia a otro Number.
     * @return Puntero a un objeto Number con el resultado.
     */
    virtual Number* sum(Number &other) = 0;

    /**
     * @brief Resta el número actual con otro Number.
     * @param other Referencia a otro Number.
     * @return Puntero a un objeto Number con el resultado.
     */
    virtual Number* subtract(Number &other) = 0;

    /**
     * @brief Multiplica el número actual con otro Number.
     * @param other Referencia a otro Number.
     * @return Puntero a un objeto Number con el resultado.
     */
    virtual Number* multiply(Number &other) = 0;

    /**
     * @brief Divide el número actual entre otro Number.
     * @param other Referencia a otro Number.
     * @return Puntero a un objeto Number con el resultado.
     */
    virtual Number* divide(Number &other) = 0;

    /**
     * @brief Devuelve una representación en cadena del número.
     * @return String con el valor del número.
     */
    virtual string toString() = 0;
    
    virtual ~Number() = default;
};

/**
 * @brief Representa un número entero.
 */
class Integer : public Number{
    friend class Real;
    friend class Complex;
private:
    int value;
public:
    /**
     * @brief Constructor que inicializa el valor interno.
     * @param val Valor entero.
     */
    Integer(int val);
    ~Integer() = default;

    Number* sum(Number &other);
    Number* subtract(Number &other);
    Number* multiply(Number &other);
    Number* divide(Number &other);
    string toString();
};

/**
 * @brief Representa un número real (con punto flotante).
 */
class Real : public Number{
    friend class Complex;
private:
    double value;
public:
    /**
     * @brief Constructor que inicializa el valor interno.
     * @param val Valor real.
     */
    Real(double val);
    ~Real() = default;

    Number* sum(Number &other);
    Number* subtract(Number &other);
    Number* multiply(Number &other);
    Number* divide(Number &other);
    string toString();
};

/**
 * @brief Representa un número complejo con parte real e imaginaria.
 */
class Complex : public Number{
private:
    double Re;
    double Im;
public:
    /**
     * @brief Constructor que inicializa la parte real e imaginaria.
     * @param _Re Parte real.
     * @param _Im Parte imaginaria (0 por defecto).
     */
    Complex(double _Re, double _Im = 0);
    ~Complex() = default;

    Number* sum(Number &other);
    Number* subtract(Number &other);
    Number* multiply(Number &other);
    Number* divide(Number &other);
    string toString();
};