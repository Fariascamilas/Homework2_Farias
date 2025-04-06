#include "Course.hpp"
#include <algorithm>
#include <iostream>

Course::Course(string _name, array<shared_ptr<Student>,20> _students) : name(_name), students(_students){}

string Course::getName() const{
    return this->name;
}

void Course::printCourse() const {
    auto sortedStudents = students;
    sort(sortedStudents.begin(), sortedStudents.end(),
         [](const shared_ptr<Student>& a, const shared_ptr<Student>& b) {
             if(!a) return false;
             if(!b) return true;
             return *a < *b;
         });
    cout<<*this<<endl;
    /*for(const auto& s : sortedStudents) {
        if(s) {
            cout << "Nombre: " << s->getFullName() 
                 << " | Legajo: " << s->getRecordNumber() 
                 << " | Promedio: " << s->getGPA() << endl;
        }
    }*/
}

bool Course::isEnrolled(int record){
    for(shared_ptr<Student> student : students){
        if (student && student->getRecordNumber() == record){
            return true;
        }
    }
    return false;
}

bool Course::enrollStudent(shared_ptr<Student> s){
    if(!this->isFull()){
        for(shared_ptr<Student> &student : students){
            if(!student){
                student = s;
                return true;
            }
        }
    }
    return false;
}

bool Course::unenrollStudent(int record){
    for(shared_ptr<Student> &student : students){
        if(student && student->getRecordNumber() == record){
            student = nullptr;
            return true;
        }
    }
    return false;
}


bool Course::isFull(){
    for (shared_ptr<Student> student : students){
        if (!student){return false;}
    }
    return true;
}