#include <iostream>
#include "Menu.hpp"
#include "Student.hpp"
#include "UniversityDB.hpp"

void showMenu();

int main() {  
    UniversityDB universityDB;

    std::vector<Student> getDataBase();
    readStudentsFromFile(getDataBase);
        
    while (true) {
        selectOption(universityDB);
    }
    
}

