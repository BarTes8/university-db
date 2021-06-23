#include "Student.hpp"

Student::Student() {
    name_ = "";
    surname_ = "";
    address_ = "";
    indexNumber_ = "";
    personalIdentityNumber_ = "";
    gender_ = "";
    std::cout << "Student c-tor" << '\n';
}

Student::Student(std::string name, std::string surname, std::string address, std::string indexNumber, std::string personalIdentityNumber, std::string gender)
    : name_(name), surname_(surname), address_(address), indexNumber_(indexNumber), personalIdentityNumber_(personalIdentityNumber), gender_(gender) {}

bool Student::operator==(const Student& student) const {
    return student.indexNumber_ == indexNumber_;
}

bool Student::hasPersonalIdentityNumberElevenCharacters() {
    if(personalIdentityNumber_.size() != 11) {
        return false;
    }
    return true;
}

bool Student::areAllCharactersDigit() {
    for (const auto& el : personalIdentityNumber_) {
        if (!isdigit(el)) {
            return false;
        }
    }
    return true;
}

bool Student::isMonthCodeCorrect() {
    if ((personalIdentityNumber_[2] - '0') % 2 != 0 && (personalIdentityNumber_[3] - '0') > 2) {
        return false;
    }
    if ((personalIdentityNumber_[2] - '0') % 2 == 0 && (personalIdentityNumber_[3] - '0') == 0) {
        return false;
    }
    return true;
}

size_t Student::getYear() {
    if ((personalIdentityNumber_[2] - '0') == 8 || (personalIdentityNumber_[2] - '0') == 9)
        return 18 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0');
    if ((personalIdentityNumber_[2] - '0') == 0 || (personalIdentityNumber_[2] - '0') == 1)
        return 19 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0');
    if ((personalIdentityNumber_[2] - '0') == 2 || (personalIdentityNumber_[2] - '0') == 3)
        return 20 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0');
    if ((personalIdentityNumber_[2] - '0') == 4 || (personalIdentityNumber_[2] - '0') == 5)
        return 21 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0');
    if ((personalIdentityNumber_[2] - '0') == 6 || (personalIdentityNumber_[2] - '0') == 7)
        return 22 * 100 + (personalIdentityNumber_[0] - '0') * 10 + (personalIdentityNumber_[1] - '0');  

}

bool Student::isGenderCorrect() {
    if (personalIdentityNumber_[9] % 2 == 0 && gender_ != "k") {
        return false;
    }
    if (personalIdentityNumber_[9] % 2 != 0 && gender_ != "m") {
        return false;
    }
    return true;
}

bool Student::isLastNumberCorrect() {
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
    if (10 - sum != personalIdentityNumber_[10]) {
        return false;
    }
    return true;
}

 bool Student::validatePersonalIdentityNumber() {
//    if (hasPersonalIdentityNumberElevenCharacters()
//         && areAllCharactersDigit()
//         && isMonthCodeCorrect()
//         && isGenderCorrect()) {
            
//         }
    return true;
}



bool Student::validateGenderName() {
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

void Student::stringValidation(std::string& word) {
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

void Student::getStudent() {
    std::cout << "Name: ";
    getline(std::cin, name_);
    stringValidation(name_); 
    std::cout << "Surname: ";
    getline(std::cin, surname_);
    stringValidation(surname_);
    std::cout << "Address: ";
    getline(std::cin, address_);
    stringValidation(address_);
    std::cout << "Index number: ";
    getline(std::cin, indexNumber_);
    do {
        std::cout << "Gender (f / m): ";
        getline(std::cin, gender_);
    } while (!validateGenderName());
    do {
        std::cout << "Personal identity number: ";
        getline(std::cin, personalIdentityNumber_);
    } while (!validatePersonalIdentityNumber());
    
}
