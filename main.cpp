#include <iostream>
#include "Menu.hpp"
#include "Student.hpp"
#include "UniversityDB.hpp"

void showMenu();

int main() {  
    UniversityDB universityDB;

    // std::vector<Student> dataBase;
    // universityDB.readStudentsFromFile();
        
    while (true) {
        selectOption(universityDB);
    }
    
}

