#include "UniversityDB.hpp"

UniversityDB::UniversityDB() {
    std::cout << "AllStudent c-tor" << '\n';
}
UniversityDB::~UniversityDB() {
    std::cout << "AllStudent d-tor" << '\n';
}

void UniversityDB::addStudent() {
    Student student;
    student.getStudent();
    dataBase_.push_back(student);
    writeStudentToFile(student);
}

void UniversityDB::showUniversityDB() {
    for (const auto& student : dataBase_) {
        std::cout << student.getName() << '\n';
        std::cout << student.getSurname() << '\n';
        std::cout << student.getAddress() << '\n';
        std::cout << student.getIndexNumber() << '\n'; 
        std::cout << student.getPersonalIdentityNumber() << '\n';
        std::cout << student.getGender() << '\n';
    }
}

void UniversityDB::writeStudentToFile(Student student) {
    std::fstream file;
    file.open("UniversityDataBase.txt", std::ios::out | std::ios::app);
    if (file.good()) {
        file << student.getName() << '|';
        file << student.getSurname() << '|';
        file << student.getAddress() << '|';
        file << student.getIndexNumber() << '|';
        file << student.getPersonalIdentityNumber() << '|';
        file << student.getGender() << '|' << '\n';
        file.close();
    }
    else {
        std::cerr << "Error";
    }  
}



