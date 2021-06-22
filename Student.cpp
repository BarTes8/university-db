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
    return 0; 
}

bool Student::isDayCodeCorrect(size_t year) {
    //bool isLeap = std::chrono::year::is_leap(year);
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

bool Student::validatePersonalIdentityNumber() {
    std::vector<int> index{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::string personalIdentityNumber = "83020112345";
    std::vector<int> personalNumber;
    personalNumber.reserve(11);
   
    
    if (personalIdentityNumber[9] % 2 == 0 && gender_ != "k") {
        return false;
    }
    if (personalIdentityNumber[9] % 2 != 0 && gender_ != "m") {
        return false;
    }
    for (auto& el : personalIdentityNumber) {
        personalNumber.push_back(el - '0');
    }
    int sum = std::inner_product(begin(personalNumber), end(personalNumber) - 1, begin(index), 0);

    do {
        sum %= 10;
    } while (sum > 10);
    if (sum == 0 && personalIdentityNumber[10] - '0' == 0) {
        return true;
    }

    if (10 - sum != personalIdentityNumber[10]) {
        return false;
    }
    return true;
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
