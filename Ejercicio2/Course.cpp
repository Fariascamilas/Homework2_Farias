#pragma once
#include "Course.h"
#include <algorithm>
#include <iostream>

ostream& operator <<(ostream &output,const Course &c){
    output<<"Curso: "<<c.name<<"\n Estudiantes:\n";
    for(shared_ptr<Student> student : c.students){
        output<<"Nombre:"<<student->getFullName()<<"\t"<<"Legajo:"<<student->getRecordNumber()<<"\t"<<"Promedio General:"<<student->getGPA()<<endl;
    }
}

void Course::printCourse() const {
    sort(students.begin(), students.end());
    cout<<this<<endl;
}

bool Course::isEnrolled(int record){
    for(shared_ptr<Student> student : students){
        if (student->getRecordNumber() == record){
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