// zapis i odczyt pliku binarnego
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>


inline void eatline() { while(std::cin.get() != '\n') continue; }

struct Planet{
    char name[20];
    double population;
    double g;
};

const char * file = "planety.dat";

int main()

{
    using namespace std;
    Planet p;
    cout << fixed << right;

                    

//pokaz poczatkowa zawartosc                
    ifstream fin;
                
    fin.open(file, ios_base::in | ios::binary);  //plik binarny
    if(fin.is_open()){
        cout << "Oto aktualna zawartosc pliku "        
            <<file << "file:\n";
        while(fin.read((char *) &p, sizeof p)){        
            cout << setw(20) << p.name <<": "    
                << setprecision(0) << setw(12) << p.population
                << setprecision(2) << setw(6) << p.g << endl;
        }        
        fin.close();
    }            
//dodaj nowe dane         
    ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);

    if(!fout.is_open()){
        cerr << "Nie mozna otworzyc pliku " << file << "do zapisu.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Podaj nazwe planety (aby zakonczyc, wprowadz pusty wiersz):\n";
    cin.get(p.name, 20);            
    while(p.name[0] != '\0'){
        cout << "Podaj zaludnienie planety: ";
        cin >> p.population;
        cout << "Podaj przyspieszenie grawitacyjne na planecie: ";
        cin >> p.g;                                         
        eatline();
        fout.write((char *) &p, sizeof p);        
        cout << "Podaj nazwe planety (aby zakonczyc, wprowadz pusty wiersz):\n";        
        cin.get(p.name, 20);        
    }            
    fout.close();
//wyswietl zmieniony plik
    fin.clear();   
    fin.open(file, ios_base::in | ios_base::binary);            
    if(fin.is_open()){
        cout << "Oto nowa zawartosc pliku "
            << file << ":\n";
        while(fin.read((char *) &p, sizeof p)){         
            cout << setw(20) << p.name << ": "
                << setprecision(0) << setw(12) << p.population
                << setprecision(2) << setw(6) << p.g <<endl;
        }        
        fin.close();        
    } 
    cout << "koniec\n";
    return 0;            
}
