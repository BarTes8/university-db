#include "AllStudents.hpp"
#include <iomanip>

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

void AllStudents::showAllStudents() {
    for (const auto& student : students_) {
        std::cout << student.name_;
        std::cout << student.surname_;
        std::cout << student.address_;
        std::cout << student.indexNumber_;
        std::cout << student.personalIdentityNumber_;
        std::cout << student.gender_;
        std::cout << std::endl;
    }
}



