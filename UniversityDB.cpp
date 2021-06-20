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

void UniversityDB::showSingleStudent(size_t index) {
    std::cout << "Name: " << dataBase_[index].getName() << '\n';
    std::cout << "Surname: " << dataBase_[index].getSurname() << '\n';
    std::cout << "Address: " << dataBase_[index].getAddress() << '\n';
    std::cout << "Index number: " << dataBase_[index].getIndexNumber() << '\n';
    std::cout << "Personal identity number: " << dataBase_[index].getPersonalIdentityNumber() << '\n';
    std::cout << "Gender: " << dataBase_[index].getGender() << '\n';
}

void UniversityDB::findStudentBySurname() {
    std::string searchedSurname {};
    std::cout << "Enter the name you are looking for: " << '\n';
    std::getline(std::cin, searchedSurname); 
    size_t counter {};
    for (const auto& it : dataBase_) {
        counter++;
        if (it.getSurname() == searchedSurname) {
            showSingleStudent(counter); 
        } else {
            std::cout << "There is no such surname" << '\n';
        } 
    }
}

void UniversityDB::findStudentByPersonalIdentityNumber() {
    std::string PersonalIdentityNumber {};
    std::cout << "Enter the personal identity number you are looking for: " << '\n';
    std::getline(std::cin, PersonalIdentityNumber);
    size_t counter {};
    for (const auto& it : dataBase_) {
        counter++;
        if (it.getSurname() == PersonalIdentityNumber) {
            showSingleStudent(counter); 
        } else {
            std::cout << "There is no such personal identity number" << '\n';
        }
    } 
} 