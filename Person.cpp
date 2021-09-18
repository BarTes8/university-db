#include "Person.hpp"

Person::Person(std::string name, 
               std::string surname, 
               std::string address, 
               std::string personalIdentityNumber, 
               std::string gender)
    : name_(name)
    , surname_(surname)
    , address_(address)
    , personalIdentityNumber_(personalIdentityNumber)
    , gender_(gender)
{} 