#pragma once
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "Student.hpp"

class UniversityDB {
public:
    UniversityDB();

    ~UniversityDB();

    std::vector<Student> getDataBase() const { return dataBase_; }
    Student getStudentData(std::string);

    void addStudent();
    void showUniversityDB();
    void showSingleStudent(size_t);
    void findStudentBySurname();
    void findStudentByPersonalIdentityNumber();
    void sortStudentsByPersonalIdentityNumber();
    void sortStudentsBySurname();
    void removeStudentByIndexNumber();
    void stringValidation(std::string&);
   
    void readFromFileManually();
    void writeStudentToFileManually();
    
private:
    std::vector<Student> dataBase_;
};