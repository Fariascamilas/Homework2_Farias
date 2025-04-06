#pragma once
#include "Student.hpp"
#include <array>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class Course{
private:
    string name;
    array<shared_ptr<Student>,20> students;
public: // Ver si va protected
    Course(string _name, array<shared_ptr<Student>,20> _students = {});
    
    Course(const Course& original, const string& newName) : name(newName), students(original.students) {};
    /*
    Copy Constructor:
        Se trata, en este caso, de shallow copy (para el array). Un constructor de copia puramente superficial deberia copiar exactamente los atributos del objeto original, pero nos interesa que los cursos tengan nombres distintos al copiarlos, entonces el nombre se "copia" de forma profunda (deep) porque no es una referencia al dato original. Aún así hago shallow de el array para no tener que duplicar todos los valores ocupando mas memoria. Se puede hacer shallow ya que el array no es dinámico. No tendré problemas con el borrado de un Curso ya que cuando duplique mi array los shared_ptr incrementan el contador, entonces no se modifican las direcciones en memoria que apuntan a los estudiantes al borrar solo uno de los cursos porque el contador no es cero.
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
    
    string getName() const;
    void printCourse() const;
    bool isEnrolled(int record);
    bool enrollStudent(shared_ptr<Student> s); // Devuelve false si el curso esta lleno
    bool unenrollStudent(int record); // Devuelve false si el estudiante no estaba inscripto
    bool isFull();
};