#pragma once
#include <string>

class Person {
public:
    // Person();
    Person(const std::string& name, 
            const std::string& surname, 
            const std::string& address, 
            const std::string& personalIdentityNumber, 
            const std::string& gender);

    void getPerson();

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    std::string getPersonalIdentityNumber() const { return personalIdentityNumber_; }
    std::string getGender() const { return gender_; }

protected:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string personalIdentityNumber_{};
    std::string gender_{};

    bool hasPersonalIdentityNumberElevenCharacters();
    bool areAllCharactersDigit();
    bool isMonthCodeCorrect();
    bool isDayCodeCorrect();
    bool isGenderCorrect();
    bool isLastNumberCorrect();
    bool validateGenderName();
    bool validatePersonalIdentityNumber();
    void stringValidation(std::string&);
};