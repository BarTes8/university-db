#include <iostream>
#include "Student.hpp"
#include "AllStudents.hpp"

int main() {
    // Student student1("Adam", "Nowak", "Wroclaw", "12445", "12312421", 'm');
    // std::cout << student1.getName() << '\n';
    // std::cout << student1.getSurname() << '\n';
    // std::cout << student1.getAddress() << '\n';
    // std::cout << student1.getIndexNumber() << '\n';
    // std::cout << student1.getPersonalIdentityNumber() << '\n';
    // std::cout << student1.getGender() << '\n';

    AllStudents allstudents;
    Student student2;
    allstudents.addStudent();
    allstudents.showAllStudents();


}