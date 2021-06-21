#include "UniversityDB.hpp"

UniversityDB::UniversityDB() {
    std::cout << "UniversityDB c-tor" << '\n';
}

UniversityDB::~UniversityDB() {
    std::cout << "UniversityDB d-tor" << '\n';
}

void UniversityDB::addStudent() {
    Student student;
    student.getStudent();
    dataBase_.push_back(student);
    writeStudentToFile(student);
}

void UniversityDB::showUniversityDB() {
    for (const auto& student : dataBase_) {
        std::cout << student.getName() << '\n';
        std::cout << student.getSurname() << '\n';
        std::cout << student.getAddress() << '\n';
        std::cout << student.getIndexNumber() << '\n';
        std::cout << student.getPersonalIdentityNumber() << '\n';
        std::cout << student.getGender() << '\n';
    }
}

void UniversityDB::showSingleStudent(const size_t index) {
    std::cout << "Name: " << dataBase_[index].getName() << '\n';
    std::cout << "Surname: " << dataBase_[index].getSurname() << '\n';
    std::cout << "Address: " << dataBase_[index].getAddress() << '\n';
    std::cout << "Index number: " << dataBase_[index].getIndexNumber() << '\n';
    std::cout << "Personal identity number: " << dataBase_[index].getPersonalIdentityNumber() << '\n';
    std::cout << "Gender: " << dataBase_[index].getGender() << '\n';
}

void UniversityDB::findStudentBySurname() {
    std::string searchedSurname{};
    std::cout << "Enter the name you are looking for: ";
    std::getline(std::cin, searchedSurname);
    size_t index{};
    bool guard = true;
    for (const auto& it : dataBase_) {
        if (it.getSurname() == searchedSurname) {
            showSingleStudent(index);
            guard = false;
        }
        index++;
    }
    if (guard) {
        std::cout << "There is no such surname\n";
    }
}

void UniversityDB::findStudentByPersonalIdentityNumber() {
    std::string PersonalIdentityNumber{};
    std::cout << "Enter the personal identity number you are looking for: ";
    std::getline(std::cin, PersonalIdentityNumber);
    size_t index{};
    bool guard = true;
    for (const auto& it : dataBase_) {
        if (it.getPersonalIdentityNumber() == PersonalIdentityNumber) {
            showSingleStudent(index);
            guard = false;
        }
        index++;
    }
    if (guard) {
        std::cout << "There is no such personal identity number" << '\n';
    }
}

void UniversityDB::removeStudentByIndexNumber() {
    bool guard = true;
    std::string indexNumber{};
    std::cout << "Enter the index number you are looking for: ";
    std::getline(std::cin, indexNumber);
    size_t index{};
    for (auto& it : dataBase_) {
        if (it.getIndexNumber() == indexNumber) {
            dataBase_.erase(std::remove(dataBase_.begin(), dataBase_.end(), dataBase_[index]), dataBase_.end());
            removeStudentFromFile(dataBase_);
            guard = false;
        }
        index++;
    }
    if (guard) {
        std::cout << "There is no such index number" << '\n';
    }
}

void UniversityDB::sortStudentsByPersonalIdentityNumber() {
    std::sort(begin(dataBase_), end(dataBase_),
              [](Student first, Student second) { return first.getPersonalIdentityNumber() < second.getPersonalIdentityNumber(); });
    showUniversityDB();
}

void UniversityDB::sortStudentsBySurname() {
    std::sort(begin(dataBase_), end(dataBase_),
              [](Student first, Student second) { return first.getSurname() < second.getSurname(); });
    showUniversityDB();
}

void UniversityDB::writeStudentToFile(Student& student) {
    std::fstream file("UniversityDataBase.txt", file.out | file.app);
    if (file.is_open()) {
        file << student.getName() << '|';
        file << student.getSurname() << '|';
        file << student.getAddress() << '|';
        file << student.getIndexNumber() << '|';
        file << student.getPersonalIdentityNumber() << '|';
        file << student.getGender() << '|' << '\n';
        file.close();
    }
}

void UniversityDB::removeStudentFromFile(std::vector<Student>& database) {
    std::fstream file("UniversityDataBase.txt", file.out);
    if (file.is_open()) {
        for (auto student : database) {
            file << student.getName() << '|';
            file << student.getSurname() << '|';
            file << student.getAddress() << '|';
            file << student.getIndexNumber() << '|';
            file << student.getPersonalIdentityNumber() << '|';
            file << student.getGender() << '|' << '\n';
        }
        file.close();
    }
}

void UniversityDB::readStudentsFromFile() {
    std::string name, surname, address, indexNumber, personalIdentityNumber, gender, line;
    std::ifstream file("UniversityDataBase.txt", file.in);
    if (file.is_open()) {
        while (getline(file, line)) {
            std::stringstream ss(line);
            getline(ss, name, '|');
            getline(ss, surname, '|');
            getline(ss, address, '|');
            getline(ss, indexNumber, '|');
            getline(ss, personalIdentityNumber, '|');
            getline(ss, gender, '|');
            dataBase_.emplace_back(Student(name, surname, address, indexNumber, personalIdentityNumber, gender));
        }
    }
}
