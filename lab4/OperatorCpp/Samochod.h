#include<string>

class Samochod{
private:
    float pojemnosc_baku;
    float poziom_paliwa;
    unsigned int liczba_kilometrow;
    std::string model;

public:
    //zad 3
    Samochod(){
        pojemnosc_baku = 100;
        poziom_paliwa = 50;
        liczba_kilometrow = 0;
        model = "";
    }

    Samochod(float poj, std::string mod){
        pojemnosc_baku = poj;
        if (pojemnosc_baku < 50){
            poziom_paliwa = pojemnosc_baku;
        }else{
            poziom_paliwa = 50;
        }
        liczba_kilometrow = 0;
        model = mod;
    }

    //zad 4
    float getPojemnoscBaku() const{
        return pojemnosc_baku;
    }

    float getPoziomPaliwa() const{
        return poziom_paliwa;
    }

    unsigned int getLiczbaKilometrow() const{
        return liczba_kilometrow;
    }

    std::string getModel() const{
        return model;
    }

    //zad 5
    operator bool () const{
        if (model != "" && pojemnosc_baku > 0)
            return true;
    }

    bool operator !() const {
        if (model == "" && pojemnosc_baku <= 0)
            return true;
    }

    //zad 7
    friend std::ostream & operator << (std::ostream & os, const Samochod & samochod){
        os<<samochod.model<<""<<samochod.poziom_paliwa<<"\n";
        return os;
    }
    //zad 8: chcemy utworzyć funkcję, a nie metodę

    //zad 9
    bool operator < (const Samochod & samochod) const {
        return this->model < samochod.model;
    }
    
    //zad 10: dodajemy const, ponieważ ta metoda gwarantuje, że nie zmienimy wartości obiektu

    //zad 15
    void operator ++ (int) {
        this->poziom_paliwa++;
    }

    void operator , (std::string dodatkowe) {
        this->model = this->model + " " + dodatkowe;
    }

    void operator |= (float nowa_pojemnosc) {
        this->pojemnosc_baku = nowa_pojemnosc;
    }
};