#pragma once
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "Person.hpp"

class UniversityDB {
public:

    std::vector<Person*> getDataBase() const { return dataBase_; }
 //   Student getStudentData(std::string);

    void addPerson(Person* person);
   // void showUniversityDB();
  //  void showSingleStudent(size_t);
    //void findStudentBySurname();
  //  void findStudentByPersonalIdentityNumber();
 //   void sortStudentsByPersonalIdentityNumber();
 //   void sortStudentsBySurname();
 //   void removeStudentByIndexNumber();
    void stringValidation(std::string&);
   
 //   void readFromFileManually();
 //   void writeStudentToFileManually();
    
private:
    std::vector<Person*> dataBase_;
};