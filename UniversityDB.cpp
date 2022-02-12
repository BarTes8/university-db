#include <iostream>

#include "UniversityDB.hpp"

void UniversityDB::addPerson(Person* person) {
    dataBase_.emplace_back(person);
}

//void UniversityDB::showUniversityDB() {
  //  for (const auto& person : dataBase_) {
//    std::cout << "Name: " << person.getName() << '\n';
//        std::cout << "Surname: " << student.getSurname() << '\n';
//        std::cout << "Address: " << student.getAddress() << '\n';
//        std::cout << "Index number: " << student.getIndexNumber() << '\n';
//        std::cout << "Personal identity number: " << student.getPersonalIdentityNumber() << '\n';
//        std::cout << "Gender: " << student.getGender() << '\n';
//        std::cout << "=================================================\n";
//    }
//}

//void UniversityDB::showSingleStudent(const size_t index) {
//    std::cout << "Name: " << dataBase_[index].getName() << '\n';
//    std::cout << "Surname: " << dataBase_[index].getSurname() << '\n';
//    std::cout << "Address: " << dataBase_[index].getAddress() << '\n';
//    std::cout << "Index number: " << dataBase_[index].getIndexNumber() << '\n';
//    std::cout << "Personal identity number: " << dataBase_[index].getPersonalIdentityNumber() << '\n';
//    std::cout << "Gender: " << dataBase_[index].getGender() << '\n';
//}

//void UniversityDB::findStudentBySurname() {
//    std::string searchedSurname{};
//    std::cout << "Enter the name you are looking for: ";
//    std::getline(std::cin, searchedSurname);
//    stringValidation(searchedSurname);
//    size_t index{};
//    bool guard = true;
//    for (const auto& it : dataBase_) {
//        if (it.getSurname() == searchedSurname) {
//            showSingleStudent(index);
//            guard = false;
 //       }
 //       index++;
 //   }
 //   if (guard) {
//        std::cout << "There is no such surname\n";
//    }
//}

//void UniversityDB::findStudentByPersonalIdentityNumber() {
//    std::string PersonalIdentityNumber{};
//    std::cout << "Enter the personal identity number you are looking for: ";
//    std::getline(std::cin, PersonalIdentityNumber);
//    size_t index{};
//    bool guard = true;
//    for (const auto& it : dataBase_) {
 //       if (it.getPersonalIdentityNumber() == PersonalIdentityNumber) {
 //           showSingleStudent(index);
//            guard = false;
//        }
 //       index++;
//    }
//    if (guard) {
//        std::cout << "There is no such personal identity number" << '\n';
//    }
//}

//void UniversityDB::removeStudentByIndexNumber() {
 //   bool guard = true;
 //   std::string indexNumber{};
 //   std::cout << "Enter the index number you are looking for: ";
 //   std::getline(std::cin, indexNumber);
 //   size_t index{};
//    for (auto& it : dataBase_) {
//        if (it.getIndexNumber() == indexNumber) {
//            dataBase_.erase(std::remove(dataBase_.begin(), dataBase_.end(), dataBase_[index]), dataBase_.end());
//            guard = false;
//        }
 //       index++;
 //   }
//    if (guard) {
//        std::cout << "There is no such index number" << '\n';
//    }
//}

//void UniversityDB::sortStudentsByPersonalIdentityNumber() {
//    std::sort(begin(dataBase_), end(dataBase_),
 //             [](Student first, Student second) { return first.getPersonalIdentityNumber() < second.getPersonalIdentityNumber(); });
 //   showUniversityDB();
//}

//void UniversityDB::sortStudentsBySurname() {
//    std::sort(begin(dataBase_), end(dataBase_),
//              [](Student first, Student second) { return first.getSurname() < second.getSurname(); });
 //   showUniversityDB();
//}

//void UniversityDB::writeStudentToFileManually() {
//    std::string filename;
//    std::ofstream file;
//    do {
//        std::cout << "Enter filename: ";
//        getline(std::cin, filename);
//        file.open(filename);
//    } while (file.fail());
//    for (const auto& student : dataBase_) {
 //       file << student.getName() << '|';
 //       file << student.getSurname() << '|';
 //       file << student.getAddress() << '|';
 //       file << student.getIndexNumber() << '|';
//        file << student.getPersonalIdentityNumber() << '|';
 //       file << student.getGender() << '|' << '\n';
 //   }
 //   file.close();
//}

//void UniversityDB::readFromFileManually() {
 //   std::string name, surname, address, indexNumber, personalIdentityNumber, gender, line;
 //   std::string filename;
 //   std::ifstream file;
 //   do {
 //       std::cout << "Enter filename: ";
 //       getline(std::cin, filename);
 //       file.open(filename);
 //   } while (file.fail());
 //   while (getline(file, line)) {
 //       std::stringstream ss(line);
 //       getline(ss, name, '|');
 //       getline(ss, surname, '|');
 //       getline(ss, address, '|');
 //       getline(ss, indexNumber, '|');
 //       getline(ss, personalIdentityNumber, '|');
 //       getline(ss, gender, '|');
 //       dataBase_.emplace_back(Student(name, surname, address, indexNumber, personalIdentityNumber, gender));
//    }
//}

void UniversityDB::stringValidation(std::string& word) {
    for (auto& letter : word) {
        letter = std::tolower(letter);
    }
    for (size_t i = 0; i < word.size(); i++) {
        if (i == 0) {
            word[i] = std::toupper(word[i]);
        }
        if (word[i] == ' ' || word[i] == '-') {
            word[i + 1] = std::toupper(word[i + 1]);
        }
    }
}
