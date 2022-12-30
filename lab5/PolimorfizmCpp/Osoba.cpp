#include"Osoba.hpp"

Osoba::Osoba(std::string newName, std::string newSurname){
    name = newName;
    surname = newSurname; 
}

Osoba::~Osoba(){
    std::cout << "Usuwam obiekt osoba" << std::endl;
}

void Osoba::setNameAndSurname(std::string newName, std::string newSurname){
    name = newName;
    surname = newSurname; 
}

std::string Osoba::getName(){
    return name;
}

std::string Osoba::getSurname(){
    return surname;
}

void Osoba::przedstaw(){
    std::cout << "Nazywam się " << name << " " << surname << std::endl;
}