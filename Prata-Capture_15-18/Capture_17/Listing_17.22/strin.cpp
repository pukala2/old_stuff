//strin.cpp -- odczyt formatowany z obiektu typu string
#include <iostream>
#include <sstream>
#include <string>

int main(){
    using namespace std;
    string lit = "Dzien bym ciemny i burzowy, lecz ksiezyc w pelni swiecil zywym blaskiem.";

    istringstream instr(lit); //uzyj bufora do operacji wejscia

    string word;

    while(instr >> word) // odczytaj po jednym slowie naraz
        cout << word << endl;
    return 0;
}
