#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include"Osoba.h"

class Pracownik : public Osoba{
private:
    std::string position;
    float salary;

public:
    Pracownik(std::string newName, std::string newSurname, std::string newPosition, float newSalary);

    void setPosition(std::string newPosition);

    void setSalary(float newSalary);

    std::string getPosition();

    float getSalary();

    void przedstaw();
};

#endif