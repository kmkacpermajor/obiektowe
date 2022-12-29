#ifndef OSOBA_H
#define OSOBA_H

#include<string>

class Osoba{
protected:
    std::string name;
    std::string surname;

public:
    Osoba(std::string newName, std::string newSurname);

    void setNameAndSurname(std::string newName, std::string newSurname);
    
    std::string getName();

    std::string getSurname();

    void przedstaw();
};

#endif