#include "AllStudents.hpp"

void AllStudents::addStudent() {
    Student student;

    std::cout << "Name: " ;
    getline(std::cin, student.name_);
    std::cout << "Surname: " ;
    getline(std::cin, student.surname_);
    std::cout << "Address: " ;
    getline(std::cin, student.address_);
    std::cout << "Index number: " ;
    getline(std::cin, student.indexNumber_);
    std::cout << "Personal identity number: " ;
    getline(std::cin, student.personalIdentityNumber_);
    std::cout << "Gender: " ;
    std::cin >> student.gender_;
    std::cin.clear();
    std::cin.ignore();

    students_.push_back(student);
};

