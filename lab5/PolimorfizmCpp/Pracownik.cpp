#include"Pracownik.hpp"

Pracownik::Pracownik(std::string newName, std::string newSurname, std::string newPosition, float newSalary) : Osoba(newName, newSurname){
    position = newPosition;
    salary = newSalary;
}

void Pracownik::setPosition(std::string newPosition){
    position = newPosition;
}

void Pracownik::setSalary(float newSalary){
    salary = newSalary;
}

std::string Pracownik::getPosition(){
    return position;
}

float Pracownik::getSalary(){
    return salary;
}

void Pracownik::przedstaw(){
    std::cout << "Nazywam się " << name << " " << surname << std::endl;
    std::cout << "Pracuję jako " << position << " i zarabiam " << salary << std::endl;
}