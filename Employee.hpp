#include "Person.hpp"

class Employee : public Person {
public:
    Employee(std::string name,
             std::string surname,
             std::string address,
             std::string personalIdentityNumber,
             std::string gender,
             int salary);

private:
    int salary_;
};