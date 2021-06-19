#include "Student.hpp"

Student::Student(std::string name, std::string surname, std::string address, std::string indexNumber, 
                 std::string personalIdentityNumber, char gender)
    : name_(name)
    , surname_(surname)
    , address_ (address)
    , indexNumber_ (indexNumber)
    , personalIdentityNumber_ (personalIdentityNumber)
    , gender_ (gender)
{}

void Student::addStudent() {
    std::cout << "Name: " ;
    getline(std::cin, name_);
    std::cout << "Surname: " ;
    getline(std::cin, surname_);
    std::cout << "Address: " ;
    getline(std::cin, address_);
    std::cout << "Index number: " ;
    getline(std::cin, indexNumber_);
    std::cout << "Personal identity number: " ;
    getline(std::cin, personalIdentityNumber_);
    std::cout << "Gender: " ;
    std::getchar() >> gender_;
}
