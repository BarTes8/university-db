#include "Student.hpp"
#include <vector>

class AllStudents {
public:
    AllStudents() = default;

    void addStudent();

private:
    std::vector<Student> students_ {};

};