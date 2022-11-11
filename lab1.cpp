#include <iostream>

using namespace std;

class Hive {
    private:
        int numBees;        // liczba pszczół
        float coords[2];    // położenie ula [50.123, 33.123]
        float avgHoney;     // średni roczny wskaźnik
        string name;        // nazwa pasieki
        string color;       // kolor ula (własne pole)
        
    public:
        Hive(int n){    // ustawienie startowej ilości pszczół
            if (n<0) numBees = 0;
            else numBees = n;    
            coords[0] = 0;
            coords[1] = 0;
            avgHoney = 0;
            name = "";
            color = "";
        }

        void chgNumBees(int n){ // określenie wartości zmiany liczby pszczół
            if(n<=100 && n>=-100){
                int x = numBees+n;
                if(x > 0){
                    numBees = x;
                }else{
                    cout << "Liczba pszczół nie może być mniejsza od 0, teraz wynosi: " << numBees << endl;
                }
            }else{
                cout << "Zmiana może być tylko w zakresie <-100;100>" << endl;
            }
        }

        int getNumBees(){   // odczytanie aktualnej liczby pszczół
            return numBees;
        }

        void setCoords(float x, float y){ // określenie położenia ula
            if(-180 > x || x > 180){
                cout<< "X może być tylko z przedziału <-180°:180°>"<<endl;
            }else if(-90 > x || x > 90){
                cout<< "Y może być tylko z przedziału <-90°:90°>"<<endl;
            }else{
                coords[0] = x;
                coords[1] = y;
            }
        }

        float* getCoords(){ // odczytanie aktualnej pozycji ula
            return coords;
        }
    
        void setAvgHoney(int n){ // dodanie aktualnej rocznej ilości miodu
            avgHoney = n;
        }

        float getAvgHoney(){ // odczytanie aktualnej rocznej ilości miodu
            return avgHoney;
        }

        void setName(string str){ // określenie nazwy pasieki
            if (isupper(str.front()))
            name = str;
        }
        
        string getName(){ // odczytanie nazwy
            return name;
        }

        void setColor(string str){ // własna metoda nr 1
            color = str;
        }
        
        string getColor(){ // własna metoda nr 2
            return color;
        }
   
};

int main()
{
    int n;
    cout << "Podaj liczbę pszczół w twoim ulu" << endl;
    cout << "Wejście inne niż liczba dodatnia będzie interpretowana jako 0" << endl;
    cout.flush();
    cin >> n;
    Hive myHive(n);

    char choice = 0;
    char choice2 = 0;
    do{
        cout << endl;
        cout << "Wybierz operację:" << endl;
        cout << "1. Odczyt" << endl;
        cout << "2. Zapis" << endl;
        cout << "0. Zamknij" << endl;
        cout.flush();
        cin >> choice;
        switch (choice){
            case '1': {
                do{
                    cout << endl;
                    cout << "Wybierz pole:" << endl;
                    cout << "1. Liczba pszczół" << endl;
                    cout << "2. Położenie ula" << endl;
                    cout << "3. Średni roczny wskaźnik wypr. miodu" << endl;
                    cout << "4. Nazwa pasieki" << endl;
                    cout << "5. Kolor ula" << endl;
                    cout << "0. Powrót" << endl;
                    cout.flush();
                    cin >> choice2;
                    switch(choice2){
                        case '1': {
                            cout << "Aktualna liczba pszczół wynosi: " << myHive.getNumBees() << endl;
                            break;
                        }
                        case '2': {
                            float* coords;
                            coords = myHive.getCoords();
                            cout << "Aktualne położenie ula to: [" << coords[0] << "°, " << coords[1] << "°] " << endl;
                            break;
                        }
                        case '3': {
                            cout << "Aktualny średni roczny wskaźnik wypr. miodu wynosi: " << myHive.getAvgHoney() << endl;
                            break;
                        }
                        case '4': {
                            cout << "Aktualna nazwa pasieki to: " << myHive.getName() << endl;
                            break;
                        }
                        case '5': {                        
                            cout << "Aktualny kolor ula to: " << myHive.getColor() << endl;
                            break;
                        }
                        case '0': {
                            cout << "Wracam do poprzedniego menu" << endl;
                            break;
                        }
                        default: {
                            cout << "Nieobsługiwana wartość" << endl;
                            break;
                        }
                    }
                }while(choice2 != '0');
                break;
            }
            case '2': {
                do{
                    cout << endl;
                    cout << "Wybierz pole:" << endl;
                    cout << "1. Liczba pszczół" << endl;
                    cout << "2. Położenie ula" << endl;
                    cout << "3. Średni roczny wskaźnik wypr. miodu" << endl;
                    cout << "4. Nazwa pasieki" << endl;
                    cout << "5. Kolor ula" << endl;
                    cout << "0. Powrót" << endl;
                    cout.flush();
                    cin >> choice2;
                    switch(choice2){
                        case '1': {
                            int num;
                            cout << "Podaj o ile ma zmienić się liczba pszczół (w zakresie [-100; 100])" << endl;
                            cout.flush();
                            cin >> num;
                            myHive.chgNumBees(num);
                            break;
                        }
                        case '2': {
                            float x, y;
                            cout << "Podaj koordynat X ula" << endl;
                            cout.flush();
                            cin >> x;
                            cout << "Podaj koordynat Y ula" << endl;
                            cout.flush();
                            cin >> y;
                            myHive.setCoords(x, y);
                            break;
                        }
                        case '3': {
                            float num;
                            cout << "Podaj nowy średni roczny wskaźnik wypr. miodu" << endl;
                            cout.flush();
                            cin >> num;
                            myHive.setAvgHoney(num);
                            break;
                        }
                        case '4': {
                            string name;
                            cout << "Podaj nową nazwe pasieki (aby nastąpiła zmiana musi zaczynać się wielką literą)" << endl;
                            cout.flush();
                            cin >> name;
                            myHive.setName(name);
                            break;
                        }
                        case '5': {
                            string color;
                            cout << "Podaj nowy kolor ula" << endl;
                            cout.flush();
                            cin >> color;
                            myHive.setColor(color);
                            break;
                        }
                        case '0': {
                            cout << "Wracam do poprzedniego menu" << endl;
                            break;
                        }
                        default: {
                            cout << "Nieobsługiwana wartość" << endl;
                            break;
                        }
                    }
                }while(choice2 != '0');
                break;
            }
            case '0': {
                cout << "Wychodzę z programu" << endl;
                break;
            }
            default: {
                cout << "Nieobsługiwana wartość" << endl;
                break;
            }
        }
    }while(choice != '0');
    
}
