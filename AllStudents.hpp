#include "Student.hpp"
#include <vector>

class AllStudents {
public:
    AllStudents() = default;

    void addStudent();
    void showAllStudents();

private:
    std::vector<Student> students_ {};

};