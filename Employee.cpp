#include "Employee.hpp"

Employee::Employee(std::string name,
             std::string surname,
             std::string address,
             std::string personalIdentityNumber,
             std::string gender,
             std::string salary)
    : Person::Person(name, surname, address, personalIdentityNumber, gender)
    , salary_(salary)
{}