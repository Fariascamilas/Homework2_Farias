#pragma once
#include <string>
using namespace std;

/**
 * @brief Clase base que representa una cuenta bancaria.
 */
class Account{
protected: // Para poder acceder a los atributos desde las clases derivadas
    double balance;
    string accountOwner;
    int shows;
public:
    /**
     * @brief Deposita un monto en la cuenta.
     * @param amount Monto a depositar.
     * @throw invalid_argument Si el monto a depositar es menor o igual a cero.
     */
    virtual void deposit(double amount);
    
    /**
     * @brief Retira un monto de la cuenta.
     * @param amount Monto a retirar.
     * @param savings Referencia a otra cuenta (usada para sobregiro en cuentas derivadas).
     * @note Es un método virtual puro, cada clase derivada lo implementa según corresponda.
     */
    virtual void draw(double amount, Account &savings) = 0;
    
    /**
     * @brief Muestra la información de la cuenta.
     * @note Es un método virtual puro, cada clase derivada lo implementa según corresponda.
     */
    virtual void showInfo() = 0; /* Si no fuera public no podria usarlo en el main. Alternativa para que sea mas seguro: crear otro getter que sea public que solo devuelva el balance, no los datos del propietario. De esta forma podria tener el getter en public y showInfo() en protected, o incluso en private dentro de las clases derivadas*/
    
    /**
     * @brief Destructor virtual.
     */
    virtual ~Account() = default;
};

/**
 * @brief Representa una cuenta de tipo caja de ahorro.
 * @details Hereda de Account y permite retiros y una penalización al mostrar info si se excede cierto número de consultas.
 */
class savingsAccount : public Account{
    friend class currentAccount; /* Para poder acceder a los atributos de la caja de ahorro desde la cuenta corriente*/
public:
    /**
     * @brief Constructor de la caja de ahorro.
     * @param _accountOwner Nombre del titular.
     * @param _balance Balance inicial (opcional).
     * @throw invalid_argument Si el balance inicial es negativo.
     */
    savingsAccount(string _accountOwner, double _balance = 0);
    
    /**
     * @brief Retira un monto de la caja de ahorro.
     * @param amount Monto a retirar.
     * @param savings Referencia a la misma cuenta u otra (usado en herencias).
     * @throw invalid_argument Si se intenta retirar más de lo disponible.
     */
    void draw(double amount, Account &savings) override;
    
    /**
     * @brief Muestra la información de la cuenta.
     * @details Reduce el balance si se llama más de dos veces.
     */
    void showInfo() override;
};

/**
 * @brief Representa una cuenta de tipo cuenta corriente.
 * @details Hereda de Account y permite retiros que pueden hacer uso de una caja de ahorro asociada.
 */
class currentAccount : public Account{
public:
    /**
     * @brief Constructor de la cuenta corriente.
     * @param _accountOwner Nombre del titular.
     * @param _balance Balance inicial (opcional).
     * @throw invalid_argument Si el balance inicial es negativo.
     */
    currentAccount(string _accountOwner, double _balance = 0);
    
    /**
     * @brief Retira un monto de la cuenta corriente, usando la caja de ahorro si no hay suficiente saldo.
     * @param amount Monto a retirar.
     * @param savings Referencia a la caja de ahorro asociada para sobregiros.
     * @throw invalid_argument Si no hay fondos suficientes o si la caja de ahorro no coincide con el titular.
     */
    void draw(double amount, Account &savings) override;
    
    /**
     * @brief Muestra la información de la cuenta corriente.
     */
    void showInfo() override;
};