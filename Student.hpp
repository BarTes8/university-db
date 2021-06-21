#pragma once

#include <cctype>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
class UniversityDB;
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
    std::string getPersonalIdentityNumber() const { return personalIdentityNumber_; }
    std::string getGender() const { return gender_; }

    // void setName(std::string& name) { name_ = name; }
    // void setSurname(const std::string& surname) { surname_ = surname; }
    // void setAddress(const std::string& address) { address_ = address; }
    // void setIndexNumber(const std::string& indexNumber) { indexNumber_ = indexNumber; }
    // void setPersonalIdentityNumber(const std::string personalIdentityNumber) { personalIdentityNumber_ = personalIdentityNumber; }
    // void setGender(const std::string& gender) { gender_ = gender; }

    void getStudent();
    bool validatePersonalIdentityNumber();

private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string indexNumber_{};
    std::string personalIdentityNumber_{};
    std::string gender_{};
};