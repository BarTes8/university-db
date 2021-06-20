#pragma once

#include <string>
#include <iostream>

class Student {
public:
    Student();
    Student(std::string, std::string, std::string, std::string, std::string, std::string);

    ~Student();

    bool operator==(const Student&) const;

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    std::string getIndexNumber() const { return indexNumber_; }
    std::string getPersonalIdentityNumber () const { return personalIdentityNumber_; }
    std::string getGender() const { return gender_; }

    void getStudent();
    
private:
    std::string name_ {};
    std::string surname_ {};
    std::string address_ {};
    std::string indexNumber_ {};
    std::string personalIdentityNumber_ {};
    std::string gender_ {};
};