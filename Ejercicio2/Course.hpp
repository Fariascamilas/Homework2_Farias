#pragma once
#include "Student.hpp"
#include <array>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

/**
 * @brief Representa un curso con un nombre y un arreglo de estudiantes.
 */
class Course{
private:
    string name;
    array<shared_ptr<Student>,20> students;
public:
    /**
     * @brief Constructor de la clase Course.
     * @param _name Nombre del curso.
     * @param _students Arreglo de punteros compartidos a Student (hasta 20).
     */
    Course(string _name, array<shared_ptr<Student>,20> _students = {});
    
    /**
     * @brief Constructor de copia que cambia el nombre del curso.
     * @param original Curso original.
     * @param newName Nuevo nombre para el curso.
     */
    Course(const Course& original, const string& newName) : name(newName), students(original.students) {};
    /*
    Copy Constructor:
        Se trata, en este caso, de shallow copy (para el array). Un constructor de copia puramente superficial deberia copiar exactamente los atributos del objeto original, pero nos interesa que los cursos tengan nombres distintos al copiarlos, entonces el nombre se "copia" de forma profunda (deep) porque no es una referencia al dato original. Aún así hago shallow de el array para no tener que duplicar todos los valores ocupando mas memoria. Se puede hacer shallow ya que el array no es dinámico. No tendré problemas con el borrado de un Curso ya que cuando duplique mi array los shared_ptr incrementan el contador, entonces no se modifican las direcciones en memoria que apuntan a los estudiantes al borrar solo uno de los cursos porque el contador no es cero.
    */
    
    /**
     * @brief Operador de salida para imprimir la información del curso.
     * @param output Flujo de salida.
     * @param c Objeto Course a imprimir.
     * @return Referencia al flujo de salida.
     */
    friend ostream& operator <<(ostream &output,const Course &c){
        output<<"CURSO: "<<c.name<<"\n\nESTUDIANTES:";
        for(shared_ptr<Student> student : c.students){
            if(student){
                output<<"\n► Nombre:"<<student->getFullName()<<" | "
                <<"Legajo:"<<student->getRecordNumber()<<" | "
                <<"Promedio General:"<<student->getGPA()<<endl;
            }
        }
        return output;
    }
    
    /**
     * @brief Devuelve el nombre del curso.
     * @return Nombre del curso (string).
     */
    string getName() const;
    
    /**
     * @brief Imprime la información del curso y los estudiantes ordenados.
     */
    void printCourse() const;
    
    /**
     * @brief Verifica si un estudiante con cierto legajo está inscrito.
     * @param record Número de legajo a buscar.
     * @return true si está inscrito, false en caso contrario.
     */
    bool isEnrolled(int record);
    
    /**
     * @brief Inscribe un nuevo estudiante si hay espacio disponible.
     * @param s Puntero compartido al Student que se desea inscribir.
     * @return true si la operación fue exitosa, false si el curso está lleno.
     */
    bool enrollStudent(shared_ptr<Student> s);
    
    /**
     * @brief Da de baja a un estudiante por número de legajo.
     * @param record Número de legajo del estudiante a dar de baja.
     * @return true si se dio de baja exitosamente, false si no estaba inscrito.
     */
    bool unenrollStudent(int record); 
    
    /**
     * @brief Revisa si el curso está completo (sin espacios).
     * @return true si todos los lugares están ocupados, false en caso contrario.
     */
    bool isFull();
};