#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cstdlib>

inline void Eatline() { while(std::cin.get() != '\n') continue; }

int main(){
    using namespace std;
    ifstream bolek;
    ofstream lista;
    ifstream lolek;

    lista.open("lista.dat");

    bolek.open("bolek.txt");
    if(bolek.is_open()){
        cout << "Otworzenie pliku bolek, powiodlo sie.\n";
    }
    else{
        cerr << "Otworzenie pliku bolek, niepowiodlo sie.\n";
        exit(EXIT_FAILURE);
    }
    
    list<string> guests;
    string tmp;

    while(getline(bolek, tmp))
         guests.push_back(tmp);

    bolek.close();
    Eatline();

    lolek.open("lolek.txt");
    if(lolek.is_open()){
        cout << "Otworzenie pliku lolek, powiodlo sie.\n";
    }
    else{
        cerr << "Otworzenie pliku lolek, niepowiodlo sie.\n";
        exit(EXIT_FAILURE);
    }

    while(getline(lolek, tmp))
        guests.push_back(tmp);
    lolek.close();
    
    guests.sort();
    guests.unique();

    for(auto i : guests)
        lista << i << endl;
    lista.close();

    cout << "Koniec\n";
    return 0;
}
