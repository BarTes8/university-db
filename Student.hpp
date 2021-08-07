#pragma once

#include "Person.hpp"

#include <cctype>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Student : public Person {
public:
    // Student();
    Student(const std::string& name, 
            const std::string& surname, 
            const std::string& address, 
            const std::string& personalIdentityNumber, 
            const std::string& gender,
            const std::string& indexNumber) : Person(name, surname, address, personalIdentityNumber, gender), indexNumber_(indexNumber)
    {};

    void getStudent();
    bool operator==(const Student&) const;
    std::string getIndexNumber() const { return indexNumber_; }

private:
    std::string indexNumber_{};
    bool validateIndexNumber();
};