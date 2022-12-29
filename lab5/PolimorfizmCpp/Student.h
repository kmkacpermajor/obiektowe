#ifndef STUDENT_H
#define STUDENT_H

#include"Osoba.h"

class Student : public Osoba{
private:
    std::string universityName;
    float avgGrades;

public:
    Student(std::string newName, std::string newSurname, std::string newUniversityName, float newAvgGrades);

    void setUniversityName(std::string newUniversityName);

    void setAvgGrades(float newAvgGrades);

    std::string getUniversityName();

    float getAvgGrades();
    
    void przedstaw();
};

#endif