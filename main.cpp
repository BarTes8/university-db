#include <iostream>
#include "Student.hpp"
#include "UniversityDB.hpp"

void showMenu();

int main() {  
    UniversityDB universityDB;
    Student student2;
    universityDB.addStudent();
    universityDB.showUniversityDB();
}

void showMenu() {
    char choice;
    std::cout << "Main menu\n";
    std::cout << "1. Add student\n";
    std::cout << "2. Display list of students\n";
    std::cout << "3. Search by surname\n";
    std::cout << "4. Search by personal identity number\n";
    std::cout << "5. Sort by personal identity number\n";
    std::cout << "6. Sort by surname\n";
    std::cout << "7. Delete by index number\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
    std::cin >> choice;

    switch(choice) {
        case '1':

        break;
        case '2':

        break;
        case '3':

        break;
        case '4':

        break;
        case '5':

        break;
        case '6':

        break;
        case '7':

        break;
        case '8':
        exit(0);
    }
}