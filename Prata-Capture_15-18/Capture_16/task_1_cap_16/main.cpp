#include <iostream>
#include <cctype>
#include <string>
#include "palindrom.h"

int main(){
    std::string word;
    std::cout<<"Podaj slowo <koniec> aby zakonczyc :";
    
    while(std::getline(std::cin,word) && word != "koniec"){
        if(Palindrom(word) == true)
            std::cout<<"Podane slowo jest palindromem\n";
        else
            std::cout<<"Podaj kolejne slowo <koniec> aby zakonczyc\n";
    }
}
