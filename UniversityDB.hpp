#pragma once
#include "Student.hpp"
#include <fstream>
#include <vector>

class UniversityDB {
public:
    UniversityDB();

    ~UniversityDB();

    std::vector<Student> getDataBase() const { return dataBase_; }

    void addStudent();
    void showUniversityDB();
    void writeStudentToFile(Student);
private:
    std::vector<Student> dataBase_;
};