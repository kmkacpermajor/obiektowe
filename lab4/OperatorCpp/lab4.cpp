#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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
    bool operator ++ (int) {
        this->poziom_paliwa++;
    }

    bool operator , (std::string dodatkowe) {
        this->model = this->model + " " + dodatkowe;
    }

    bool operator |= (float nowa_pojemnosc) {
        this->pojemnosc_baku = nowa_pojemnosc;
    }
};

// zad 12
struct cmp{
    bool operator () (const Samochod & a, const Samochod & b) const{
        return a.getPojemnoscBaku() < b.getPojemnoscBaku();
    }
};

int main(){
    Samochod s1(123, "audi");
    Samochod s2(0, "bmw");
    Samochod s3(200, "");

    if(s1){
        std::cout << "Model nie jest pustym stringiem i pojemność baku większa niż 0" << std::endl;
    }

    if(!s1){
        std::cout << "Model jest pustym stringiem i pojemność baku nie jest większa niż 0" << std::endl;
    }

    if(s1<s2){
        std::cout << "prawda" << std::endl;
    }

    std::vector <Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(),v.end());
    
    for(auto it=v.begin(); it!=v.end(); ++it){
        std::cout<<*it<<std::endl;
    }

    std::set <Samochod,cmp>s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);

    for(auto it=s.begin();it!=s.end();++it){
        std::cout << *it << std::endl;
    }

    std::cout << "Poziom " << s1.getPoziomPaliwa() << std::endl;
    std::cout << "Nazwa " << s2.getModel() << std::endl;
    std::cout << "Pojemnosc " << s3.getPojemnoscBaku() << std::endl;

    s1++;
    s2,"x5";
    s3|= 50;

    std::cout << "Poziom " << s1.getPoziomPaliwa() << std::endl;
    std::cout << "Nazwa " << s2.getModel() << std::endl;
    std::cout << "Pojemnosc " << s3.getPojemnoscBaku() << std::endl;

    return 0;
}