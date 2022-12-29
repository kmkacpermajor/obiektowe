#include<iostream>
#include"Osoba.hpp"
#include"Student.hpp"
#include"Pracownik.hpp"

int main(){

    Osoba osoba("Kacper", "Majorkowski");

    std::cout << osoba.getName() << std::endl; 

    return 0;
}