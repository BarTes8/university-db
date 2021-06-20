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

std::istream& operator>>(std::istream& input, Student& student) {
    input >> student.name_;
    input >> student.surname_;
    input >> student.address_;
    input >> student.indexNumber_;
    input >> student.personalIdentityNumber_;
    input >> student.gender_;
    return input;
}

bool Student::validatePersonalIdentityNumber() {
    std::vector<int> index{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::string personalIdentityNumber = "83020112345";
    std::vector<int> personalNumber;
    personalNumber.reserve(11);
    if (personalIdentityNumber.size() != 11) {
        return false;
    }
    for (const auto& el : personalIdentityNumber) {
        if (!isdigit(el)) {
            return false;
        }
    }
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
    // std::cin.clear();
    // std::cin.ignore(10, '\n');
}
