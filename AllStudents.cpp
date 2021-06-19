#include "AllStudents.hpp"
#include <iomanip>

void AllStudents::addStudent() {
    
    
};

void AllStudents::showAllStudents() {
    for (const auto& student : students_) {
        std::cout << student.getName() << '\n';
        std::cout << student.getSurname() << '\n';
        std::cout << student.getAddress() << '\n';
        std::cout << student.getIndexNumber() << '\n'; 
        std::cout << student.getPersonalIdentityNumber() << '\n';
        std::cout << student.getGender() << '\n';
    }
}



