#pragma once
#include <string>
#include <vector>

class Person {
public:
    Person(std::string name, 
           std::string surname, 
           std::string address, 
           std::string personalIdentityNumber, 
           std::string gender);

    virtual ~Person() = default;

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    std::string getPersonalIdentityNumber() const { return personalIdentityNumber_; }
    std::string getGender() const { return gender_; }

protected:
    bool hasPersonalIdentityNumberElevenCharacters();
    bool areAllCharactersDigit();
    bool isMonthCodeCorrect();
    bool isDayCodeCorrect();
    bool isGenderCorrect();
    bool isLastNumberCorrect();
    bool validateGenderName();
    
    bool validatePersonalIdentityNumber();

    void stringValidation(std::string&);

    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string personalIdentityNumber_{};
    std::string gender_{};
};