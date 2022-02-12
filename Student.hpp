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
   


private:
    bool validateIndexNumber();
    
    std::string indexNumber_{};
};