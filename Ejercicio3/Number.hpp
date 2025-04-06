#pragma once
#include <string>
#include <memory>
using namespace std;

// Ver si agregar getter para operar con reales y complejos

class Number{
public:
    virtual Number* sum(Number &other) = 0;
    virtual Number* subtract(Number &other) = 0;
    virtual Number* multiply(Number &other) = 0;
    virtual Number* divide(Number &other) = 0;
    virtual string toString() = 0;
    
    virtual ~Number() = default;
};

class Integer : public Number{
private:
    int value;
public:
    Integer(int val);
    ~Integer() = default; // Lo dejo o no?

    Number* sum(Number &other);
    Number* subtract(Number &other);
    Number* multiply(Number &other);
    Number* divide(Number &other);
    string toString();
};

class Real : public Number{
public:
    double value; // Public para poder operar con reales desde la clase Complex

    Real(double val);
    ~Real() = default;

    Number* sum(Number &other);
    Number* subtract(Number &other);
    Number* multiply(Number &other);
    Number* divide(Number &other);
    string toString();
    };

class Complex : public Number{
private:
    double Re;
    double Im;
public:
    Complex(double _Re, double _Im = 0);
    ~Complex() = default;

    Number* sum(Number &other);
    Number* subtract(Number &other);
    Number* multiply(Number &other);
    Number* divide(Number &other);
    string toString();
    };