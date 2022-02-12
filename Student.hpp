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
    Student(std::string name, 
            std::string surname, 
            std::string address, 
            std::string personalIdentityNumber, 
            std::string gender, 
            std::string indexNumber);

    void getStudent();

    bool operator==(const Student&) const;
    
    std::string getIndexNumber() const { return indexNumber_; }
   
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