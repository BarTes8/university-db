#include "Student.hpp"

Student::Student(std::string name, std::string surname, std::string address, std::string indexNumber, 
                 std::string personalIdentityNumber, char gender)
    : name_(name)
    , surname_(surname)
    , address_ (address)
    , indexNumber_ (indexNumber)
    , personalIdentityNumber_ (personalIdentityNumber)
    , gender_ (gender)
{}
