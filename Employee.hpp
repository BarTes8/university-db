#include "Person.hpp"

class Employee : public Person {
public:
    Employee(std::string name,
             std::string surname,
             std::string address,
             std::string personalIdentityNumber,
             std::string gender,
             std::string salary);
             
private:
    std::string salary_;
};