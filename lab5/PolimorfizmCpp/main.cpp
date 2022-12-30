#include<iostream>
#include<vector>
#include"Osoba.hpp"
#include"Student.hpp"
#include"Pracownik.hpp"


//zad 8
void foo (Osoba &os) {
    os.przedstaw();
}
void bar (Osoba *os) {
    os->przedstaw();
}

int main(){

    // zad 18
    std::string input;
    std::vector<Osoba*> tablicaOsob;

    do{
        std::cout << "Wpisz:" << std::endl;
        std::cout << "pracownik - aby utworzyć pracownika" << std::endl;
        std::cout << "student - aby utworzyć studenta" << std::endl;
        std::cout << "wyswietl - aby wyświetlić wszystkie obiekty" << std::endl;
        std::cout << "wyjscie - aby wyjść" << std::endl;
        std::cin >> input;

        if (input == "pracownik"){
            std::string imie;
            std::string nazwisko;
            std::string stanowisko;
            float pensja;

            std::cout << "Podaj imie: " << std::endl;
            std::cin >> imie;
            std::cout << "Podaj nazwisko: " << std::endl;
            std::cin >> nazwisko;
            std::cout << "Podaj stanowisko: " << std::endl;
            std::cin >> stanowisko;
            std::cout << "Podaj pensję: " << std::endl;
            std::cin >> pensja;

            Pracownik *pracownik = new Pracownik(imie, nazwisko, stanowisko, pensja);

            tablicaOsob.push_back(pracownik);

        }else if (input == "student")
        {
            std::string imie;
            std::string nazwisko;
            std::string uniwersytet;
            float srednia;

            std::cout << "Podaj imie: " << std::endl;
            std::cin >> imie;
            std::cout << "Podaj nazwisko: " << std::endl;
            std::cin >> nazwisko;
            std::cout << "Podaj uniwersytet: " << std::endl;
            std::cin >> uniwersytet;
            std::cout << "Podaj srednią: " << std::endl;
            std::cin >> srednia;

            Student *student = new Student(imie, nazwisko, uniwersytet, srednia);

            tablicaOsob.push_back(student);   
        }else if (input == "wyswietl"){
            std::cout << std::endl;
            for (auto it=tablicaOsob.begin(); it != tablicaOsob.end(); it++){
                (*it)->przedstaw();
                std::cout << std::endl;
            }
        }else if (input == "wyjscie"){
            continue;    
        }else{
            std::cout << "Nieprawidłowe wejście" << std::endl;
            continue;
        }
        


    }while (input != "wyjscie");

    // zad 19: Wszystko przebiegło bezproblemowo, kiedy iterujemy po wektorze musimy się odnosić do wartości w iteratorze, stąd * przy it


    // //zad 5

    // Student *kacper = new Student("Kacper", "Majorkowski", "PP", 4.0);

    // std::cout << kacper->getName() << std::endl; 
    // kacper->przedstaw();

    // Osoba *przykladowa = new Student("Jan", "Kowalski"); 

    // przykladowa->przedstaw();
    // przykladowa->setNameAndSurname("Adam", "Przykładowy");
    // przykladowa->przedstaw();

    // Pracownik *inny = new Pracownik("Yan", "Xinski", "Informatyk", 35);

    // inny->przedstaw();
    // inny->setPosition("Sprzątacz");
    // inny->przedstaw();
    
    // std::cout << std::endl; 

    // // zad 9

    // foo(*przykladowa);
    // bar(przykladowa);

    // std::cout << std::endl; 

    // //zad 10

    // foo(*inny);
    // bar(inny);

    // delete kacper;
    // delete przykladowa;
    // delete inny;

    // zad 11: Dla pracownika mimo nadpisania funkcji przedstaw w klasie Pracownik wywoływana jest funkcja przedstaw zdefiniowana w klasie Osoba
    //         Funkcje foo i bar przyjmują obiekt Osoba, więc wywoływana jest funkcja przedstaw właśnie z tej klasy

    // zad 12: Tym razem w zad 10 wywoływana jest funkcja klasy Pracownik, virtual zapewnia, że mimo przyjmowania przez funkcję obiektu klasy Osoba
    //         wywołana zostanie nadpisana funkcja dla klasy obiektu podanego do funkcji 

    // zad 15: Nie można, występuje błąd: "invalid new-expression of abstract class type ‘Osoba’". 
    //         Należy utworzyć obiekt typu Osoba, korzystając z konstruktora klasy Student

    // zad 16: Pojawia się dodakowy komunikat "Usuwam obiekt student" przy usuwaniu obiektu "przykladowa"

    return 0;
}