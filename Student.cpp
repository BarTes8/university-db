#include "Student.hpp"

Student::Student(std::string name, 
                 std::string surname, 
                 std::string address,
                 std::string personalIdentityNumber, 
                 std::string gender,
                 std::string indexNumber) 
    : Person::Person(name, surname, address, personalIdentityNumber, gender)
    , indexNumber_(indexNumber)
{}

void Student::getStudent() {
    std::cout << "Name: ";
    std::getline(std::cin, name_);
    stringValidation(name_); 
    std::cout << "Surname: ";
    std::getline(std::cin, surname_);
    stringValidation(surname_);
    std::cout << "Address: ";
    std::getline(std::cin, address_);
    stringValidation(address_);
    do {
        std::cout << "Index number: ";
        std::getline(std::cin, indexNumber_);
    } while(!validateIndexNumber());
    do {
        std::cout << "Gender (f / m): ";
        std::getline(std::cin, gender_);
    } while (!validateGenderName());
    do {
        std::cout << "Personal identity number: ";
        std::getline(std::cin, personalIdentityNumber_);
    } while (!validatePersonalIdentityNumber());   
}

bool Student::operator==(const Student& student) const {
    return student.indexNumber_ == indexNumber_;
}

bool Student::validateIndexNumber() {
    if(indexNumber_.size() != 6) {
        std::cout << "Index number must have 6 digits.\n";
        return false;
    }
    for (const auto el : indexNumber_) {
        if (!isdigit(el)) {
            return false;
        }
    }
    return true;
}
