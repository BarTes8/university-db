#pragma once

#include <cctype>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "Person.hpp"

class Student : public Person {
public:
    using Person::Person;
    Student();
    Student(std::string name, 
            std::string surname, 
            std::string address, 
            std::string personalIdentityNumber, 
            std::string gender, 
            std::string indexNumber);

    void getStudent();

    bool operator==(const Student&) const;
    
    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    std::string getIndexNumber() const { return indexNumber_; }
    std::string getPersonalIdentityNumber() const { return personalIdentityNumber_; }
    std::string getGender() const { return gender_; }

    bool hasPersonalIdentityNumberElevenCharacters();
    bool areAllCharactersDigit();
    bool isMonthCodeCorrect();
    bool isDayCodeCorrect();
    bool isGenderCorrect();
    bool isLastNumberCorrect();
    bool validateGenderName();
    bool validateIndexNumber();
    bool validatePersonalIdentityNumber();

    void stringValidation(std::string&);

private:
    std::string indexNumber_{};
};