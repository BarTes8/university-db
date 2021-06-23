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

    void addStudent();
    void showUniversityDB();
    void showSingleStudent(size_t);
    void findStudentBySurname();
    void findStudentByPersonalIdentityNumber();
    void sortStudentsByPersonalIdentityNumber();
    void sortStudentsBySurname();
    void removeStudentByIndexNumber();
    
    Student getStudentData(std::string);
    void writeStudentToFile(Student&);
    void removeStudentFromFile(std::vector<Student>&);
    void readStudentsFromFile();

    void stringValidation(std::string&);

private:
    std::vector<Student> dataBase_;
};