#pragma once
#include <string>
#include <vector>
using namespace std;

class Student{
    private:
        const char* fullName;
        int recordNumber;
        vector<int> grades;
    
    public:
        Student(const char* _fullName, int _recordNumber, vector<int> _grades);
        bool operator<(const Student& other) const;
        
        const char* getFullName() const;
        int getRecordNumber() const;
        float getGPA() const; // Grade Point Average (GPA)
    };