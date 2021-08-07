#include "Person.hpp"

// Person::Person() {
//     name_ = {};
//     surname_ = {};
//     address_ = {};
//     personalIdentityNumber_ = {};
//     gender_ = {};
// }

Person::Person( const std::string& name, 
                const std::string& surname, 
                const std::string& address, 
                const std::string& personalIdentityNumber, 
                const std::string& gender)
    : name_(name)
    , surname_(surname)
    , address_(address)
    , personalIdentityNumber_(personalIdentityNumber)
    , gender_(gender)
{}


bool Person::hasPersonalIdentityNumberElevenCharacters() {
    if(personalIdentityNumber_.size() != 11) {
        return false;
    }
    return true;
}

bool Person::areAllCharactersDigit() {
    for (const auto& el : personalIdentityNumber_) {
        if (!isdigit(el)) {
            return false;
        }
    }
    return true;
}

bool Person::isMonthCodeCorrect() {
    if ((personalIdentityNumber_[2] - '0') % 2 != 0 && (personalIdentityNumber_[3] - '0') > 2) {
        return false;
    }
    if ((personalIdentityNumber_[2] - '0') % 2 == 0 && (personalIdentityNumber_[3] - '0') == 0) {
        return false;
    }
    return true;
}

bool Person::isDayCodeCorrect() {
    size_t year {};
    if ((personalIdentityNumber_[2] - '0') == 8 || (personalIdentityNumber_[2] - '0') == 9)
        year = 18 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0');
    if ((personalIdentityNumber_[2] - '0') == 0 || (personalIdentityNumber_[2] - '0') == 1)
        year = 19 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0');
    if ((personalIdentityNumber_[2] - '0') == 2 || (personalIdentityNumber_[2] - '0') == 3)
        year = 20 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0');
    if ((personalIdentityNumber_[2] - '0') == 4 || (personalIdentityNumber_[2] - '0') == 5)
        year = 21 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0');
    if ((personalIdentityNumber_[2] - '0') == 6 || (personalIdentityNumber_[2] - '0') == 7)
        year = 22 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0'); 
    size_t firstDigitOfMonth;
    if ((personalIdentityNumber_[2] - '0') % 2 == 0) {
        firstDigitOfMonth = 0;
    }
    if ((personalIdentityNumber_[2] - '0') % 2 != 0) {
        firstDigitOfMonth = 1;
    }

    size_t month = firstDigitOfMonth * 10 + personalIdentityNumber_[3] - '0';
    size_t day = (personalIdentityNumber_[4] - '0') * 10 + personalIdentityNumber_[5] - '0';

    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (day > 31) {
            return false;
        }
        break;
    case 4: case 6: case 9: case 11:
        if (day > 30) {
            return false;
        }
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day > 29) {
                return false;
            }
        }
        else {
            if (day > 28) {
                return false;
            }
        }
        break;       
    }
    return true;
}


bool Person::isGenderCorrect() {
    if (personalIdentityNumber_[9] % 2 == 0 && gender_ != "F") {
        return false;
    }
    if (personalIdentityNumber_[9] % 2 != 0 && gender_ != "M") {
        return false;
    }
    return true;
}

bool Person::isLastNumberCorrect() {
    std::vector<int> index {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::vector<int> personalNumber;
    personalNumber.reserve(10);
    for (auto& el : personalIdentityNumber_) {
        personalNumber.push_back(el - '0');
    }
    int sum = std::inner_product(begin(personalNumber), end(personalNumber) - 1, begin(index), 0);
    do {
        sum %= 10;
    } while (sum > 10);
    if (sum == 0 && personalIdentityNumber_[10] - '0' == 0) {
        return true;
    }
    if (10 - sum != personalIdentityNumber_[10] - '0') {
        return false;
    }
    return true;
}

bool Person::validatePersonalIdentityNumber() {
   if (hasPersonalIdentityNumberElevenCharacters()
        && areAllCharactersDigit()
        && isMonthCodeCorrect()
        && isGenderCorrect()
        && isDayCodeCorrect() 
        && isLastNumberCorrect()) {
            return true;
        }
    std::cout << "Incorrect personal identity number. Try again." << '\n';
    return false;       
}

void Person::stringValidation(std::string& word) {
    for (auto& letter : word) {
        letter = std::tolower(letter);
    }
    for (size_t i = 0; i < word.size(); i++) {
        if (i == 0) {
            word[i] = std::toupper(word[i]);
        }
        if (word[i] == ' ' || word[i] == '-') {
            word[i+1] = std::toupper(word[i+1]);
        }
    }
}

bool Person::validateGenderName() {
    if (gender_ == "f" || gender_ == "F") {
        gender_ = "F";
        return true;
    } 
    if (gender_ == "m" || gender_ == "M") {
        gender_ = "M";
        return true;
    } 
    return false;
}

void Person::getPerson() {
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
        std::cout << "Gender (f / m): ";
        std::getline(std::cin, gender_);
    } while (!validateGenderName());
    do {
        std::cout << "Personal identity number: ";
        std::getline(std::cin, personalIdentityNumber_);
    } while (!validatePersonalIdentityNumber());   
}
