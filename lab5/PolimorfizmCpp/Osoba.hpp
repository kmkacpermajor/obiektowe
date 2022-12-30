#ifndef OSOBA_H
#define OSOBA_H

#include<iostream>
#include<string>

class Osoba{
protected:
    std::string name;
    std::string surname;

public:
    Osoba(std::string newName, std::string newSurname);

    virtual ~Osoba();

    void setNameAndSurname(std::string newName, std::string newSurname);
    
    std::string getName();

    std::string getSurname();

    void virtual przedstaw() = 0;
};

#endif