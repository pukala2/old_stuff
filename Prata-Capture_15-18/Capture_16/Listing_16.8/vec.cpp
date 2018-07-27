#include <iostream>
#include <vector>
#include <string>
#include "vec.h"

bool FillReview(Review & rr){
    std::cout<<"Wpisz tytul ksiazki (koniec, aby zakonczyc): ";
    std::getline(std::cin, rr.title);
    if(rr.title == "koniec")
        return false;
    std::cout<<"Wpisz ocene: ";
    std::cin>>rr.rating;
    if(!std::cin)
        return false;
    //pozbycie sie reszty danych wejsciowych
    while(std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr){
    std::cout<<rr.rating<<"\t"<<rr.title<<std::endl;
}

