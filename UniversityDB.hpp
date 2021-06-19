#pragma once
#include "Student.hpp"
#include <algorithm>
#include <vector>

class UniversityDB {
public:
    UniversityDB();

    ~UniversityDB();

    std::vector<Student> getDataBase() const { return dataBase_; }

    void addStudent();
    void showUniversityDB();
    void showSingleStudent(std::vector<Student>::iterator);
    void findStudentBySurname();
    void findStudentByPersonalIdentityNumber();
    
private:
    std::vector<Student> dataBase_;
};