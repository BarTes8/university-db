#include "StudentsFile.hpp"

void StudentsFile::writeStudentToFile {
    Student student;
    student.getStudent();
    fstream file;
    file.open("UniversityDataBase.txt", ios::out | ios::app);
    if (file.good()) {
        file << 
    }
    else {
        std::cerr << ""
    }
}