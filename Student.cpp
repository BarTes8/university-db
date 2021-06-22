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

Student::~Student() {
    std::cout << "Student d-tor" << '\n';
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
}

bool Student::areAllCharactersDigit() {
    for (const auto& el : personalIdentityNumber_) {
        if (!isdigit(el)) {
            return false;
        }
    }
}

bool Student::isMonthCodeCorrect() {
    if ((personalIdentityNumber_[2] - '0') % 2 != 0 && (personalIdentityNumber_[3] - '0') > 2) {
        return false;
    }
    if ((personalIdentityNumber_[2] - '0') % 2 == 0 && (personalIdentityNumber_[3] - '0') == 0) {
        return false;
    }
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
}

bool Student::isLastNumberCorrect() {
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
   
    
   
    
}

void Student::getStudent() {
    std::cout << "Name: ";
    getline(std::cin, name_);
    std::cout << "Surname: ";
    getline(std::cin, surname_);
    std::cout << "Address: ";
    getline(std::cin, address_);
    std::cout << "Index number: ";
    getline(std::cin, indexNumber_);
    std::cout << "Personal identity number: ";
    getline(std::cin, personalIdentityNumber_);
    std::cout << "Gender: ";
    getline(std::cin, gender_);
}
