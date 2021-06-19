#pragma once
#include "Student.hpp"
#include <vector>

class UniversityDB {
public:
    UniversityDB();

    ~UniversityDB();

    std::vector<Student> getDataBase() const { return dataBase_; }

    void addStudent();
    void showUniversityDB();
private:
    std::vector<Student> dataBase_;
};