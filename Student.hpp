#pragma once

#include <string>
#include <iostream>

class Student {
public:
    void addStudent();
private:
    std::string name_ {};
    std::string surname_ {};
    std::string address_ {};
    std::string indexNumber_ {};
    std::string personalIdentityNumber_ {};
    char gender_ {};
};