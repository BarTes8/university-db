#include "UniversityDB.hpp"

UniversityDB::UniversityDB() {
    std::cout << "AllStudent c-tor" << '\n';
}

UniversityDB::~UniversityDB() {
    std::cout << "AllStudent d-tor" << '\n';
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


void UniversityDB::showSingleStudent(std::vector<Student>::iterator it) {
    size_t distance = std::distance(begin(dataBase_), it);
    std::cout << "Name: " << dataBase_[distance].getName() << '\n';
    std::cout << "Surname: " << dataBase_[distance].getSurname() << '\n';
    std::cout << "Address: " << dataBase_[distance].getAddress() << '\n';
    std::cout << "Index number: " << dataBase_[distance].getIndexNumber() << '\n';
    std::cout << "Personal identity number: " << dataBase_[distance].getPersonalIdentityNumber() << '\n';
    std::cout << "Gender: " << dataBase_[distance].getGender() << '\n';
}

void UniversityDB::writeStudentToFile(Student student) {
    std::fstream file;
    file.open("UniversityDataBase.txt", std::ios::out | std::ios::app);
    if (file.good()) {
        file << student.getName() << '|';
        file << student.getSurname() << '|';
        file << student.getAddress() << '|';
        file << student.getIndexNumber() << '|';
        file << student.getPersonalIdentityNumber() << '|';
        file << student.getGender() << '|' << '\n';
        file.close();
    }
    else {
        std::cerr << "Error\n";
    }  
}

// std::vector<std::string> UniversityDB::readDataFromFileToDataBase() {

// }

Student UniversityDB::getStudentData(std::string studentData) {
    Student student;
    std::string singleData = "";
    int dataNumber = 1;
    for (size_t i = 0; i < studentData.size(); i++) {
        if (studentData[i] != '|') {
            singleData += studentData[i];
        }
        else {
            switch (dataNumber) {
            case 1:
                student.getName() = singleData;
                break;
            case 2:
                student.getSurname() = singleData;
                break;
            case 3:
                student.getAddress() = singleData;
                break;
            case 4:
                student.getIndexNumber() = singleData;
                break;
            case 5:
                student.getPersonalIdentityNumber() = singleData;
                break;
            case 6:
                student.getGender() = singleData;
                break;
            }
            singleData = "";
            dataNumber++;
        }
    }
    return student;
}

void UniversityDB::readStudentsFromFile(std::vector<Student>& getDataBase) {
    Student student;
    std::string studentData = "";
    std::fstream file;
    file.open("UniversityDataBase.txt", std::ios::in);
    if(file.good()) {
        while (getline(file, studentData)) {
            student = getStudentData(studentData);
            getDataBase.push_back(student);
        }
        file.close();
    }
    else {
        std::cerr << "Error\n";
    }
}


// void UniversityDB::findStudentBySurname() {
//     std::string searchedSurname {};
//     std::cout << "Enter the name you are looking for: " << '\n';
//     std::getline(std::cin, searchedSurname); 
//     auto it = std::find_if(begin(dataBase_), end(dataBase_), searchedSurname);
//     if (it != end(dataBase_)) {
//         showSingleStudent(it); 
//     } 
//     std::cout << "There is no such surname" << '\n';
// }

// void UniversityDB::findStudentByPersonalIdentityNumber() {
//     std::string PersonalIdentityNumber {};
//     std::cout << "Enter the personal identity number you are looking for: " << '\n';
//     std::getline(std::cin, PersonalIdentityNumber); 
//     auto it = std::find_if(begin(dataBase_), end(dataBase_), PersonalIdentityNumber);
//     if (it != end(dataBase_)) {
//         showSingleStudent(it); 
//     } 
//     std::cout << "There is no such personal identity number" << '\n';
// }

