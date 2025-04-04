#include "Student.h"
#include <iostream>

Student::Student(const char* _fullName, int _recordNumber, vector<int> _grades) : fullName(_fullName), recordNumber(_recordNumber), grades(_grades){
    try{
        if (to_string(_recordNumber).length() != 5){
        throw invalid_argument("El número de legajo debe tenr 5 dígitos");
        }
    } catch(const exception &e){
        cerr<<"Error al inicializar el objeto Student: "<<e.what()<<endl;
        throw;
    }
}

bool Student::operator<(const Student& other) const {
    return this->fullName<other.fullName;
}

const char* Student::getFullName() const {
    return fullName;
}

int Student::getRecordNumber() const {
    return recordNumber;
}

float Student::getGPA() const{
    int sum = 0;
    for(int grade : grades){
        sum += grade;
    }
    return float(sum)/grades.size();
}

int main(){
    char name[] = "Camila Farías";
    vector<int> grades = {10,9,9,9};
    Student myStudent(name,36612,grades);

    cout<<myStudent.getFullName()<<endl;
    cout<<myStudent.getGPA()<<endl;
    cout<<myStudent.getRecordNumber()<<endl;

    return 0;
}