//dostep swobodny do pliku binarnego
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

const int LIM = 20;

inline void eatline() { while(std::cin.get() != '\n') continue; }

struct Planet{
        char name[LIM];
        double population;
        double g;
};

const char * file = "planety.dat"; //  Z ZALOZENIA ISTNIEJE 

int main(){
    using namespace std;
    Planet p;
    cout << fixed << right;
//pokaz poczatkowa zawartosc
    fstream finout;  //strumien do odczytu i zapisu           
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);  //plik binarny            
    int ct = 0;            
    if(finout.is_open()){            
        finout.seekg(0);  //przejdz na poczatek        
        cout << "Oto aktualna zawartosc pliku "        
            <<file << "file:\n";    
        while(finout.read((char *) &p, sizeof p)){        
            cout << ct++ << ": "<< setw(LIM) << p.name <<": "    
                << setprecision(0) << setw(12) << p.population
                << setprecision(2) << setw(6) << p.g << endl;
        }        
        if(finout.eof())        
            finout.clear();  //skasuj znacznik konca pliku    
        else{        
            cerr << "Blad przy probie odczytu pliku " << file << ".\n";    
            exit(EXIT_FAILURE);   
        }        
    }            
    else{
        cerr << "Nie mozna otworzyc pliku " << file << " -- koniec pracy programu.\n";        
        exit(EXIT_FAILURE);        
    }            
    //zmien rekod           
    cout << "Podaj numer rekordu, ktory chcesz zmienic:" ;
    long rec;            
    cin >> rec;            
    eatline();            
    if(rec < 0 || rec >= ct){            
        cout << "Nieprawidlowy numer rekordu -- koniec pracy programu.\n";        
        exit(EXIT_FAILURE);        
    }            
    streampos place = rec * sizeof p;  //konwertuj na typ streampos            
    finout.seekg(place);  //dostep swobodny            
    if(finout.fail()){
        cerr << "Blad podczas wyszukiwania pozycji\n";        
        exit(EXIT_FAILURE);        
    }            
    finout.read((char *) &p, sizeof p);            
    cout << "Twoj wybor :\n";            
    cout << rec << ": " << setw(LIM) << p.name << ": "            
        << setprecision(0) << setw(12) << p.population        
        << setprecision(2) << setw(6) << p.g << endl;       
    if(finout.eof())            
        finout.clear();  //skasuj znacznik konca pliku        
    cout << "Podaj nazwe planety: ";            
    cin.get(p.name, LIM);            
    cout << "Podaj zaludnienie planety: ";            
    cin >> p.population;            
    cout << "Podaj przyspieszenie grawitacji na planecie: ";            
    cin >> p.g;            
    finout.seekp(place);  //wroc            
    finout.write((char *) &p, sizeof p);            
    if(finout.fail()){            
        cerr << "Blad przy probie zapisu\n";        
        exit(EXIT_FAILURE);        
    }                        
    //wyswietl zmieniony plik        
    ct = 0;            
    finout.seekg(0);  //przejdz do poczatku pliku            
    cout << "Oto nowa zawartosc pliku " << file            
        << " :\n";        
    while(finout.read((char *) &p, sizeof p)){            
        cout << ct++ << ": " << setw(LIM) << p.name << ": "        
            << setprecision(0) << setw(12) << p.population    
            << setprecision(2) << setw(6) << p.g << endl;    
    }            
    finout.close();            
    cout << "Koniec\n";            
    return 0;            
}
