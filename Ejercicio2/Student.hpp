#pragma once
#include <string>
#include <vector>
using namespace std;

/**
 * @brief Representa a un estudiante con nombre, legajo y notas.
 */
class Student{
    private:
        const char* fullName;
        int recordNumber;
        vector<int> grades;
    
    public:
        /**
         * @brief Constructor de la clase Student.
         * @param _fullName Nombre completo del estudiante.
         * @param _recordNumber Número de legajo (con 5 dígitos).
         * @param _grades Vector de calificaciones del estudiante.
         */
        Student(const char* _fullName, int _recordNumber, vector<int> _grades);

        /**
         * @brief Sobrecarga del operador < para ordenar por nombre.
         * @param other Otro objeto Student para comparar.
         * @return true si this->fullName es lexicográficamente menor.
         */
        bool operator<(const Student& other) const;
        
        /**
         * @brief Obtiene el nombre completo del estudiante.
         * @return Cadena de caracteres con el nombre completo.
         */
        const char* getFullName() const;
        
        /**
         * @brief Obtiene el número de legajo del estudiante.
         * @return Número de legajo (5 dígitos).
         */
        int getRecordNumber() const;
        
        /**
         * @brief Calcula el promedio (GPA) de las notas del estudiante.
         * @return Valor del promedio como flotante.
         */
        float getGPA() const; // Grade Point Average (GPA)
    };