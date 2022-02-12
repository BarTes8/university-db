#pragma once
#include <string>

class Person {
public:
    Person(std::string name, 
           std::string surname, 
           std::string address, 
           std::string personalIdentityNumber, 
           std::string gender);

protected:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string personalIdentityNumber_{};
    std::string gender_{};
};