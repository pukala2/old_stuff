#include <iostream>
#include <ctime>
#include <string>
#include <chrono>

std::string asString(const std::chrono::system_clock::time_point &tp){
    //konwerska na czas systemowy
    std::time_t t = std::chrono::system_clock::to_time_t(tp); //konwersja na czas kalendarzowy
    std::string ts = std::ctime(&t);                          //pomijanie znakow odstepow z konca
    ts.resize(ts.size()-1);
    return ts;
}

int main(){
    //wypisz epoke zegara systemowego
    std::chrono::system_clock::time_point tp;
    std::cout << "epoka:  " << asString(tp) << std::endl;

    //bierzacy czas zegara systemowego 
    tp = std::chrono::system_clock::now();
    std::cout << "teraz:  " << asString(tp) << std::endl;
}
