#pragma once
#include "Student.hpp"
#include <vector>

class UniversityDB {
public:
    UniversityDB();

    ~UniversityDB();

    void addStudent();
    void showUniversityDB();
private:
    std::vector<Student> dataBase_;
};