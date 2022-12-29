#include<string>
#include<iostream>
#include"Student.h"

Student::Student(std::string newName, std::string newSurname, std::string newUniversityName, float newAvgGrades) : Osoba(newName, newSurname){
    universityName = newUniversityName;
    avgGrades = newAvgGrades;
}

void Student::setUniversityName(std::string newUniversityName){
    universityName = newUniversityName;
}

void Student::setAvgGrades(float newAvgGrades){
    avgGrades = newAvgGrades;
}

std::string Student::getUniversityName(){
    return universityName;
}

float Student::getAvgGrades(){
    return avgGrades;
}

void Student::przedstaw(){
    std::cout << "Nazywam się " << name << " " << surname << std::endl;
    std::cout << "Ucze się na " << universityName << " ze średnią " << avgGrades << std::endl;
}