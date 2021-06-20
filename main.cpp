#include <iostream>
#include "Menu.hpp"
#include "Student.hpp"
#include "UniversityDB.hpp"

void showMenu();

int main() {  
    UniversityDB universityDB;
    while (true) {
        selectOption(universityDB);
    }
    
}

