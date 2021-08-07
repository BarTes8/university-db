#include "Student.hpp"

// Student::Student() {
//     name_ = {};
//     surname_ = {};
//     address_ = {};
//     personalIdentityNumber_ = {};
//     gender_ = {};
//     indexNumber_ = {};
// }

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

bool Student::operator==(const Student& student) const {
    return student.indexNumber_ == indexNumber_;
}

void Student::getStudent() {
    // Person::getPerson();
    do {
        std::cout << "Index number: ";
        std::getline(std::cin, indexNumber_);
    } while(!validateIndexNumber());
}
  




