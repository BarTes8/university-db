#pragma once 
#include <fstream>
#include <vector>
#include "Student.hpp"

class StudentsFile {
    void writeStudentToFile();
private:
    std::vector<Student> fileDataBase_;
};