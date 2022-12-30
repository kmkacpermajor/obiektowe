#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include<string>
#include<iostream>
#include"Osoba.hpp"

class Pracownik : public Osoba{
private:
    std::string position;
    float salary;

public:
    Pracownik(std::string newName, std::string newSurname, std::string newPosition, float newSalary);

    ~Pracownik();

    void setPosition(std::string newPosition);

    void setSalary(float newSalary);

    std::string getPosition();

    float getSalary();

    void przedstaw();
};

#endif